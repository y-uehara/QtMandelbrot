#include "FractalImageProvider.h"

FractalImageProvider::FractalImageProvider(FractalDrawer *drawer, int width, int height) :
    QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    m_canvasWidth = width;
    m_canvasHeight = height;

    m_data = new unsigned char[m_canvasWidth * m_canvasHeight * 4];
    m_drawer = drawer;
}

FractalImageProvider::~FractalImageProvider()
{
    delete [] m_data;
}

QPixmap FractalImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);
    Q_UNUSED(requestedSize);

    *size = QSize(m_canvasWidth, m_canvasHeight);

    m_drawer->setImageBitmap(m_data);

    QImage drawnImage(m_data, m_canvasWidth, m_canvasHeight, QImage::Format_ARGB32);

    return QPixmap::fromImage(drawnImage);
}
