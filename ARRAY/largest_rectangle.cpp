#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <random>
#include <algorithm>
#include <time.h>
using namespace std;

// Function to return the index of the left smaller element
vector<int> leftSmaller(int H[], int n)
{
    vector<int> LS(n, -1);
    stack<int> S;

    int i = 0;
    while (i < n)
    {
        if (S.empty())
        {
            S.push(i++);
        }
        else if (H[S.top()] < H[i])
        {
            LS[i] = S.top();
            S.push(i++);
        }
        else
        {
            S.pop();
        }
    }
    return LS;
}

// Function to return the index of the right smaller element
vector<int> rightSmaller(int H[], int n)
{
    vector<int> RS(n, n);
    stack<int> S;

    int i = 0;
    while (i < n)
    {
        if (S.empty())
        {
            S.push(i++);
        }
        else if (H[S.top()] > H[i])
        {
            RS[S.top()] = i;
            S.pop();
        }
        else
        {
            S.push(i++);
        }
    }
    return RS;
}

int main()
{

    srand(time(0));
    cout << "\nEnter the size of the array: ";
    int n;
    // cin >> n;
    int arr[] = {2, 1, 5, 6, 2, 3, 1};
    n = 7;
    // int *arr = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = rand() % 10;
    // }
    cout << "\nThe array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    vector<int> LS = leftSmaller(arr, n);
    cout << "\nLeft Smaller: ";
    for (int i : LS)
        cout << i << " ";

    vector<int> RS = rightSmaller(arr, n);
    cout << "\nRight Smaller: ";
    for (int i : RS)
        cout << i << " ";

    // Calculate the area of the largest Rectangle
    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, arr[i] * (RS[i] - LS[i] - 1));
    }
    cout << "\nThe area of the largest triangle is: " << maxArea;

    return 0;
}

/*
TC-> O(N)
SC-> O(N)
*/