#include <iostream>
#include <algorithm>
using namespace std;

void max_heap(int arr[], int size, int i)
{
    //i is the parent
    int largest = i;
    int left = i * 2;        //left child
    int right = (i * 2) + 1; //right child

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heap(arr, size, largest);
    }
};

void min_heap(int arr[], int size, int i)
{
    int smallest = i;
    int left = i * 2;
    int right = (i * 2) + 1;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heap(arr, size, smallest);
    }
}

void build_maxheap(int arr[], int size)
{
    int startIdx = size / 2;

    for (int i = startIdx; i >= 1; i--)
        max_heap(arr, size, i);
}

void build_minheap(int arr[], int size)
{
    int startIdx = size / 2;

    for (int i = startIdx; i >= 1; i--)
        min_heap(arr, size, i);
}

void print_heap(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    int size = n + 1;
    int *arr = new int[size];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 1; i < size; i++)
    {
        int val;
        cin >> val;
        arr[i] = val;
    }

    print_heap(arr, size);
    cout << endl;
    build_maxheap(arr, size);

    print_heap(arr, size);
    cout << endl;

    build_minheap(arr, size);
    cout << endl;

    print_heap(arr, size);

    return 0;
}