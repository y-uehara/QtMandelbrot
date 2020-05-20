#include "SizeSettings.h"

SizeSettings::SizeSettings(QObject *parent) : QObject(parent)
{
    m_window_width = 1280;
    m_window_height = 960;

    m_canvas_width = 960;
    m_canvas_height = 960;
}
