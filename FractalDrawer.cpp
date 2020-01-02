#include "FractalDrawer.h"

#include <QDebug>

FractalDrawer::FractalDrawer() :
    QObject(),
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    m_minX = -2.0;
    m_minY = -2.0;
    m_maxX = 2.0;
    m_maxY = 2.0;

    m_data = new unsigned char[960 * 960 * 4];
    m_calculator = new CalcMandelbrot(960, 960, m_minX, m_minY, m_maxX, m_maxY);
}

FractalDrawer::~FractalDrawer()
{
    delete [] m_data;
    delete m_calculator;
}

QPixmap FractalDrawer::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);
    Q_UNUSED(requestedSize);

    *size = QSize(960, 960);

    m_calculator->calc(m_data);

    QImage drawnImage(m_data, 960, 960, QImage::Format_ARGB32);

    return QPixmap::fromImage(drawnImage);
}

void FractalDrawer::zoomIn()
{
    m_minX /= 2;
    m_minY /= 2;
    m_maxX /= 2;
    m_maxY /= 2;

    delete m_calculator;
    m_calculator = new CalcMandelbrot(960, 960, m_minX, m_minY, m_maxX, m_maxY);

    emit coordinateChanged();
}

void FractalDrawer::zoomOut()
{
    m_minX *= 2;
    m_minY *= 2;
    m_maxX *= 2;
    m_maxY *= 2;

    delete m_calculator;
    m_calculator = new CalcMandelbrot(960, 960, m_minX, m_minY, m_maxX, m_maxY);

    emit coordinateChanged();
}


void FractalDrawer::setMinX(qreal value)
{
    if(value < m_maxX)
    {
        m_minX = value;
    }
    emit coordinateChanged();
    return;
}

void FractalDrawer::setMinY(qreal value)
{
    if(value < m_maxY)
    {
        m_minY = value;
    }
    emit coordinateChanged();
    return;
}

void FractalDrawer::setMaxX(qreal value)
{
    if(value > m_minX)
    {
        m_maxX = value;
    }
    emit coordinateChanged();
    return;
}

void FractalDrawer::setMaxY(qreal value)
{
    if(value > m_minY)
    {
        m_maxY = value;
    }
    emit coordinateChanged();
    return;
}
