#include <iostream>

// Program which stores and prints the speed and acceleration of objects in freefall over 10 seconds


class Object                                        // make object
{
    public:
    double velocity;
    Object (double a)                               // constructor which initializes instances of Object class with an initial velocity
    {
        velocity = a;
    }
};

double speeds [10];                                 // array for storing velocity, and variable for initial speed
double v_0;

void iterSpeed (double v) {                         // function to call in main (void type since it does not return a value)
    Object * pObj = &Object(v);
    for (int t = 0; t < 10; t++) {
        double v_t = pObj -> velocity + 9.8*t;
        speeds[t] = v_t;
        std::cout << v_t << "\n";
    }
}

int main () 
{
std::cout << "Please enter an initial velocity\n";
std::cin >> v_0;
iterSpeed(v_0);                                     // calls function with initial velocity v_0
return 0;
}