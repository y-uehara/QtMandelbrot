#ifndef FRACTALIMAGEPROVIDER_H
#define FRACTALIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QPixmap>

#include "FractalDrawer.h"

class FractalImageProvider : public QQuickImageProvider
{
public:
    FractalImageProvider(FractalDrawer *drawer, int width, int height);
    ~FractalImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) Q_DECL_OVERRIDE;

private:
    int m_canvasWidth;
    int m_canvasHeight;
    unsigned char *m_data;

    FractalDrawer *m_drawer;
};

#endif // FRACTALIMAGEPROVIDER_H
