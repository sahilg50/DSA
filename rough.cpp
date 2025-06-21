#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> M;
    M[1] = 1;
    M[0] = 0;
    M[2] = 2;
    M[6] = 6;
    for (auto [key, value] : M)
        cout << key << " " << value << endl;
    return 0;
}
