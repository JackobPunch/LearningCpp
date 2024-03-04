#include <iostream>

using namespace std;

void swapPointers(int *ptr1, int *ptr2)
{
    int temp{*ptr2};
    *ptr2 = *ptr1;
    *ptr1 = temp;
}

int main()
{
    int a{5};
    int b{10};

    int *ptrA = &a;
    int *ptrB = &b;

    cout << *ptrA << endl;
    cout << *ptrB << endl;

    swapPointers(ptrA, ptrB);

    cout << *ptrA << endl;
    cout << *ptrB << endl;

    return 0;
}