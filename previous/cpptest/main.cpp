#include<iostream>
using namespace std;

int main()
{
    const int SIZE = 5;
    int numbers[SIZE] { 1, 2, 4, 3, 10 };

    int cnt = 0;

    for (int i = 1; i < SIZE; ++i)
    {
        cout << "i = " << i << " " << numbers[i + 1] << endl;
        if (numbers[i - 1] < numbers[i] && numbers[i] < numbers[i + 1])
            cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
