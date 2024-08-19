#include <iostream>
using namespace std;

int main () 
{
    int play = 1;
    string input;
    while (play == 1)
    {
        play = 0;
        cout << "Welcome! Want to play? (Enter Yes or No)\n";
        cin >> input;
        if (input == "Yes" || input == "yes") {
            play = 1;
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}