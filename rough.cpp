#include <iostream>
using namespace std;

void test(int *arr)
{
    *arr = 100;
}
int main()
{
    // int arr[] = {1, 3, 4, 2, 10, 9};
    int arr = 10;
    test(&arr);
    cout << arr;
    return 0;
}