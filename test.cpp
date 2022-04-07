#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> getOneBits(int n)
{
    vector<int> bits;

    for (int i = 0; n > 0; i++)
    {
        bits.push_back(n % 2);
        n = n / 2;
    }

    reverse(bits.begin(), bits.end());

    vector<int> result;
    int count = 0;
    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] == 1)
        {
            count++;
            result.push_back(i + 1);
        }
    }
    result.insert(result.begin(), count);

    return result;
}

int main()
{
    getOneBits(161);
    return 0;
}