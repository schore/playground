#include <iostream>
#include <func_2.h>
using namespace std;

int foo(int a, int b) {
    return a + b;
}

int main()  {
    cout << "Hello World!!" << endl;
    cout << foo(3,5) << endl;
    cout << foo(4,2) << endl;

    cout << func_2(1,5) << endl;
}

