#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool sortbyfirst(const pair<string, int> &a,
                 const pair<string, int> &b)
{

    return (a.first < b.first);
}

bool sortbysec(const pair<string, int> &a,
               const pair<string, int> &b)
{
    if (a.first == b.first)
    {
        return (a.second > b.second);
    }
    else
    {
        return false;
    }
}

int main()
{

    int N;
    cin >> N;

    vector<pair<string, int>> vect;
    string Ci;
    int Si;
    for (int i = 0; i < N; i++)
    {
        cin >> Ci >> Si;
        vect.push_back(make_pair(Ci, Si));
    }

    cout << endl;
    sort(vect.begin(), vect.end(), sortbyfirst);

    for (int i = 0; i < N; i++)
    {
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    cout << endl;

    sort(vect.begin(), vect.end(), sortbysec);

    for (int i = 0; i < N; i++)
    {
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    return 0;
}