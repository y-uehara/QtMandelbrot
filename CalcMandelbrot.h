#ifndef CALCMANDELBROT_H
#define CALCMANDELBROT_H

#include "CalcFractalBase.h"

class CalcMandelbrot : public CalcFractalBase
{
public:
    CalcMandelbrot(int pixelWidth, int pixelHeight, double minX, double minY, double maxX, double maxY);
    ~CalcMandelbrot();

    void calc(unsigned char *data) override;

private:
    int calcDivergence(std::complex<double> c);
};

#endif // CALCMANDELBROT_H
