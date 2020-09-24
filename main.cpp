#include <iostream>

using namespace std;

class Recipe
{
public:
    string ingredients {};
    string descriptors {};

    void print()
    {
        cout << "Ingredients:" << endl;
        for (int i = 0; i<5; i++)
            cout << i << endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Recipe test {};
    test.ingredients = "fries";
    cout << test.ingredients << endl;
    test.print();
    return 0;
}
