#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &number)
{
    int N = number.size() / 2;
    int count = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int left1 = number[2 * i];
        int right1 = number[2 * i + 1];
        int left2 = number[2 * (i + 1)];
        int right2 = number[2 * (i + 1) + 1];

        if (right1 != left2)
        {
            count++;

            if (left1 + right1 < left2 + right2)
            {
                number[2 * (i + 1)] = left1;
                number[2 * (i + 1) + 1] = right1;
            }
            else
            {
                number[2 * i] = left2;
                number[2 * i + 1] = right2;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> dominoes = {2, 4, 1, 3, 4, 6, 2, 4, 1, 6};
    int result = solution(dominoes);
    cout << "Minimum number of tiles to remove: " << result << endl;
    return 0;
}