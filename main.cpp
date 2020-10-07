#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Recipe
{
public:
    std::string recipe_name {};
    std::vector<std::string> ingredients {};
    std::vector<std::string> directions {};
    std::vector<std::string> keywords {};
    int line_number {};

    void multi_line_print()
    {

        std::cout << std::endl;
        std::cout << "Recipe Name: " << recipe_name << std::endl;
        std::cout << std::endl;

        std::cout << "Ingredients:" << std::endl;
        for (int i = 0; i < ingredients.size(); i++)    {
            std::cout << " - " << ingredients[i] << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Directions: " << std::endl;
        for (int i = 0; i < directions.size(); i++) {
            std::cout << i + 1 << ". " << directions[i] << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Keywords: " << std::endl;
        for (int i = 0; i < keywords.size(); i++)   {
            std::cout << " - " << keywords[i] << std::endl;
        }

        std::cout << std::endl;
    }

    /*
    void single_line_print()
    {
        cout << "Recipe: " << recipe_name <<
        cout << "Recipe: " << recipe_name << "; Ingredients: " << ingredients << "; Descriptions: " << descriptors << endl;
    }
    */

};


void OpenFile()
{
    ifstream myfile;
    string line;
    myfile.open ("mealprepdata.txt", ios::out | ios::app);
    getline(myfile, line);
    cout << line << endl;
}

//takes string of the input style, outputs recipe name into variable, modifies out vector to be a vector of vectors containing strings
void InputDataProcessor(std::string &line, std::string &recipe_name, std::vector<std::vector<std::string>> &out)
{
    //takes input in the form of "recipename,{ingredient1;ingredient2;ingredient3},{direction1;direction2;direction3},{keyword1;keyword2}"
    //outputs the recipe name to the recipe_name variable
    //creates an individual vector of strings for ingredients, directions, and keywords, then stores those three vectors of strings in the out vector

    std::vector<std::string> temporary {};
	std::stringstream ss(line); //input line
	std::string s; //output string

	//delimit input string by commas and store vectored variables in temporary vector
	while (getline(ss, s, ',')) {
        if (s[0] == '{' and s.back() == '}')   {

            //removes bracket chars
            s.erase(s.end()-1);
            s.erase(s.begin());

            temporary.push_back(s);
            continue;
        }
        recipe_name = s;
	}


	//delimit ingredients from temporary vector into individual ingredients vector
	std::vector<std::string> ingredients {};

	std::stringstream ingredients_input(temporary[0]);
    while (getline(ingredients_input, s, ';'))    {
        ingredients.push_back(s);
    }

    //delimit directions from temporary vector into individual directions vector
    std::vector<std::string> directions {};

    std::stringstream directions_input(temporary[1]);
    while (getline(directions_input, s, ';'))    {
        directions.push_back(s);
    }

    //delimit keywords from temporary vector into individual keywords vector
	std::vector<std::string> keywords {};

    std::stringstream keywords_input(temporary[2]);
    while (getline(keywords_input, s, ';'))    {
        keywords.push_back(s);
    }

    //add the three sub-vectors of strings to the main output vector
	out.push_back(ingredients);
	out.push_back(directions);
	out.push_back(keywords);

}

Recipe BuildRecipeObject(std::string line, std::vector<std::vector<std::string>> &output, int line_number)
{
    Recipe current {};
    std::string recipe_name {};

    InputDataProcessor(line, recipe_name, output);

    current.recipe_name = recipe_name;
    current.ingredients = output[0];
    current.directions = output[1];
    current.keywords = output[2];
    current.line_number = line_number;

    return current;

}



//Reads each line of file and creates a recipe object for each, adds these objects to results vector
void ReadFromFile(vector<Recipe> &results)
{

    string line;
    int line_number = 1;
    ifstream myfile ("mealprepdata.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::vector<std::vector<std::string>> output;
            Recipe current  = BuildRecipeObject(line, output, line_number);

            line_number ++;

            results.push_back(current);

        }

    }

}



//Take user input for each of the paramaters, formats it properly, adds it to the text file and the results vector
void NewEntry(vector<Recipe> &results)
{
    string entry {};
    string temp {};
    string tempoR {};
    cout << "Enter a recipe name: ";
    getline(cin >> ws, temp);
    entry.append(temp + ",{");
    temp = {};

    cout << "Enter recipe ingredients (ex: ingredient1;ingredient2;ingredient3): ";
    getline(cin >> ws, temp);
    entry.append(temp + "},{");
    temp = {};

    cout << "Enter recipe directions (ex: direction1;direction2;direction3): ";
    getline(cin >> ws, temp);
    entry.append(temp + "},{");
    temp = {};

    cout << "Enter recipe keywords (ex: keyword1;keyword2;keyword3): ";
    getline(cin >> ws, temp);
    entry.append(temp + "}");
    temp = {};

    //add string to text file
    ofstream myfile;
    myfile.open ("mealprepdata.txt", ios::out | ios::app);
    myfile << entry << endl;

    cout << "Recipe entered: " << entry << endl;

    //add recipe directly to results vector instead of re-reading file
    int last_line_number {results.size()};
    std::vector<std::vector<std::string>> output;
    Recipe current = BuildRecipeObject(entry, output, last_line_number + 1);

    results.push_back(current);
}

/*
void WriteResultsToFile(vector<Recipe> &results)
{
    ofstream myfile ("mealprepdata.txt");
    if (myfile.is_open())   {
        for (int i = 0; i < results.size(); i++)  {
            myfile << results[i].recipe_name << "," << results[i].ingredients << "," << results[i].descriptors << endl;
        }
    }
}

void EditRecipe(vector<Recipe> &results)
{
    //ask user what recipe they'd like to edit and to enter line number of that recipe
    //change specific recipe in results vector (ask for each input one by one)
    //overwrite entire txt file with new results vector
    cout << endl << "Type the number of the recipe you'd like to edit, then press ENTER" << endl << endl;

    for(int i=0; i < results.size(); i++) {
                cout << i+1 << ": ";
                results.at(i).single_line_print();
    }

    int entered_line_number {};
    cin >> entered_line_number;
    cout << endl << "You entered: " << entered_line_number << endl;

    string temp {};
    cout << endl << "Current recipe name is: " << results[entered_line_number-1].recipe_name << endl;
    cout << "Enter a new recipe name: ";
    cin >> temp;
    results[entered_line_number-1].recipe_name = temp;
    temp = {};

    cout << endl << "Current ingredients are: " << results[entered_line_number-1].ingredients << endl;
    cout << "Enter new ingredients: ";
    cin >> temp;
    results[entered_line_number-1].ingredients = temp;
    temp = {};

    cout << endl << "Current descriptors are: " << results[entered_line_number-1].descriptors << endl;
    cout << "Enter new descriptors: ";
    cin >> temp;
    results[entered_line_number-1].descriptors = temp;
    temp = {};

    cout << endl << "Recipe " << entered_line_number << " changed to: ";
    results[entered_line_number-1].single_line_print();

    WriteResultsToFile(results);

}
*/

void PrintUserPrompt()
{
    cout << endl << "Press a number on the keypad and press enter" << endl;
    cout << "1: View Recipes" << endl;
    cout << "2: Add a Recipe" << endl;
    cout << "3: Edit an Existing Recipe" << endl;
    cout << "8: Tutorial/Help" << endl;
    cout << "9: Exit Program" << endl << endl;
}

void PrintTutorial()
{
    //print here
    cout << endl << endl << "Tutorial/Help" << endl << endl;
    cout << "This program reads from an associated text file" << endl;
    cout << "1 - View Recipes: View all recipes available in the storage file" << endl;
    cout << "2 - Add a Recipe: Follow the prompts to add a recipe to the storage file" << endl;
    cout << "3 - Edit an Existing Recipe: F" << endl;
    cout << "8 - Tutorial: This" << endl;
    cout << "9 - Exit Program: Exit" << endl;
}

int main()
{
    //Read text file and populate results vector with recipe objects
    vector<Recipe> results {};
    ReadFromFile(results);

    while (true)  {

        PrintUserPrompt();

        int input {};
        cin >> input;

        if (input == 1)   {
            cout << endl;


            for(int i=0; i < results.size(); i++) {
                cout << i+1 << ": ";
                results.at(i).multi_line_print();
            }

            continue;

        }   else if (input == 2)  {
                NewEntry(results);
                continue;

        }   else if (input == 3)  {
                //EditRecipe(results);
                continue;

        }   else if (input == 8)  {
                PrintTutorial();
                continue;

        }   else if (input == 9)  {
                break;

        }   else {
                cout << endl << "Invalid number entered, try again." << endl;
                continue;
        }
        return 0;
    }

}

    //For quick reference:

    //need to implement read and append functions to text file, then search and modify functions for those entries
    //reads all data from text file into separate objects and stores in memory
    //format of data in text file: RecipeName, Ingredients, Descriptor /n

    /*
    Structure of output
    1. Recipe Name:
    2. Comprehensive list of ingredients
    3. Directions
    4. Keywords

    storage structure in recipe object: [recipename,[vector_of_ingredients],[vector_of_directions],[vector_of_keywords]]

    current storage in txt file: recipename,ingredient1,ingredient2,ingredient3,direction1,direction2,direction3,keyword1,keyword2
    updated: recipename,{ingredient1,ingredient2,ingredient3},{direction1,direction2,direction3},{keyword1,keyword2}

    need to remove std namespace and replace all calls with std::

    */
