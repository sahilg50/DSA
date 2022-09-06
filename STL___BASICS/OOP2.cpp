// https://www.youtube.com/watch?v=b3GccK5_KSQ
// https://www.codin gninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799

#include <iostream>
#include <string>
using namespace std;

/*
ENCAPSULATION:
    -> Wrapping up of data members and functions.
    -> In other words, it is known as data hiding.
    -> Data Members: Properties or State
    -> Member Functions: Methods or Behaviour
    -> Fully Encapsulated: When all the data members are private.

INHERITANCE:
    -> Inheriting properties from parent or super class.

POLYMORPHISM:
    -> Compile Time:
    -> Run TIme:
*/

class Human
{
private:
    int height, weight, age;

public:
    void getAge()
    {
        cout << this->age;
    }
    void setWeight(int w)
    {
        this->weight = w;
    }
};

class Male : public Human
{
public:
    string color;
    void sleep()
    {
        cout << "Male Sleeping";
    }
};

int main()
{
    Male A;
    A.setWeight(10);
    A.getAge();
    return 0;
}