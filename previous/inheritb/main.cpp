#include <iostream>

using namespace std;

class base
{
protected:
    int protected_number;

public:
    base(int=0);
    int set_number_base();
};

inline base::base(int x):protected_number(x){cout << "In Constructor: base" << endl;}
inline int base::set_number_base()
{
    //private_number = 5;
    return ++protected_number;
}


class derived: private base
{
public:
    int get_number_derived();
    int set_number_derived();
};

inline int derived::get_number_derived()
{
    return protected_number;
}


inline derived::set_number_derived()
{
    protected_number=20;
    //base::private_number = 10;
    return protected_number;
}


/*
class derived: public base
{
private:
    int number;
public:
    derived(int = 1);
    int get_number();
};

inline derived::derived(int y):number(y){}
inline int derived::get_number()
{
    number=4;
    base::number++;
    return base::number;
}
*/

int main()
{
    derived b;
    //b.get_number_derived();
    cout << b.get_number_derived() << endl;
    cout << b.set_number_derived() << endl;
    //derived a;
    //cout << a.get_number() << endl;
    //cout << a.base::get_number() << endl;
    return 0;
}

