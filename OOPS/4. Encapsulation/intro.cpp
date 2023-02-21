/*
In normal terms Encapsulation is defined as wrapping up of data and information under a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulates them. Consider a real life example of encapsulation, in a company there are different sections like the accounts section, finance section, sales section etc. The finance section handles all the financial transactions and keep records of all the data related to finance. Similarly the sales section handles all the sales related activities and keep records of all the sales. Now there may arise a situation when for some reason an official from finance section needs all the data about sales in a particular month. In this case, he is not allowed to directly access the data of sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data. This is what encapsulation is. Here the data of sales section and the employees that can manipulate them are wrapped under a single name “sales section”.

We can not access any function from class directly. We need an object to access that function which is using the member the variable of that class.

The function which we are making inside the class ,it must use the all member variable then only it is called encapsulation.

If we  don’t  make function inside the class which is using the member  variable of the class then we don’t call it encapsulation.
*/

#include <iostream>
using namespace std;

class SalesDept
{
private:
    int data;

public:
    void setData(int a) { data = a; };
    void showData() { cout << "Data: " << data << endl; }
};

int main()
{
    SalesDept s;
    s.setData(10);
    s.showData();
    return 0;
}