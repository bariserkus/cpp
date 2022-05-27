#include <iostream>
//#include <vector>

using namespace std;

int move_zeros(int a[], int n);

void move_zeros(int a[], int n)
{
    int read_index = n-1;
    int write_index = n-1;

    for (; read_index >=0; --read_index)
    {
        if (a[read_index] != 0)
        {
            a[write_index] = a[read_index];
            --write_index;
        }
    }
    for (; write_index>=0; --write_index) a[write_index] = 0;
}

int main()
{
    int v[] = {1, 10, 20, 0, 59, 63, 0, 88, 0, 100};
    int n = sizeof(v) / sizeof(v[0]);

    cout << "Original Array: " ;

    for(int x=0 ; x<n; x++)
    {
        cout << v[x];
        cout << ", ";
    }


    move_zeros(v, n);

    cout << endl << "Modified Array: " ;

    for(int x=0 ; x<n; x++)
    {
        cout << v[x];
        cout << ", ";
    }

}
