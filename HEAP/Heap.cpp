#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// MAX HEAP
class maxHeap
{
private:
    // Follows 1 based indexing
    vector<int> arr = {0}; // Takes values through insert method only
    // Recursively heapify a non leaf element
    void heapify(int i, int N)
    {
        // N is the range upto which arr elements are accessible
        int largest = i;   // Index that is to be adjusted
        int L = 2 * i;     // Left child
        int R = 2 * i + 1; // Right child

        if (L <= N && arr[L] > arr[largest])
            largest = L;
        if (R <= N && arr[R] > arr[largest])
            largest = R;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(largest, N);
        }
    }

public:
    // Insert values in the heap
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
        // Sc-> O(1)
    }

    // Print the max heap
    void print()
    {
        cout << endl
             << "The max heap is: ";
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        // TC->O(N)
        // SC->O(1)
    }

    // Delete any node of user choice
    void del()
    {
        // If the Heap is empty
        int N = arr.size() - 1;
        if (N == 0)
        {
            cout << endl
                 << "Nothing to delete, the maxheap is empty!";
            return;
        }

        cout << "\nEnter the node to be deleted: ";
        int val;
        cin >> val;

        // step 1 -> Check if the element to be deleted exists in heap or not
        int index = -1;
        for (int i = 0; i <= N; i++)
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
        swap(arr[index], arr[N]);

        // Step 3 -> Remove the last node
        arr.pop_back();
        N = N - 1; // Number of nodes decreases by 1

        // step 4 -> Heapify all the nodes from the current node to root node
        for (int i = index; i >= 1; i--)
        {
            heapify(i, N);
        }
        return;
        // TC-> Searching the element: O(N) + Heapify: O(NlogN), but according to books it is O(logN)
        // SC-> O(log N)
    }

    // Sort the heap
    void heapSort()
    {
        int N = arr.size() - 1;
        while (N > 1)
        {
            // step1 -> swap
            swap(arr[1], arr[N]);
            N--;

            heapify(1, N);
        }
        // TC->O(NlogN), since we heapify N elements
    };

    // Build the heap from non leaf nodes
    void buildHeap()
    {
        int N = arr.size() - 1; // N is the number of nodes in the heap
        int startInd = N / 2;   // startInd is the starting index of the non leaf nodes
        for (int i = startInd; i >= 1; i--)
        {
            heapify(i, N);
        }
        // TC-> O(NlogN)
    };
};

int main()
{
    vector<int> nodes = {10, 2, 5, 6, 7, 20, 100};
    maxHeap h;
    for (auto &i : nodes)
        h.insert(i), h.print();

    h.del();
    cout << "\nAfter deleting: ", h.print();

    h.heapSort();
    cout << "\nAfter heap sort: ", h.print();

    cout << "\nNote: After heapsort the array is no longer a heap therefore we've to build the heap again using buildHeap(): ";

    h.buildHeap();
    cout << "\nAfter building the heap: ", h.print();

    return 0;
}