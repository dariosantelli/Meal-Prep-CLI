#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Recipe
{
public:
    string recipe_name {};
    string ingredients {};
    string descriptors {};

    void print()
    {
        cout << endl;
        cout << "Recipe: " << recipe_name << endl;
        cout << "Ingredients: " << ingredients << endl;
        cout << "Decriptions: " << descriptors << endl;
        cout << endl;
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

//need to implement read and append functions to text file, then search and modify functions for those entries
//reads all data from text file into separate objects and stores in memory
//format of data in text file: RecipeName, Ingredients, Descriptor /n

//Delimit target with ',' and modify output vector
void delimit(string const &str, vector<std::string> &out)
{
	stringstream ss(str);

	string s;
	while (getline(ss, s, ',')) {
		out.push_back(s);
	}
}

//Reads each line of file and creates a recipe object for each, adds these objects to results vector
void ReadFromFile(vector<Recipe> &results)
{
    Recipe obj [3] {};
    string line;
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

            results.push_back(working);
            //cout << obj << endl;
            /*
            cout << "Working Recipe Name: " << working.recipe_name << endl;
            cout << "Working Ingredients: " << working.ingredients << endl;
            cout << "Working Descriptors: " << working.descriptors << endl;
            */
        }

    }

}

//Add a new entry to the text file in the form "RecipeName,Ingredients,Descriptor"
void NewEntry()
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
}

int main()
{
    /*
    std::string s = "C,C++,Java";
    std::vector<std::string> out;
	delimit(s, out);

	string reffe = out[1];
	cout << reffe;

	for (int i = 0; i<3; i++)
            cout << out[i] << endl;
    */
    //OpenFile();
    vector<Recipe> results {};
    ReadFromFile(results);
    for(int i=0; i < results.size(); i++)
        cout << results.at(i).ingredients << ' ';
    //NewEntry();
    results.at(0).print();
    //Recipe test {};
    //test.ingredients = "fries";
    //cout << test.ingredients << endl;
    //test.print();

    /*
    int input {};
    cin >> input;
    if (input == 1)   {
        cout << "Input is: " << input << "(should be 1)" << endl;
    }   else if (input == 2)  {
            cout << "Input is: " << input << "(should be 2)" << endl;
    }   else if (input == 3)  {
            cout << "Input is: " << input << "(should be 3)" << endl;
    }   else if (input == 8)  {
            cout << "Input is: " << input << "(should be 8)" << endl;
    }   else if (input == 9)  {
            cout << "Input is: " << input << "(should be 9)" << endl;
    }   else {
        cout << "Invalid number entered, try again." << endl;
    }
    return 0;
    */
}

/*
GUI Layout:
Press a number on the keypad and press enter for more options:
1: View recipes
2: Add a recipe
3: Edit an existing recipe
8: Tutorial/Help
9: Exit program
*/
