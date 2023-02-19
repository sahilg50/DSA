#include <iostream>
using namespace std;

class Hero
{
private:
public:
    int life = 10, health = 100;
    void getInfo()
    {
        cout << endl
             << this->life << " " << this->health;
    }
};

int main()
{
    Hero H1;
    H1.getInfo();
    Hero H2(H1);
    H2.life = 20;
    H2.getInfo();

    return 0;
}