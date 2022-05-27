#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    float e;

    cout << "Ilk Sayiyi Giriniz > " << flush;
    cin >> a;

    cout << "Ikinci Sayiyi Giriniz > " << flush;
    cin >> b;

    c = a + b;
    d = a * b;
    e = (float) a / b;

    cout << "Birinci sayi ile ikinci sayi toplami " << c << "'dir" << endl;
    cout << "Birinci sayi ile ikinci sayi carpimi " << d << "'dir" << endl;
    cout << "Birinci sayi bolu ikinci sayi : " << e << "'dir" << endl;

    return 0;
}
