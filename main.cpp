#include <iostream>
#include <fstream>

using namespace std;

class Recipe
{
public:
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

void ReadFromFile(int line_number)
{
    //read specific line
}

#Add a new entry to the text file in the form "RecipeName,Ingredients,Descriptor"
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
    OpenFile();
    NewEntry();
    cout << "Hello world!" << endl;
    Recipe test {};
    test.ingredients = "fries";
    cout << test.ingredients << endl;
    test.print();
    cout << test.ingred[0];
    return 0;
}
