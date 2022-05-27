#include <iostream>

using namespace std;

static int A[3][5];

void printRow(int row)
{
    for (int i = 0;  i < 5; ++i)
    {
        cout << A[row][i] << " ";
    }
    cout << endl;
}

int main()
{
    for (int i = 0; i<3; ++i)
    {
        printRow(i);
    }
    return 0;
}
