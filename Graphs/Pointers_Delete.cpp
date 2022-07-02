#include <iostream>
using namespace std;

int main()
{
     /*
     -> Unlike Java, C++ doesn't provide support for Garbage Collector(implicitely) for cleaning of unreachable objects.

     -> Negligence could lead to a memory leak, which is nothing but a bunch of unreachable objects stacked up in memory.

     -> To deal with this situation we use delete or delete[]

     -> C++ uses the new operator to dynamically allocate memory on the heap at the run time.
     */

     // delete
     cout << "\n\ndelete CONCEPT: \n\n\n";
     int *B = new int;
     *B = 10;
     delete B;

     // delete[]
     cout << "\ndelete[] CONCEPT: \n";
     int *A = new int[10];
     A[0] = 100;
     A[1] = 200;
     cout << endl
          << "Created dynamic array A of size 10 :" << endl
          << "The memory address of A is: " << &A << endl
          << "The memory address stored in A is: " << A << endl
          << "The value at that memory address is: " << *A << endl
          << "The value at that memory address + 1 is: " << *(A + 1);

     /*
     -> Deallocating this memory using delete[] because we want to free the space allocated for the entire array and not just the first element.

     -> When delete is used to deallocate memory for a C++ class object, the object's destructor is called before the object's memory is deallocated (if the object has a destructor).

     -> It calls as many destructors as the size of the array.
     */
     delete[] A;

     cout << endl
          << "After delete[] :" << endl
          << "The memory address of A is: " << &A << endl
          << "The memory address stored in A is: " << A << endl
          << "The value at that memory address is: " << *A << endl
          << "The value at that memory address + 1 is: " << *(A + 1);

     // We observe that the values stored at A[0] and A[1] have been deleted and that means delete[] A worked successfully.

     return 0;
}