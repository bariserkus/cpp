#include <iostream>

using namespace std;

struct Employee
{
    string name;
    int age;
    double salary;
    char gender;
};

void readEmployee(Employee& e)
{
    cout << "Enter Employee Name: " ;
    cin >> e.name;
    cout << "Enter Employee Age: " ;
    cin >> e.age;
    cout << "Enter Employee Salary: " ;
    cin >> e.salary;
    cout << "Enter Employee Gender: " ;
    cin >> e.gender;
}

void writeEmployee(const Employee& e)
{
        cout << "Name: "<< e.name << endl;
        cout << "Age: "<< e.age << endl;
        cout << "Salary: "<< e.salary << endl;
        cout << "Gender: "<< e.gender << endl;
}



int main()
{
    Employee();
    int en = 0;
    Employee es[100];
    es[en].name = "Baris";
    es[en].age = 46;
    es[en].salary = 2500.50;
    es[en].gender = 'M';
    ++en;
    es[en++] = {"Ahmet", 50, 3500.40, 'F'};
    es[en++] = es[1];
    cout << "Number of Employees: " << en+1 << endl;
    readEmployee(es[en]);
    for (int i = 0; i < en+1; ++i)
    {
        cout << "\nEmployee No: " << i << endl;
        writeEmployee(es[i]);
    }




    return 0;
}
