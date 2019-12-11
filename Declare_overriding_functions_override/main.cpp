//Testing (contextual) keyword, override & member function reference qualifiers.

#include <iostream>
#include <vector>
using namespace std;

class Base {
public:
    virtual void mf1() const;
    virtual void mf2(int x);
    virtual void mf3() &;
    //void mf4() const;                         //Getting errors.
    virtual void mf4() const;
};
class Derived: public Base {
public:
    //virtual void mf1()override;               //Getting errors.
    void mf1() const override;
    //virtual void mf2(unsigned int x)override; //--"--
    void mf2(int x) override;
    //virtual void mf3() && override;           //--"--
    void mf3() & override;
    //void mf4() const override;                //--"--
    void mf4() const override;
    void override();                            //Legal even if override is reserved word.
};
class Widget {
public:
    using DataType = std::vector<double>;
    Widget(){
        values.reserve(1000000);
    }
// for lvalue Widgets, return lvalue
    DataType& data() &{
        return values;
    }
// for rvalue Widgets, return rvalue
    DataType data() &&{
        return std::move(values);
    }
private:
    DataType values;
};

auto makeWidget(){
    return Widget();
}
int main()
{
    Widget w;
//Calls lvalue overload of Widget::data & Copy construct vals1.
    auto vals1=w.data();
//Calls rvalue overload of Widget::data & Move construct vals1. Widget is the temporary object returned from makeWidget (rvalue)
//so copying the std::vector inside it is a waste of time. (Temporary object no longer needed (exist) ==> temp.values no longer needed (exist) ==> Okay to move.
    auto vals2=makeWidget().data();
    return 0;
}
