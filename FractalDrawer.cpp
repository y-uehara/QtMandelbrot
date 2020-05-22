#include "FractalDrawer.h"

FractalDrawer::FractalDrawer(int width, int height) :
    QObject()
{
    m_canvasWidth = width;
    m_canvasHeight = height;

    m_minX = -2.0;
    m_minY = -2.0;
    m_maxX = 2.0;
    m_maxY = 2.0;

    m_calculator = new CalcMandelbrot(m_canvasWidth, m_canvasHeight);
}

FractalDrawer::~FractalDrawer()
{
    delete m_calculator;
}

void FractalDrawer::setImageBitmap(unsigned char *data)
{
    m_calculator->calc(data, m_minX, m_minY, m_maxX, m_maxY);
}


void FractalDrawer::changeRange(qreal minX, qreal minY, qreal maxX, qreal maxY)
{
    if(minX < maxX && minY < maxY)
    {
        m_minX = minX;
        m_minY = minY;
        m_maxX = maxX;
        m_maxY = maxY;

        emit redrawNeeded();
    }
    emit reloadRange();
}
