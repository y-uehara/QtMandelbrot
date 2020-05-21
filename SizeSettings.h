#ifndef SIZESETTINGS_H
#define SIZESETTINGS_H

#include <QObject>

class SizeSettings : public QObject
{
    Q_OBJECT
public:
    explicit SizeSettings(QObject *parent = nullptr);

    Q_INVOKABLE bool isFullScreen() { return m_isFullScreen; }
    Q_INVOKABLE int getWindowWidth() { return m_windowWidth; }
    Q_INVOKABLE int getWindowHeight() { return m_windowHeight; }
    Q_INVOKABLE int getCanvasWidth() { return m_canvasWidth; }
    Q_INVOKABLE int getCanvasHeight() { return m_canvasHeight; }

signals:


private:
    bool m_isFullScreen;

    int m_windowWidth;
    int m_windowHeight;

    int m_canvasWidth;
    int m_canvasHeight;
};

#endif // SIZESETTINGS_H
