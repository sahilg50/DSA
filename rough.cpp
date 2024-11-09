#include <iostream>
using namespace std;

class Phone
{
private:
protected:
public:
    int number = 10;
    void info()
    {
        cout << "\nModel: Phone\nNumber: " << this->number << endl;
    }
};

class Android : public Phone
{
private:
protected:
public:
    int number = 12345;
    void info()
    {
        cout << "\nModel: Android\nNumber: " << this->number << endl;
    }
};

int main()
{
    Android device;
    cout << device.Phone::number;
    device.info();
    return 0;
}