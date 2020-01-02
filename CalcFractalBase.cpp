#include "CalcFractalBase.h"

CalcFractalBase::CalcFractalBase(int pixelWidth, int pixelHeight, double minX, double minY, double maxX, double maxY) :
    m_pixelWidth(pixelWidth),
    m_pixelHeight(pixelHeight),
    m_minX(minX),
    m_minY(minY),
    m_maxX(maxX),
    m_maxY(maxY)
{

}

CalcFractalBase::~CalcFractalBase()
{

}
