#include <iostream>

using namespace std;

int main ()
{
  int x = 9;  
  do
  {
    ++x;
    cout << "x is " << x << endl;
  } while(x >= 10);
}