#include <iostream>
using namespace std;

class Hero
{
private:
    char name;

public:
    Hero(char ch) { this->name = ch; }

    Hero &set()
    {
        cout << "\nSet method called!";
        // Return the object which called this method as reference.
        return *this;
    }

    void get() { cout << endl
                      << this->name; }
};

int main()
{

    Hero A('a');
    Hero B('b');
    A = B.set();
    A.get();

    cout << '9' - '0';
    return 0;
}