#ifndef FRACTALDRAWER_H
#define FRACTALDRAWER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QPixmap>

#include "CalcFractalBase.h"
#include "CalcMandelbrot.h"

// QObject must be inherit at first!!
class FractalDrawer : public QObject, public QQuickImageProvider
{
    Q_OBJECT

public:
    FractalDrawer();
    ~FractalDrawer();

    Q_PROPERTY(qreal minX READ getMinX WRITE setMinX NOTIFY redrawNeeded)
    Q_PROPERTY(qreal minY READ getMinY WRITE setMinY NOTIFY redrawNeeded)
    Q_PROPERTY(qreal maxX READ getMaxX WRITE setMaxX NOTIFY redrawNeeded)
    Q_PROPERTY(qreal maxY READ getMaxY WRITE setMaxY NOTIFY redrawNeeded)

    Q_INVOKABLE void zoomOut();
    Q_INVOKABLE void zoomIn();

    Q_INVOKABLE qreal getRe(int value) { return (m_minX + (value * (m_maxX - m_minX) / 960)); }
    Q_INVOKABLE qreal getIm(int value) { return (m_minY + (value * (m_maxY - m_minY) / 960)); }

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) Q_DECL_OVERRIDE;

    void setMinX(qreal value);
    void setMinY(qreal value);
    void setMaxX(qreal value);
    void setMaxY(qreal value);

    qreal getMinX() { return m_minX; }
    qreal getMinY() { return m_minY; }
    qreal getMaxX() { return m_maxX; }
    qreal getMaxY() { return m_maxY; }


signals:
    void redrawNeeded();


private:
    unsigned char *m_data;
    CalcFractalBase *m_calculator;

    qreal m_minX, m_minY, m_maxX, m_maxY;

    void updateImageAndNotify();

};

#endif // FRACTALDRAWER_H
