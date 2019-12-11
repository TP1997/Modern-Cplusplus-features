//constexpr-variable:
//-Known value at compilation time.
//-Constant.

//constexpt-functions:
//-Produce compile-time constants when they are called with compile-time constants (the result will be computed during compilation).
//-If called with (one or more) values not known until runtime, they produce runtime values (acts like normal function).
//==> you don’t need two functions to perform the same operation for compile & runtime.

#include <iostream>
#include <array>
#include <vector>
using namespace std;

//C++11 way:
constexpr
int pow11(int base, int exp) noexcept{
    return (exp==0? 1 : pow11(base, exp-1));
}
//C++14 way:
//constexpr
int pow14(int base, int exp) noexcept{
    auto res=1;
    for(int i = 0; i < exp; ++i) res *= base;

    return res;
}

class Point {
public:
    constexpr Point(double xVal = 0, double yVal = 0) noexcept : x(xVal), y(yVal){}
    constexpr double xValue() const noexcept { return x; }
    constexpr double yValue() const noexcept { return y; }
    void setX(double newX) noexcept { x = newX; }//Cant declared constexpr (in C++11!!), since they modify the object they operate on & void isn’t a literal type in C++11
    void setY(double newY) noexcept { y = newY; }//ditto
    //constexpr void setX(double newX) noexcept { x = newX; }//C++14
    //constexpr void setY(double newY) noexcept { y = newY; }//C++14
private:
    double x, y;
};

constexpr
Point midpoint(const Point& p1, const Point& p2) noexcept{
    return { (p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2 };
}

// return reflection of p with respect to the origin (C++14)
constexpr Point reflection(const Point& p) noexcept{
    Point result;               // create non-const Point
    result.setX(-p.xValue());
    result.setY(-p.yValue());   // set its x and y values
    return result;              // return copy of it
}
int main()
{
//constexpr-variable-testing:
/*    int sz=0;

    //constexpr auto arraySize1 = sz;
    constexpr auto arraySize2 = 10;
    array<int, sz> data2;
*/
//constexpr-function-testing:
/*    constexpr auto numConds = 5;
    std::array<int, pow11(3, numConds)> results;
*/
//constexpr-class testing (literal types):
    constexpr Point p1(9.4, 27.7);
    constexpr Point p2(9.4, 27.7);
    constexpr auto mid = midpoint(p1, p2);
    //array<int, pow11(3, mid.xValue()*10)> rndmTemplateTest1;
    //array<int, static_cast<int>(mid.xValue()*10)> rndmTemplateTest2;
    return 0;
}
