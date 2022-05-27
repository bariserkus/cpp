#include <iostream>

using namespace std;

struct Employee
{
    string m_name;
    int m_age;

    Employee()
    {
        m_name = "";
        m_age = 0;
    }
    Employee(string _name)
    {
        m_name = _name;
    }
    Employee(string _name, int _age)
    {
        m_name = _name;
        m_age = _age;
    }


    void set_emp()
    {
        cout << "Enter name and age: " ;
        cin >> m_name >> m_age;
    }

    void get_emp()
    {
        cout << "Name of the Employee: " << m_name << endl;
        cout << "Age of the Employee: " << m_age << endl;
    }

    void set_age(int a)
    {
        m_age = a;
    }

    void set_name(string n)
    {
        m_name = n;
        m_age = 0;
    }

};

bool compare_name(Employee& e1, Employee& e2)
{
    return e1.m_name < e2.m_name;
}

int main()
{
    int ne {0};
    Employee e[10];

    e[ne++].set_emp();
    e[ne++].set_emp();

    for (int i = 0; i < ne; ++i)
        e[i].get_emp();

    sort(e, e+ne, compare_name);

    cout << e[0].m_name << endl;

    for (int i = 0; i < ne; ++i)
        e[i].get_emp();

    cout << "Hello world!" << endl;

    Employee a("Mehmet", 35);
    a.get_emp();

    Employee b("Zerrin");
    b.get_emp();
    return 0;
}
