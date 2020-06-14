#ifndef LAB_7_MYINT_H
#define LAB_7_MYINT_H

#include <iostream>

using namespace std;

class MyInt
{
public:
    MyInt(int iValue) { i_value = iValue; };
    ~MyInt() { cout << "MyInt dealocation" << endl; };
    int iGet() { return i_value; };

private:
    int i_value;
};

#endif //LAB_7_MYINT_H
