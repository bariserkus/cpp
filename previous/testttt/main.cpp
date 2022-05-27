#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    const int size = 20;
    char name[size];
    int x, y, z ;
    int array[] = {0, 2, 4, 6, 7, 5, 3};
    int n, result = 0;
    for (n = 0; n < 8; n++)
    {
        result += array[n];
    }
    printf("%d\n",result);
    cout.setf(ios::showpos | ios::uppercase);
    cin.operator>>(x) >> y >> z;
    cout.operator<<(x) << y << z << endl;
    cin.width(5);
    cin.getline(name,size);
    cout << name;
    return 0;
}


