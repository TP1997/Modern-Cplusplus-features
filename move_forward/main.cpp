#include <iostream>
#include <string>

using namespace std;

class Annotation{
public:
    string value;
    explicit Annotation(const string text): value(move(text)){};
};
class Test{
public:
    string value;
    Test(const string &s): value(s){cout << "copy ctor called!\n";};      //Copy ctr.
    Test(string &&s): value(s){cout << "move ctor1 called!\n";};           //Move ctr
    Test(string &s): value(move(s)){cout << "move ctor2 called!\n";};
};

void foo(const int &&i){
    cout << i << endl;
}
int main()
{
    //string s="moi";
    //Test t1(s);
    //Test t2("no moi");
    string ss="moi moi";
    Test t3(ss);
    ss="asd";
    cout << ss << endl;
    cout << t3.value << endl;
/*
    int i=1;
    foo(i);*/
    return 0;
}
