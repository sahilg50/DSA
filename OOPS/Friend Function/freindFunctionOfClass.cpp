// TOPIC: Member Function of Another Class as Friend Function

#include <iostream>
using namespace std;

// Forward definition needed in which friend function is gonna be defined.
class Client;
class Trainer
{
public:
    void train(Client &C);
};

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

    friend void Trainer::train(Client &C);
};

void Trainer::train(Client &C)
{
    C.muscle += 2;
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