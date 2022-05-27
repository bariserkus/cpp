#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace cop
{

class FractalCreator
{
private:
    int m_width, m_height;
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total{0};

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange{false};


private:
    void calculateIteration();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name);
    int getRange(int iteartions) const;

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void addRange(double rangeEnd, const RGB& rgb);
    void addZoom(const Zoom& zoom);
    void run(string name);
};

}
#endif // FRACTALCREATOR_H
