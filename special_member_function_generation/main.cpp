#include <iostream>

using namespace std;

class Widget {
public:
    int x, y;
//(0)user-declared ctor
    Widget(int x_, int y_): x(x_), y(y_){};
//user-declared dtor
    ~Widget(){};
//(1)default copy ctor behavior is OK
    Widget(const Widget&) = default;
//(2)default copy assign behavior is OK
    Widget& operator=(const Widget&) = default;
//(3)default move ctor behavior is OK
    Widget(Widget&&) = default;
//(4)default move assign behavior is OK
    Widget& operator=(Widget&&) = default;

};
int main()
{
//See 0.
    Widget w1(1,1);
    cout << "w1: x = " << w1.x << ", y = " << w1.y << endl;
//See (1).
    Widget w2(w1);
    cout << "w2: x = " << w2.x << ", y = " << w2.y << endl;
//See (2).
    Widget w3=w1;
    cout << "w3: x = " << w3.x << ", y = " << w3.y << endl;
//See (3).
    Widget w4(move(w1));
    cout << "w4: x = " << w4.x << ", y = " << w4.y << endl;
//See (4).
    Widget w5=Widget(2,2);
    cout << "w5: x = " << w5.x << ", y = " << w5.y << endl;
    return 0;
}
