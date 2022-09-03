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

// https://www.geeksforgeeks.org/static-keyword-cpp/