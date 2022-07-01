#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
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