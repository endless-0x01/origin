#include "stopwatch.h"

Stopwatch::Stopwatch(QObject* parent) :
    QObject(parent), m_lapTime(0), m_totalTime(0)
{
    m_timer.setInterval(100);
    connect(&m_timer, &QTimer::timeout, this, &Stopwatch::tick);
}

void Stopwatch::start()
{
    m_timer.start();
}

void Stopwatch::stop()
{
    m_timer.stop();
}

void Stopwatch::resetLapTime()
{
    m_lapTime = 0;
    emit lapTimeChanged(m_lapTime);
}

bool Stopwatch::isRunning() const
{
    return m_timer.isActive();
}



void Stopwatch::reset()
{
    m_lapTime = 0;
    m_totalTime = 0;
    emit lapTimeChanged(m_lapTime);
    emit totalTimeChanged(m_totalTime);
}

int Stopwatch::lapTime() const
{
    return m_lapTime;
}

int Stopwatch::totalTime() const
{
    return m_totalTime;
}

void Stopwatch::tick()
{
    m_lapTime += m_timer.interval();
    m_totalTime += m_timer.interval();
    emit lapTimeChanged(m_lapTime);
    emit totalTimeChanged(m_totalTime);
}
