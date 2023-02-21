/*
https://www.geeksforgeeks.org/static-keyword-cpp/


TOPIC: Proof that static variables' lifetime (or "extent") is the entire run of the program.
    -> In the code we declare a class and then create an object from it inside the while loop. So the destructor should be called as soon as the while loop ends. But this does not happen because it is a static object and it is only destroyed when the main function ends.

    -> But if we make the object non-static then the destructor gets called as soon as the while loop ends.

*/
#include <iostream>
using namespace std;

class ABC
{
private:
    int i = 0;

public:
    ABC()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }
    ~ABC()
    {
        i = 0;
        cout << "Inside Destructor\n";
    }
};

int main()
{
    while (1)
    {
        static ABC temp;
        break;
    }
    cout << "End Of Main\n";
    return 0;
}
