#ifndef FRACTALDRAWER_H
#define FRACTALDRAWER_H

#include <QObject>

#include "CalcFractalBase.h"
#include "CalcMandelbrot.h"

class FractalDrawer : public QObject
{
    Q_OBJECT

public:
    FractalDrawer(int width, int height);
    ~FractalDrawer();

    Q_PROPERTY(qreal minX READ getMinX WRITE setMinX NOTIFY reloadRange)
    Q_PROPERTY(qreal minY READ getMinY WRITE setMinY NOTIFY reloadRange)
    Q_PROPERTY(qreal maxX READ getMaxX WRITE setMaxX NOTIFY reloadRange)
    Q_PROPERTY(qreal maxY READ getMaxY WRITE setMaxY NOTIFY reloadRange)

    Q_INVOKABLE void zoomOut() { changeRange(m_minX*2, m_minY*2, m_maxX*2, m_maxY*2); }
    Q_INVOKABLE void zoomIn() { changeRange(m_minX/2, m_minY/2, m_maxX/2, m_maxY/2); }

    Q_INVOKABLE void resetRange() { changeRange(-2.0, -2.0, 2.0, 2.0); }
    Q_INVOKABLE void changeRange(qreal minX, qreal minY, qreal maxX, qreal maxY);

    Q_INVOKABLE qreal getRe(int value) { return (m_minX + (value * (m_maxX - m_minX) / m_canvasWidth)); }
    Q_INVOKABLE qreal getIm(int value) { return (m_minY + (value * (m_maxY - m_minY) / m_canvasHeight)); }

    void setImageBitmap(unsigned char* data);

    void setMinX(qreal value) { changeRange(value, m_minY, m_maxX, m_maxY); }
    void setMinY(qreal value) { changeRange(m_minX, value, m_maxX, m_maxY); }
    void setMaxX(qreal value) { changeRange(m_minX, m_minY, value, m_maxY); }
    void setMaxY(qreal value) { changeRange(m_minX, m_minY, m_maxX, value); }

    qreal getMinX() { return m_minX; }
    qreal getMinY() { return m_minY; }
    qreal getMaxX() { return m_maxX; }
    qreal getMaxY() { return m_maxY; }


signals:
    void redrawNeeded();
    void reloadRange();

private:
    int m_canvasWidth;
    int m_canvasHeight;
    CalcFractalBase *m_calculator;

    qreal m_minX, m_minY, m_maxX, m_maxY;
};

#endif // FRACTALDRAWER_H
