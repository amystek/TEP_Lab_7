#ifndef LAB_7_CMYSMARTPOINTER_H
#define LAB_7_CMYSMARTPOINTER_H

#include <iostream>

using namespace std;

template <typename T>
class CMySmartPointer
{
private:
    class CRefCounter
    {
    public:
        CRefCounter() { i_count = 0; }
        int iAdd() { return(++i_count); }
        int iDec() { return(--i_count); };
        int iGet() { return(i_count); }
    private:
        int  i_count;
    }; //class CRefCounter

    CRefCounter *pc_counter;
    T *pc_pointer;


public:
//    CMySmartPointer(CSellData *pcPointer)
    CMySmartPointer(T *pcPointer)
    {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }//CMySmartPointer(CSellData *pcPointer)

    CMySmartPointer(const CMySmartPointer &pcOther)
    {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }//CMySmartPointer(const CMySmartPointer &pcOther)

    ~CMySmartPointer()
    {
        if (pc_counter->iDec() == 0)
        {
            delete pc_pointer;
            delete pc_counter;
        } //if (pc_counter->iDec() == 0)
    } //~CMySmartPointer()

    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }
    CMySmartPointer<T>* operator=(const CMySmartPointer<T>* pcOther);
    void vPrint();
}; //class CMySmartPointer


template<typename T>
CMySmartPointer<T> *CMySmartPointer<T>::operator=(const CMySmartPointer<T> *pcOther)
{
    if (pcOther == NULL) { return NULL; }
    pc_pointer = pcOther->pc_pointer;
    pc_counter = pcOther->pc_counter->iAdd();

    return this;
}

template<typename T>
void CMySmartPointer<T>::vPrint()
{
    cout << "pc_pointer address:" << &pc_pointer;
    cout << "; number of references : " << pc_counter->iGet() << endl;
} //void CMySmartPointer<T>::vPrint()
//CMySmartPointer<T> *CMySmartPointer<T>::operator=(const CMySmartPointer<T> *pcOther)


#endif //LAB_7_CMYSMARTPOINTER_H
