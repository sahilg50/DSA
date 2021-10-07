#include <iostream>
using namespace std;

#define SIZE 7
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr1[], int arr2[], int arr3[], int low, int high)
{
    int pivot = arr1[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr1[j] > pivot)
        {
            i++;
            swap(arr1[j], arr1[i]); //
            swap(arr2[j], arr2[i]);
            swap(arr3[j], arr3[i]);
        }
    }
    swap(arr1[i + 1], arr1[high]);
    swap(arr2[i + 1], arr2[high]);
    swap(arr3[i + 1], arr3[high]);
    return (i + 1);
}

int quicksort(int arr1[], int arr2[], int arr3[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr1, arr2, arr3, low, high);
        quicksort(arr1, arr2, arr3, low, pi - 1);
        quicksort(arr1, arr2, arr3, pi + 1, high);
    }
}

int main()
{
    int job[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    int profit[SIZE] = {14, 90, 10, 15, 27, 22, 7};
    int deadline[SIZE] = {2, 1, 2, 1, 8, 6, 6};
    int totalprofit = 0;
    int order[10];
    int done[SIZE];
    //finding max deadline
    int max = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        if (max < deadline[i])
            max = deadline[i];
    }

    //making done
    for (int i = 0; i < SIZE; ++i)
    {
        done[i] = 0;
    }

    quicksort(profit, job, deadline, 0, SIZE - 1);
    cout << "After sorting the jobs in decreasing order of their profit\n";
    cout << "Job"
         << "       "
         << "Profit           "
         << "Deadline           " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << job[i] << "            " << profit[i] << "                " << deadline[i] << endl
             << endl;
    }

    //job sequencing
    int p = max - 1;

    while (p >= 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (deadline[i] >= p + 1 && done[i] == 0)
            {
                order[p] = job[i];
                totalprofit = totalprofit + profit[i];
                done[i] = 1;
                break;
            }
            order[p] = 0;
        }
        p = p - 1;
    }

    cout << "Final sequence of jobs chosen is -" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << order[i] << "   ";
    }
    cout << endl;
    cout << "Total profit=" << totalprofit << endl;
    cout << "Job"
         << "       "
         << "Profit           "
         << "Deadline              "
         << "Is the job selected?" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << job[i] << "          " << profit[i] << "               " << deadline[i] << "                      " << done[i] << endl;
    }
}
