#include <iostream>
#include <vector>

using namespace std;

void printarr(vector<int> * a)
{
    for (auto v:*a)
        cout << v << " ";
}

void printarr(int (&a)[4])
{
    for (auto i:a)
        cout << i << " ";
}

int main()
{
    int arr[] = {1, 5, 7, 10};

    for (auto i:arr)
        cout << i << " ";


    int* ptr = arr;
    cout << "arr : " << arr << endl;
    // cout << "++arr : " << ++arr << endl; Error

    while (ptr != arr+4)
        cout << *ptr++ << " ";
    cout << endl;

    cout << "ptr : " << ptr << endl;
    cout << "--ptr : " << --ptr << endl;
    cout << "*ptr : " << *ptr << endl;
    cout << "*ptr++ : " << *ptr++ << endl;
    cout << "ptr : " << *ptr << endl;
    cout << "*ptr : " << *ptr << endl;


    return 0;
}
