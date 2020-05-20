#ifndef SIZESETTINGS_H
#define SIZESETTINGS_H

#include <QObject>

class SizeSettings : public QObject
{
    Q_OBJECT
public:
    explicit SizeSettings(QObject *parent = nullptr);

    Q_INVOKABLE int getWindowWidth() { return m_window_width; }
    Q_INVOKABLE int getWindowHeight() { return m_window_height; }
    Q_INVOKABLE int getCanvasWidth() { return m_canvas_width; }
    Q_INVOKABLE int getCanvasHeight() { return m_canvas_height; }


signals:


private:
    int m_window_width;
    int m_window_height;

    int m_canvas_width;
    int m_canvas_height;
};

#endif // SIZESETTINGS_H
