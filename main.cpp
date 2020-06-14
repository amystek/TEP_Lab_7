#include "main.h"

int main()
{
    v_TestSmartPointer();
    cout << "After v_TestSmartPointer() method exit" << endl;

    return 0;
} //int main()

void v_TestSmartPointer()
{
    CMySmartPointer<MyInt> c_sp1(new MyInt(10));
    c_sp1.vPrint();
    CMySmartPointer<MyInt> c_sp1_copy = c_sp1;

    c_sp1.vPrint();
    c_sp1_copy.vPrint();

    cout << "c_sp1 value: " << c_sp1->iGet() << "; c_sp1_copy value: " << c_sp1_copy->iGet() << endl;
    cout << "Last line of v_TestSmartPointer() method" << endl;
}
