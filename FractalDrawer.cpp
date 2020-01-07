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

void FractalDrawer::updateImageAndNotify()
{
    if(m_calculator)
        delete m_calculator;

    m_calculator = new CalcMandelbrot(960, 960, m_minX, m_minY, m_maxX, m_maxY);

    emit redrawNeeded();
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


void FractalDrawer::changeRange(qreal minX, qreal minY, qreal maxX, qreal maxY)
{
    if(minX < maxX && minY < maxY)
    {
        m_minX = minX;
        m_minY = minY;
        m_maxX = maxX;
        m_maxY = maxY;

        updateImageAndNotify();
    }
    emit reloadRange();
}
