#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct node
{
    int val;
    struct node *next;

    node(int x) : val(x), next(nullptr) {} // constuctor for the structure
};

int main()
{

    node n1(10);
    struct node *temp = &n1;

    cout << n1.next;
    cout << temp->next;

    return 0;
}