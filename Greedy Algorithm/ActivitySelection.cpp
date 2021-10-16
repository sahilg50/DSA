// Activity selection With bubblesort is given below

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    int take = 1;
    int end = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] > end)
        {
            take++;

            end = v[i][1];
        }
    }

    cout << take << "activities" << endl;
    cout << end << "is the end time of last activity picked" << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void bubbleSort(vector<vector<int>> &v)
// {
//     int i, j;
//     for (i = v.size() - 1; i > 0; i--)
//     {
//         for (j = 0; j < i; j++)
//         {
//             if (v[j][1] > v[j + 1][1])
//                 swap(v[j][1], v[j + 1][1]);
//         }
//     }
// }

// int main()

// {
//     cout << "Enter the number of activites: " << endl;
//     int n;
//     cin >> n;
//     vector<vector<int>> v;
//     for (int i = 0; i < n; i++)
//     {
//         int start, end;
//         cin >> start >> end;
//         v.push_back({start, end});
//     }

//     bubbleSort(v);

//     int take = 1;
//     int end = v[0][1];
//     for (int i = 1; i < n; i++)
//     {
//         if (v[i][0] > end)
//         {
//             take++;

//             end = v[i][1];
//         }
//     }

//     cout << endl
//          << take << " activities" << endl;
//     cout << end << " is the end time of last activity picked" << endl;
//     return 0;
// }