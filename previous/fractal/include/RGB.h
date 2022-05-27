#ifndef RGB_H
#define RGB_H

namespace cop
{

struct RGB
{
public:
    RGB(double r, double g, double b);
    double r, g, b;

protected:
private:
};

RGB operator-(const RGB& first, const RGB& second);

}
#endif // RGB_H
