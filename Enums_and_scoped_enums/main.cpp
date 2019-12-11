#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

enum class Test1: long int{ good = 0,
            failed = 1,
            incomplete = 100,
            corrupt = 200,
            audited = 500,
            indeterminate = 0xFFFFFFFF
          };

enum Test2{ good = 0,
            failed = 1,
            incomplete = 100,
            corrupt = 200,
            audited = 500,
            indeterminate = 0xFFFFFFFF
          };
enum Test3: bool{x=true,y=false};

//Check enumerators underlying type
template<typename E>
constexpr auto toUType(E enumerator)noexcept{
    return static_cast<underlying_type_t<E>>(enumerator);
}
int main()
{
    using Test1_Utype = underlying_type_t<Test1>;
    using Test2_Utype = underlying_type_t<Test2>;
    using Test3_Utype = underlying_type_t<Test3>;
    cout << "Underlying types of example enums:\n";
    cout << "Type of Test1: " << typeid(Test1_Utype).name() << ". Size: " << sizeof(Test1_Utype) << " bytes." << endl;
    cout << "Type of Test2: " << typeid(Test2_Utype).name() << ". Size: " << sizeof(Test2_Utype) << " bytes." << endl;
    cout << "Type of Test3: " << typeid(Test3_Utype).name() << ". Size: " << sizeof(Test3_Utype) << " bytes." << endl;


    return 0;
}
