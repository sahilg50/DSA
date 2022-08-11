#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int Mx = 1e5 + 5;
int par[Mx], cnt[Mx];

void ini(int n)
{
    for (int i = 1; i <= n; ++i)
        par[i] = i, cnt[i] = 1;
}

int root(int a)
{
    if (a == par[a])
        return a;
    return par[a] = root(par[a]);
}

void Union(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a == b)
        return;
    if (cnt[a] > cnt[b])
        swap(a, b);
    par[a] = b;
    cnt[b] += cnt[a];
}
vector<int> getTheGroups(int n, int q, int sz, vector<string> queryTypes, vector<int> student1, vector<int> student2, vector<int> &ans)
{
    ini(n);
    int current = 0;

    for (int i = 0; i < q; ++i)
    {
        if (queryTypes[i] == "Friend")
        {
            Union(student1[i], student2[i]);
        }
        else
        {
            int x = root(student1[i]), y = root(student2[i]);
            if (x == y)
                ans[current++] = cnt[x];
            else
                ans[current++] = cnt[x] + cnt[y];
        }
    }
    return ans;
}
int main()
{
    int n, q, sz = 0;
    cin >> n >> q;
    vector<string> queryTypes(q);
    vector<int> student1(q), student2(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> queryTypes[i];
        if (queryTypes[i] == "Total")
            ++sz;
    }
    cin >> q;
    for (int i = 0; i < q; ++i)
        cin >> student1[i];
    cin >> q;
    for (int i = 0; i < q; ++i)
        cin >> student2[i];
    vector<int> ans(sz);
    vector<int> ptr = getTheGroups(n, q, sz, queryTypes, student1, student2, ans);
    for (int i = 0; i < sz; ++i)
        cout << ptr[i] << endl;
    return 0;
}