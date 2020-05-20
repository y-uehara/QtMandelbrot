#include "SizeSettings.h"

SizeSettings::SizeSettings(QObject *parent) : QObject(parent)
{
#ifdef RASPBERRYPI
    m_window_width = 640;
    m_window_height = 480;

    m_canvas_width = 480;
    m_canvas_height = 480;
#else
    m_window_width = 1280;
    m_window_height = 960;

    m_canvas_width = 960;
    m_canvas_height = 960;
#endif
}
