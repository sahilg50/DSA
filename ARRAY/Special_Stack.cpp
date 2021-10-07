/*
Implement a special type of stack in which two values will be inserted with one push
operation and two values will be deleted with one pop operation. With one Push
operation, top will be increased once and with one Pop operation, Top will be decreased
only once.
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

class Stack
{
    int top = 0, a[MAX][2];

public:
    bool push(int key, int val)
    {
        if (top == MAX)
        {
            cout << "Stack size overflow\n";
            return false;
        }
        else
        {
            a[top][0] = key;
            a[top++][1] = val;
            return true;
        }
    }

    bool pop()
    {
        if (top == 0)
        {
            cout << "Empty Stack\n";
            return false;
        }
        else
        {
            top--;
            return true;
        }
    }

    int *topp()
    {
        if (top > 0)
            return a[top - 1];
        else
            return NULL;
    }

    void print()
    {
        cout << "Elements of stack:\n";
        for (int i = 0; i < top; i++)
            cout << a[i][0] << " " << a[i][1] << endl;
    }
};

int main()
{
    Stack mystack;
    mystack.push(1, 5);
    mystack.push(2, 6);
    mystack.push(3, 7);

    mystack.print();

    mystack.pop();
    cout << "\n\n\nAfter 1 pop: \n";
    int *topelements = mystack.topp();
    cout << "Top elements are: " << topelements[0] << " " << topelements[1] << endl;

    cout << "\n\n\nAfter 2 pops: \n";
    mystack.pop();
    mystack.print();

    return 0;
}
