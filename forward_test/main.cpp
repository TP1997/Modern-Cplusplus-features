#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

decltype(auto) fn(int &&i){
    return forward<int>(++i);
}

void fn2(int &&i){
    cout << i;
    ++i;
}
void fooMove(vector<int> &v){
    int n1=1;
    int n2=2;
    v.push_back(move(n1));
    v.push_back(move(n2));
    cout << n2 << endl;
}
void fooCopy(vector<int> &v){
    int n1=1;
    int n2=2;
    v.push_back(n1);
    v.push_back(n2);
}
auto test(){
    return 3;
}
int main()
{

/* COPY VS MOVE*/
    vector< list<int> > targ(100000);
    for(auto &lst : targ){
        lst.resize(1000);
    }
    cout << "Test begin..." << endl;

    auto s1=high_resolution_clock::now();
    vector< list<int> > destCpy;
    for(auto lst : targ){
        destCpy.push_back(lst);
    }
    auto e1=high_resolution_clock::now();
    auto dur1=duration_cast<microseconds>(e1-s1);
    cout << "Copy time: " << dur1.count() << " microseconds." << endl;

    auto s2=high_resolution_clock::now();
    vector< list<int> > destMve;
    destMve.reserve(100000);
    for(auto &lst : targ){
        destMve.push_back(move(lst));
    }
    auto e2=high_resolution_clock::now();
    auto dur2=duration_cast<microseconds>(e2-s2);
    cout << "Move time: " << dur2.count() << " microseconds." << endl;

/* MOVE TEST 2
    string s1="aaaaaaaa";
    string s2="bbbbbbbbbb";
    vector<string> ss;
    ss.push_back(move(s1));
    ss.push_back(move(s2));
    ss.push_back(s2);

    for(string &s : ss){
        cout << s << endl;
    }
    //s2="test";
    cout << endl << s2; //Can't print anymore because line 68.
*/
/*    vector<int> vMove, vCopy;
    fooMove(vMove);
    fooCopy(vCopy);

    cout << "Move vector:\n";
    for(int &i : vMove)
        cout << i << " ";
    cout << endl << "Copy vector:\n";
    for(int &i : vCopy)
        cout << i << " ";*/


}
