#include "SizeSettings.h"

SizeSettings::SizeSettings(QObject *parent) : QObject(parent)
{
#ifdef RASPBERRYPI
    m_isFullScreen = true;

    m_windowWidth = 640;
    m_windowHeight = 480;

    m_canvasWidth = 480;
    m_canvasHeight = 480;
#else
    m_isFullScreen = false;

    m_windowWidth = 1280;
    m_windowHeight = 960;

    m_canvasWidth = 960;
    m_canvasHeight = 960;
#endif
}
