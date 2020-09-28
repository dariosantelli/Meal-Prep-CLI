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

    while (true)  {

        cout << "Press a number on the keypad and press enter for more options" << endl;
        cout << "1: View recipes" << endl;
        cout << "2: Add a recipe" << endl;
        cout << "3: Edit an existing recipe" << endl;
        cout << "8: Tutorial/Help" << endl;
        cout << "9: Exit program" << endl;

        int input {};
        cin >> input;
        if (input == 1)   {

            for(int i=0; i < results.size(); i++)
                results.at(i).single_line_print();
                //WaitForEnterKey();

                continue;

        }   else if (input == 2)  {
                NewEntry();
                continue;

        }   else if (input == 3)  {
                cout << "Input is: " << input << "(should be 3)" << endl;

        }   else if (input == 8)  {
                cout << "Input is: " << input << "(should be 8)" << endl;

        }   else if (input == 9)  {
                break;

        }   else {
                cout << "Invalid number entered, try again." << endl;
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
