/*
TOPIC: What is Encapsulation ?
    -> Encapsulation is defined as binding together the data and the functions that manipulates that data under a single unit.

    -> It is done to make sure that "sensitive" data is hidden from users. It increases security.

TOPIC: How to Achieve Encapsulation ?
    -> Declare class variables/attributes as private (cannot be accessed from outside the class).

    -> If you want others to read or modify the value of a private member, you can provide public get and set methods.

TOPIC: Real Life Example of Encapsulation
    -> A company has different sections like accounts, finance, sales, etc. The finance section handles all the financial transactions and records all the finance-related data. Similarly, the sales section manages all the sales-related activities and keeps records of all the sales. For some reason, a finance section official needs all the sales data in a particular month. In this case, he is not allowed to access the data of the sales section directly. He will first have to contact some other officer in the sales section and then request him to give the particular data. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name, “sales section.” This is called encapsulation.
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