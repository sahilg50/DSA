#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1, 1, 1, 1, 10};
    v.resize(7, 0);
    cout << v.size() << " " << v.capacity();
    return 0;
}