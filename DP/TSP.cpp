// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// #define INT_MAX 999999
// int n = 4;

// //pow(2,n) = 16 and n =4
// int memo[16][4];

// //The matrix defines the graph
// int dist[10][10] = {
//     {0, 20, 42, 25},
//     {20, 0, 30, 34},
//     {42, 30, 0, 10},
//     {25, 34, 10, 0}};

// //If all the cites have been visited
// int VISITED_ALL = (1 << n) - 1;

// int tsp(int mask, int pos)
// {
//     int ans = INT_MAX;
//     if (mask == VISITED_ALL)
//         return dist[pos][0];

//     //look up
//     if (memo[mask][pos] != -1)
//         return memo[mask][pos];

//     //try to go to an unvisited city
//     for (int city = 0; city < n; city++)
//     {
//         if ((mask & (1 << city)) == 0)
//         {
//             int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
//             ans = min(ans, newAns);
//         }
//     }
//     memo[mask][pos] = ans;
//     return ans;
// }

// int main()
// {
//     for (int i = 0; i < pow(2, n); i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             memo[i][j] = -1;
//         }
//     }
//     cout << tsp(1, 0) << endl;
//     return 0;
// }

// SImplest approach without Memoization.
#include <iostream>
#include <algorithm>
using namespace std;

#define INT_MAX 999999
int n = 4;

//The matrix defines the graph
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

//If all the cites have been visited
int VISITED_ALL = (1 << n) - 1; //  this is equal to 2^n - 1

int tsp(int mask, int pos)
{
    int ans = INT_MAX;
    if (mask == VISITED_ALL)
        return dist[pos][0];

    //try to go to an unvisited city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main()
{
    cout << tsp(1, 0) << endl;
    return 0;
}