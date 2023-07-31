#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    Stopwatch(QObject* parent = nullptr);

    bool isRunning() const;
    void resetLapTime();
    void start();
    void stop();
    void reset();
    int lapTime() const;
    int totalTime() const;

signals:
    void lapTimeChanged(int lapTime);
    void totalTimeChanged(int totalTime);

private slots:
    void tick();

private:
    QTimer m_timer;
    int m_lapTime;
    int m_totalTime;
};

#endif // STOPWATCH_H
