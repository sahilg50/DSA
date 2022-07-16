#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MAX HEAP
class maxHeap
{
private:
    vector<int> arr = {0}; // array taes values only through insert function. It is the main array

public:
    // Method to insert values in the heap
    void insert(int val)
    {
        // The indexing of the heap is from 1. do not consider the value stored at index index 0;
        arr.push_back(val);
        int index = arr.size() - 1;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
            }
            else
                return;

            index = index / 2;
        }

        // TC-> O(logN)
    }

    // Method to print the max heap
    void print()
    {
        cout << endl
             << "The max heap is: ";
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        // TC->O(N)
    }

    // Method to delete any node of user choice from the heap
    void del(int val)
    {
        // If the Heap is empty
        if (arr.size() == 1)
        {
            cout << endl
                 << "Nothing to delete, the maxheap is empty!";
            return;
        }

        // step 1 -> Check if the element to be deleted exists in heap or not
        int index = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == val)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << endl
                 << "The element not found!";
            return;
        }

        // Step 2 -> swap the node and the last node
        swap(arr[index], arr[arr.size() - 1]);

        // Step 3 -> Remove the last node
        arr.pop_back();

        // step 4 -> Take the root node to it's correct position (Heapify iteratively)
        int i = index;
        int size = arr.size();
        while (i < size)
        {
            int L = 2 * i;
            int R = 2 * i + 1;
            // check if its a leaf node
            if (L >= size && R >= size)
                return;

            int Lval = -1, Rval = -1;
            if (L < size)
                Lval = arr[L];
            if (R < size)
                Rval = arr[R];

            // if node is less than any of the children then replace it with the greater child.
            if (arr[i] < Lval || arr[i] < Rval)
            {
                if (Lval > Rval)
                {
                    swap(arr[i], arr[L]);
                    i = L;
                }
                else
                {
                    swap(arr[i], arr[R]);
                    i = R;
                }
            }
            else
                return;
        }
        return;

        // Tc-> O(log N)
        // SC-> O(log N)
    }
};

// Recursive method to build heap, can also use the iterative method given in the void del method
void heapify(vector<int> &arr, int i)
{
    int largest = i;
    int L = 2 * i;
    int R = 2 * i + 1;
    int n = arr.size();

    if (L < n && arr[L] > arr[largest])
        largest = L;
    if (R < n && arr[R] > arr[largest])
        largest = R;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest);
    }
}
void buildHeap(vector<int> &arr)
{
    int N = arr.size() - 1;   // N is the number of nodes in the heap
    int startInd = N / 2 + 1; // startInd is the starting index of the non leaf nodes
    for (int i = startInd; i >= 0; i--)
    {
        heapify(arr, i);
    }
};

int main()
{
    maxHeap h;
    vector<int> nodes = {10, 2, 5, 6, 7, 20, 100};
    for (auto &i : nodes)
    {
        h.insert(i);
        h.print();
    }

    cout << endl
         << "Enter the node to be deleted: ";
    int target;
    cin >> target;
    h.del(target);
    h.print();

    // Second section of the code shows the use of heapify function
    nodes = {10, 2, 5, 6, 7, 20, 100};
    buildHeap(nodes);
    cout << endl
         << "Array after heapifing: ";
    for (auto i : nodes)
        cout << i << " ";

    return 0;
}