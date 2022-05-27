#include <iostream>

using namespace std;

int main()
{
    int a, b, c;

    cout << "İlk Sayıyı Giriniz > " << flush;
    cin >> a;

    cout << "İkinci Sayıyı Giriniz > " << flush;
    cin >> b;

    c = a + b;

    cout << "Birinci sayı ile ikinci sayı toplamı" << c << "dir" << endl;


    cout << "Starting the program" << flush;

    cout << "Starting the program AGAIN without flush";

    cout << "\n" << flush;

    cout << "Hello world!" << endl;

    cout << "This is some more shit" << endl;

    cout << "Test" << " " << "This Text" << endl;

    //cout << "A new Test" << " This Text" << flush;

    cout << "Test if without endl and flush" ;

    return 0;
}
