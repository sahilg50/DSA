#include <iostream>
#include <limits>
using namespace std;

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optCost(int freq[], int i, int j)
{

    //base case
    if (j < i) // no elements in the subarray
        return 0;

    if (j == i) // only element in the subarray
        freq[i];

    // STL function to calculate the sum of the array from i to j element.
    int fsum = sum(freq, i, j);

    //Initialize the minimum value
    int min = INT32_MAX;

    for (int r = i; r <= j; r++)
    {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);

        if (cost < min)
            min = cost;
    }
    return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    //Make sure to sort the keys[] because that is the base for a binary search tree
    return optCost(freq, 0, n - 1);
}

int main()
{

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};

    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);

    return 0;
}