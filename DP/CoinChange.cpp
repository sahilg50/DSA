#include <iostream>
#include <vector>
using namespace std;

int count(int S[], int m, int val)
{
    int rows = m + 1;
    int columns = val + 1;
    vector<vector<int>> table;
    table.resize(rows);
    for (int i = 0; i < m + 1; i++)
        table[i].resize(columns);

    for (int i = 0; i < columns; i++)
    {
        table[0][i] = 0;
        table[0][1] = 1;
    }

    for (int i = 2; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            //Count of solutions including S[j]
            int x = (j - i >= 0) ? table[i][j - i] : 0;

            // Count of solutions excluding S[j]
            int y = table[i - 1][j];

            table[i][j] = x + y;
        }
    }
}
int main()
{

    int S[] = {1, 2, 5, 10};
    int m = sizeof(S) / sizeof(int);

    int val;
    cin >> val;

    cout << count(S, m, val);
    return 0;
}