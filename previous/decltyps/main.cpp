#include <iostream>
#include <typeinfo>

using namespace std;

template <class T, class S>
auto test(T value1, S value2)-> decltype(value1 + value2)
{
    return value1 + value2;
}

int get()
{
    return 999;
}

auto test2() -> decltype(get())
{
    return get();
}


int main()
{
    auto value = 7;

    auto text = "Hello";

    cout << typeid(text).name() << endl;

    cout << value << endl;

    cout << test(6.4 , 5) << endl;
    cout << test2() << endl;
    return 0;
}
