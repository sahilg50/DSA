/*Find the union and intersection of two sorted arrays*/

#include <iostream>
using namespace std;

//function two find the Union of two arrays
void Union(int a[], int b[], int m, int n)
{

    int unionArray[100] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            unionArray[k++] = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            unionArray[k++] = b[j];
            j++;
        }
        else
        {
            unionArray[k++] = b[j];
            i++, j++;
        }
    }

    while (i < m)
        unionArray[k++] = a[i++];

    while (j < n)
        unionArray[k++] = b[j++];

    cout << "the union of array is: ";
    for (int i = 0; i < k; i++)
        cout << unionArray[i] << " ";

    cout << endl;
}

//Function to find the Intersection of two arrays
void Intersection(int a[], int b[], int m, int n)
{
    int i = 0;
    int j = 0;

    int intersectionArray[100] = {0};
    int k = 0;
    while (i < m && j < n)
    {
        if (a[i] == b[j])
        {
            intersectionArray[k++] = a[i];
            i++;
            j++;
        }

        else if (a[i] < b[j])
            i++;

        else
            j++;
    }

    cout << "The intersection of the two arrays is: ";
    for (int i = 0; i < k; i++)
        cout << intersectionArray[i] << " ";
    cout << endl;
}

//Driver program
int main()
{

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 20, 40};
    int arr2[] = {3, 4, 5, 6, 7, 8, 9, 13, 13, 13, 13, 13, 19};

    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);

    Union(arr1, arr2, m, n);
    Intersection(arr1, arr2, m, n);

    return 0;
}