#include <iostream>
#include <vector>

using namespace std;

//Test 1.
template<typename T>
void f1(vector<T>&& param){};    //param is a rvalue reference.
//Test 2.
template<typename T>
void f2(T&& param){};            //param is an universal reference.
//Test 3.
template<typename T>
void f3(const T&& param){};      //param is a rvalue reference.
//Test 4.
template<typename T>
class C4{
public:
    void ctest(T&& param){};    //param is rvalue reference (depends on C4).

    template<typename T2>
    void ctest2(T2&& param){};  //param is an universal reference.
};

int main()
{
//Test 1.
    vector<int> v;
    //f1(v);                       //Error! cannot bind lvalue to rvalue reference!

//Test 2.
    int n=0;
    f2(n);                         //Okay.
    f2(0);                         //Okay.

//Test 3.
    const int m=0;
    //f3(m);                       //Error! cannot bind lvalue to rvalue reference!
    f3(0);                         //Okay.

//Test 4.
    C4<int> c4;
    int l=0;
    //c4.ctest(l);                 //Error! cannot bind lvalue to rvalue reference!
    c4.ctest2(l);                  //Okay.
}
