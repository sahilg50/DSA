#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {2, 4, 1, 3, 4, 6, 2, 4, 1, 6};
    for (const int &number : numbers)
        cout << number << " "
             << "Akul"
             << endl;

    return 0;
}