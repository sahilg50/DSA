#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4};
    cout << "\nFind in vector v is: " << *find(v.begin(), v.end(), 2);
    return 0;
}
