#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
int main()
{
    int A = 67;
    int denom[] = {5, 15, 12, 1};
    int quant[100];
    int n = sizeof(denom) / sizeof(int);

    quicksort(denom, 0, n - 1);

    cout << "After Sorting the denominations\n";
    for (int i = 0; i < n; ++i)
    {
        cout << denom[i] << endl;
    }
    cout << endl
         << endl;
    int C = A;
    cout << "C=" << C << endl;

    for (int i = 0; i < n; ++i)
    {

        if (C > 0 && C / denom[i] != 0)
        {
            quant[i] = C / denom[i];
            C = C % denom[i];
            continue;
        }
        quant[i] = 0;
    }
    cout << "Denomination    Quantity" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << denom[i] << "        " << quant[i] << endl;
    }

    return 0;
}