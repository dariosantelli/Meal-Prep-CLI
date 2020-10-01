#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

class Recipe
{
public:
    string recipe_name {};
    string ingredients {};
    string descriptors {};
    int line_number {};

    void multi_line_print()
    {
        cout << endl;
        cout << "Recipe: " << recipe_name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Decriptions: " << descriptors << endl;
        cout << endl;
    }

    void single_line_print()
    {
        cout << "Recipe: " << recipe_name << "; Ingredients: " << ingredients << "; Descriptions: " << descriptors << endl;
    }

};

void OpenFile()
{
    ifstream myfile;
    string line;
    myfile.open ("example.txt", ios::out | ios::app);
    getline(myfile, line);
    cout << line << endl;
}

//Delimit target with ',' and modify output vector
void delimit(string const &str, vector<std::string> &out)
{
	stringstream ss(str);

	string s;
	while (getline(ss, s, ',')) {
		out.push_back(s);
	}
}

void AddEntryToResults()
{
    //basically take ReadFromFile functionality
}

//Reads each line of file and creates a recipe object for each, adds these objects to results vector
void ReadFromFile(vector<Recipe> &results)
{
    string line;
    int line_number = 1;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            Recipe working {};
            std::vector<std::string> out;
            delimit(line, out);
            working.recipe_name = out[0];
            working.ingredients = out[1];
            working.descriptors = out[2];
            working.line_number = line_number;

            line_number ++;

            results.push_back(working);

        }

    }

}

//Add a new entry to the text file in the form "RecipeName,Ingredients,Descriptor"
void NewEntry(vector<Recipe> &results)
{
    string entry {};
    string temp {};
    cout << "Enter a recipe name: ";
    cin >> temp;
    entry.append(temp + ",");
    temp = {};

    cout << "Enter recipe ingredients: ";
    cin >> temp;
    entry.append(temp + ",");
    temp = {};

    cout << "Enter a descriptor: ";
    cin >> temp;
    entry.append(temp);
    temp = {};

    ofstream myfile;
    myfile.open ("example.txt", ios::out | ios::app);
    myfile << entry << endl;


    cout << "Recipe entered: " << entry << endl;

    int last_line_number {results.size()};
    Recipe working {};
    std::vector<std::string> out;
    delimit(entry, out);
    working.recipe_name = out[0];
    working.ingredients = out[1];
    working.descriptors = out[2];
    working.line_number = last_line_number + 1;

    results.push_back(working);
}

void EditRecipe(vector<Recipe> &results)
{
    //null
    //display recipes in single line format
    //ask user what recipe they'd like to edit and to enter line number of that recipe
    //change specific line that the recipe is on in txt
    //re-run readfromfile
    cout << "Type the number of the recipe you'd like to edit, then press ENTER" << endl << endl;

    for(int i=0; i < results.size(); i++) {
                cout << i+1 << ": ";
                results.at(i).single_line_print();
    }

    int temp {};
    cin >> temp;
    cout << "You entered: " << temp << endl;
    cout << results[temp-1].recipe_name << endl;

}

void WaitForEnterKey()
{
    /* Wait for user to press enter key
    int c;
    printf( "Press ENTER to continue... " );
    fflush( stdout );
    do c = getchar(); while ((c != '\n') && (c != EOF));

    do  {
        cout << '\n' << "Press ENTER to continue...";
    }
    while (cin.get() != '\n');

    cin.ignore();
    */
}

int main()
{
    //Read text file and populate results vector with recipe objects
    vector<Recipe> results {};
    ReadFromFile(results);

    int n = results.size();
    cout << n;

    while (true)  {

        cout << endl << "Press a number on the keypad and press enter" << endl;
        cout << "1: View recipes" << endl;
        cout << "2: Add a recipe" << endl;
        cout << "3: Edit an existing recipe" << endl;
        cout << "8: Tutorial/Help" << endl;
        cout << "9: Exit program" << endl << endl;

        int input {};
        cin >> input;
        if (input == 1)   {
            cout << endl;

            for(int i=0; i < results.size(); i++) {
                cout << i+1 << ": ";
                results.at(i).single_line_print();
            }

            /*
            int temp1 {&results};
            cout << *temp1;
            */

            //WaitForEnterKey();

            continue;

        }   else if (input == 2)  {
                NewEntry(results);
                continue;

        }   else if (input == 3)  {
                EditRecipe(results);
                continue;

        }   else if (input == 8)  {
                cout << "Input is: " << input << "(should be 8)" << endl;

        }   else if (input == 9)  {
                break;

        }   else {
                cout << endl << "Invalid number entered, try again." << endl;
                continue;
        }
        return 0;
    }
}



/* For quick reference:
    std::string s = "C,C++,Java";
    std::vector<std::string> out;
	delimit(s, out);

	string reffe = out[1];
	cout << reffe;

	for (int i = 0; i<3; i++)
            cout << out[i] << endl;
    */
    //OpenFile();

    //NewEntry();
    //results.at(0).multi_line_print();
    //Recipe test {};
    //test.ingredients = "fries";
    //cout << test.ingredients << endl;
    //test.print();

    //need to implement read and append functions to text file, then search and modify functions for those entries
    //reads all data from text file into separate objects and stores in memory
    //format of data in text file: RecipeName, Ingredients, Descriptor /n

    //cout << results[i].line_number;
    //cout << results[i].recipe_name;
