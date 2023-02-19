/*
TOPIC: Global Function as Friend Function
    -> A class can have multiple friend functions
    -> We can declare a friend class in C++ by using the friend keyword.

    -> Arguments are passed by value, unless the function signature specifies otherwise:
        - in void foo(type arg), arg is passed by value regardless of whether type is a simple type, a pointer type or a class type,
        - in void foo(type& arg), arg is passed by reference.
*/

#include <iostream>
using namespace std;

class Client
{
private:
    int muscle;

public:
    Client(int muscle)
    {
        this->muscle = muscle;
    }
    void getPR()
    {
        cout << "\nMuscle Mass(KG): " << this->muscle;
        cout << "\nChest PR(KG): " << this->muscle * 2;
        cout << "\nShoulder PR(KG): " << this->muscle * 0.5;
    }

    friend void Cheer(Client &C);
};

void Cheer(Client &C)
{
    C.muscle += 1;
};

int main()
{
    Client A(10);
    A.getPR();

    Cheer(A);

    cout << "\n\nAfter Cheering:\n";
    A.getPR();

    return 0;
}