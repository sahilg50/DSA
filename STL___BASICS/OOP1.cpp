// https : // www.youtube.com/watch?v=i_5pvt7ag7E&t=494s

#include <iostream>
using namespace std;

/*
Primitive Datatypes:
    -> int a;
    -> char ch;
    -> float f;

Class(Hero) is a user defined data type:
    -> Hero Jack;

Note:
    -> Size of the class depends upon the size of it's properties. (in bytes).
    -> Empty class has size of 1 byte to keep it's track.

    -> Properties can be accessed using '.' operator.

    -> Types of access modifiers:
        - Public
        - Private
        - Protected
    -> Default access modifier is private.
    -> Private data members and functions can be accessed only inside the class.
    -> Public data member and functions can be accessed both inside and outside the class.
    -> By default, data members hold the garbage value(i.e. in case we do not assign the value to them).
    -> In case we make the properties private, we can decalre public get() and set() methods to get and set values of private data members.
    -> Data members contain garbage value if no value is assigned to them.

    PADDING: Ii is the concept that adds one or more empty bytes between the memory addresses to align the data in memory such that CPU cycles should not be wasted. This is because processor doesn't read 1 byte at a time. The processor can access memory with a fixed word size of 4 bytes. Class with a single data member does not use padding.
    https://www.youtube.com/watch?v=aROgtACPjjg

    Data structure alignment is the way data is arranged and accessed in computer memory. Data alignment and Data structure padding are two different issues but are related to each other and together known as Data Structure alignment.
    Data alignment: Data alignment means putting the data in memory at an address equal to some multiple of the word size. This increases the performance of the system due to the way the CPU handles memory.
    Data Structure Padding: Now, to align the data, it may be necessary to insert some extra bytes between the end of the last data structure and the start of the next data structure as the data is placed in memory as multiples of fixed word size. This insertion of extra bytes of memory to align the data is called data structure padding.
    https://www.geeksforgeeks.org/data-structure-alignment-how-data-is-arranged-and-accessed-in-computer-memory/

    CONSTRUCTOR
    -> Whenever we create an object, a constructor is called by default. e.g. while creating object a, a.Hero() is called.
    -> Non parameterized constructor is the default constructor that is called by itself if not delcared.
    inside class.
    -> If we write any constructor inside class, then the default constructor are no longer valid. E.g. if we create a parameterized construtor, in that case the default non parameterized construtor gets deleted.
    -> this keyword is the pointer pointing to the current object.
    -> The copy constructor has to pass by reference otherwise if we pass by value then it will get caught in the infinite loop of creating and copying the constructor.
    -> When a copy constructor is not defined, the C++ compiler automatically supplies with its self-generated constructor that copies the values of the object to the new object.

    DESTRUCTOR
    -> Properties of Destructor:
        - Name is same as the class
        - No parameters
        - No return type
    -> For statically allocated objects, the destructor is called automatically.
    -> For dynamically allocated objects, the destructor has to be called manually. (e.g. in this case: 'B')
    -> Destructor is called only once

    SHALLOW COPY AND DEEP COPY
    Depending upon the resources like dynamic memory held by the object, either we need to perform Shallow Copy or Deep Copy in order to create a replica of the object. In general, if the variables of an object have been dynamically allocated, then it is required to do a Deep Copy in order to create a copy of the object.
    https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/

    STATIC KEYWORD:
    -> Data Member
        - Data member declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Firstly, static data member has to be assigned value using scope '::' operator and only then we can modify it using '.' operator by an object.
    -> Member Functions-
        - Member functions declared using static keyword belongs to the class and we do not need to create an object to access it.
        - Static member function can only access static data members.
        - Static member functions do no have 'this' keyword. This is because 'this' keyword belongs to the onject and not the class.

*/

class Hero
{

public:
    // properties
    char *name;
    int level;
    int health;
    static int timeToComplete;

    // Non-Parameterized constructor
    Hero()
    {
        cout << "Simple construtor is called " << endl;
    }
    // Parameterized constructor
    Hero(char name, int level, int health)
    {
        cout << "Construtor called.\n";
        this->name = new char[1];
        this->name[0] = name;
        this->level = level;
        this->health = health;
    }
    // Copy Constructor
    Hero(Hero &temp)
    {
        cout << "Copy constructor called" << endl;
        this->name = temp.name;
        this->level = temp.level;
        this->health = temp.health;
    }
    // Method to print all the properties
    void print()
    {
        cout << "[ Name: " << this->name[0] << ", ";
        cout << "Level: " << this->level << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Time To Complete: " << timeToComplete << " ]";
    }

    // Static member function
    static int gotHit()
    {
        timeToComplete /= 2;
    }
    ~Hero()
    {
        cout << "Destructor called for: " << this->name[0] << endl;
    }
};
int Hero::timeToComplete = 100;

int main()
{
    // Statically allocated
    Hero A('A', 1, 20);
    cout << "Size of the class Hero: " << sizeof(A) << endl;
    A.print();
    cout << "\n\n";

    // Dynamically allocated
    Hero *B = new Hero('B', 2, 40);
    // (*B).print();
    B->print();
    cout << endl;
    delete B;
    cout << "\n\n";

    // Create C as a shallow copy of A
    Hero C(A);
    C.print();
    cout << "\n\n";

    // When copying the data of object at the time of initialization then copy is made through COPY CONSTRUCTOR
    Hero D = A;
    D.timeToComplete = 300;
    D.print();
    cout << "\n\n";

    // When copying the data of object after initialization then the copy is done through DEFAULT ASSIGNMENT OPERATOR
    Hero E;
    E = A;
    E.gotHit();
    E.print();
    cout << "\n\n";
    // In all the above examples, a shallow copy is being created since some of the data members have been dynammically allocated.
    return 0;
}