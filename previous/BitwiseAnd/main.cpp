#include <iostream>

using namespace std;

int main()
{
    int color = 0x123456;

    unsigned char red = (color & 0xFF0000) >> 16;
    unsigned char green = (color & 0x00FF00) >> 8;
    unsigned char blue = (color & 0x0000FF);

    cout << hex << (int)green << endl;

    unsigned char redAgain = color >> 16;
    cout << hex << (int)redAgain << endl;

    return 0;
}
