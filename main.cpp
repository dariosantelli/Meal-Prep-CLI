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
    int ingred[3] {4, 5, 6};

    void print()
    {
        cout << "Ingredients:" << endl;
        for (int i = 0; i<5; i++)
            cout << i << endl;
    }
};

void OpenFile()
{
    ifstream myfile;
    string line;
    myfile.open ("example.txt", ios::out | ios::app);
    getline(myfile, line);
    cout << line << endl;
    //myfile << "I wrote this f\n";
    //ofstream get
}

//need to implement read and append functions to text file, then search and modify functions for those entries
//reads all data from text file into separate objects and stores in memory
//can create new recipe and add to text file
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

//Read each line from the text file, create a recipe object from each line
void ReadFromFile()
{
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::vector<std::string> out;
            delimit(line, out);
            cout << line << '\n';
            for (int i = 0; i<3; i++)
                cout << out[i] << endl;
        }
        myfile.close();
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
    ReadFromFile();
    //NewEntry();
    //Recipe test {};
    //test.ingredients = "fries";
    //cout << test.ingredients << endl;
    //test.print();
    //cout << test.ingred[0];
    //string test [2] {delimit("dog")};
    //test = delimit("dog");
    //cout << delimit("dog");
    return 0;
}
