#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct node
{
    int val;
    node *next;

    node(int x) : val(x), next(nullptr) {} //constuctor for the structure
};

int main()
{

    node n1(10);
    node *temp = &n1;

    cout << n1.next;
    cout << temp->next;
    return 0;
}