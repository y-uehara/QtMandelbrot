#include "CalcMandelbrot.h"

CalcMandelbrot::CalcMandelbrot(int pixelWidth, int pixelHeight) :
    CalcFractalBase(pixelWidth, pixelHeight)
{

}

CalcMandelbrot::~CalcMandelbrot()
{

}

void CalcMandelbrot::calc(unsigned char *data, double minX, double minY, double maxX, double maxY)
{
    for(int i = 0; i < m_pixelHeight; i++)
    {
        for(int j = 0; j < m_pixelWidth; j++)
        {
            // calc related complex number for the pixel
            std::complex<double> c((minX + (maxX - minX) * j / m_pixelWidth),
                                   (minY + (maxY - minY) * i / m_pixelHeight));

            int divergence = calcDivergence(c);

            if(divergence == 0)
            {
                // not divergence (mandelbrot)
                setA(data, j, i, 255);
                setR(data, j, i, 0);
                setG(data, j, i, 0);
                setB(data, j, i, 0);
            }
            else
            {
                // divergence
                setA(data, j, i, 255);
                setR(data, j, i, (divergence * 255 / 20));
                setG(data, j, i, 0);
                setB(data, j, i, (divergence * 255 / 20));
            }
        }
    }
}

int CalcMandelbrot::calcDivergence(std::complex<double> c)
{
    int count = 0;

    std::complex<double> z(0.0, 0.0);

    while(std::abs(z) < 2.0)
    {
        z = (z * z) + c;
        count++;
        if(count > 20)
        {
            // not divergence
            return 0;
        }
    }
    // divergence
    return count;
}
