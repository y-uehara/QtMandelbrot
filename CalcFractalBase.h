#ifndef CALCFRACTALBASE_H
#define CALCFRACTALBASE_H

#include <complex>

class CalcFractalBase
{
public:
    CalcFractalBase(int pixelWidth, int pixelHeight);
    virtual ~CalcFractalBase();

    virtual void calc(unsigned char *data, double minX, double minY, double maxX, double maxY) = 0;

protected:
    // (0,0)  (1,0)
    // (0,1)  (1,1)

    // following functions DON'T check memory before writing!
    void setA(unsigned char *data, int x, int y, unsigned char value) { data[(y * m_pixelWidth + x) * 4 + 3] = value; }
    void setR(unsigned char *data, int x, int y, unsigned char value) { data[(y * m_pixelWidth + x) * 4 + 2] = value; }
    void setG(unsigned char *data, int x, int y, unsigned char value) { data[(y * m_pixelWidth + x) * 4 + 1] = value; }
    void setB(unsigned char *data, int x, int y, unsigned char value) { data[(y * m_pixelWidth + x) * 4 + 0] = value; }

    int m_pixelWidth;
    int m_pixelHeight;
};

#endif // CALCFRACTALBASE_H
