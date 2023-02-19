#include <iostream>
using namespace std;

class Hero
{
private:
    int weight, height;

public:
    Hero(int w, int h)
    {
        this->weight = w;
        this->weight = h;
    }
};

int main()
{
    Hero H(10, 20);
    return 0;
}