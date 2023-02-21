#include <iostream>
using namespace std;

class A
{
private:
protected:
    int a;

public:
};

class B : public A
{
private:
    int b = a;

protected:
public:
}

int
main()
{
    return 0;
}