#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
     /*
     A capture clause of lambda definition is used to specify which variables are captured and whether they are captured by reference or by value.
     An empty capture closure [ ], indicates that no variables are used by lambda which means it can only access variables that are local to it.
     The “capture-default” mode indicates how to capture outside the variables referenced in Lambda:

     The capture closure [&] means the variables are captured by reference.
     The capture closure [=] indicates that the variables are captured by value.
     */
     cout << endl
          << [](int x, int y)
     { return x + y; }(2, 11);

     auto sum = [](int x, int y)
     { return x + y; };
     cout << endl
          << sum(7, 7);

     vector<int> v = {1, 3, 4, 30, 9};

     // Using all_of
     cout << endl
          << "All positive? " << all_of(v.begin(), v.end(), [](int x)
                                        { return x > 0; });

     /*
     Note that if a function is small and is only needed once then use lamda function.
     */

     // Using any_of
     cout << endl
          << "Any positive? " << any_of(v.begin(), v.end(), [](int x)
                                        { return x > 0; });

     // Using none_of
     cout << endl
          << "None positive? " << none_of(v.begin(), v.end(), [](int x)
                                          { return x > 0; });
     return 0;
}