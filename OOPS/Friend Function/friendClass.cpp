/*
TOPIC: Friend Class
A friend class can access private and protected members of other classes in which it is declared as a friend. It is sometimes useful to allow a particular class to access private and protected members of other classes. For example, a LinkedList class may be allowed to access private members of Node.

-> We can declare a friend class in C++ by using the friend keyword.

NOTE: We can declare friend class or function anywhere in the base class body whether its private, protected or public block. It works all the same.
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

    friend class Trainer;
};

class Trainer
{
public:
    void train(Client &C)
    {
        C.muscle += 2;
    }
};

int main()
{
    Client A(10);
    A.getPR();

    Trainer T;
    T.train(A);

    cout << "\n\nAfter Training:\n";
    A.getPR();

    return 0;
}