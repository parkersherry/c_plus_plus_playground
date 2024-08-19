#include <iostream>
using namespace std;

string my_string;

int main () 
{
    cout << "Please enter some text.\n";
    cin >> my_string;
    if (my_string == "Y")
    {
        cout << "Yes!";
    }
    else if (my_string == "N")
    {
        cout << "No!";
    }
    else {cout << "Maybe.";}
    return 0;
}

// Conclusion: this method works as a way of identifying user input.