#ifndef MANDELBROT_H
#define MANDELBROT_H

namespace cop
{
class Mandelbrot
{
private:

public:
    static const int MAX_ITERATIONS = 1000;

public:
    Mandelbrot();
    virtual ~Mandelbrot();
    static int getIterations(double x, double y);

protected:

private:
};
}
#endif // MANDELBROT_H
