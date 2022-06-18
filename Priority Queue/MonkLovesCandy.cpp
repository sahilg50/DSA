// Hacker Earth problem: Our Monk loves candy!

#include <iostream>
#include <set>
using namespace std;
int main()
{

    // Number of test cases
    cout << endl
         << "Enter the total Number of test cases: " << endl;
    int T;
    cin >> T;
    while (T--)
    {
        cout << "Enter the total number of bags and the number of bags that the monk can eat from: " << endl;
        int n, k;
        cin >> n >> k;
        multiset<long long int> bags;
        cout << "Enter the candies in each bag: " << endl;
        for (int i = 0; i < n; i++)
        {
            long long int candy_ct;
            cin >> candy_ct;
            bags.insert(candy_ct);
        }
        long long int total_candies = 0;
        for (int i = 0; i < k; i++)
        {
            auto last_it = --bags.end();
            long long int candy_ct = *last_it;
            total_candies += candy_ct;
            bags.erase(last_it);
            bags.insert(candy_ct / 2);
        }
        cout << total_candies << endl;
    }
    return 0;
}