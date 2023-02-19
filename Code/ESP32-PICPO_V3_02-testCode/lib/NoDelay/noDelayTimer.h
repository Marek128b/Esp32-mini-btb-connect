#include <Arduino.h>

class noDelayTimer
{
private:
    unsigned long interval;
    unsigned long lastTime;
    bool isStopped = false;

public:
    noDelayTimer(unsigned long interval);
    void setInterval(unsigned long interval);
    void startTimer();
    bool isTriggered();
    void stopTimer();
    void continueTimer();
};

noDelayTimer::noDelayTimer(unsigned long interval)
{
    this->interval = interval;
}

void noDelayTimer::setInterval(unsigned long interval)
{
    this->interval = interval;
}

void noDelayTimer::startTimer()
{
    lastTime = millis();
}

bool noDelayTimer::isTriggered()
{
    if (!isStopped)
    {
        if (millis() - lastTime >= interval)
        {
            lastTime = millis();

            return true;
        }
    }
    return false;
}

void noDelayTimer::stopTimer()
{
    isStopped = true;
}

void noDelayTimer::continueTimer()
{
    isStopped = false;
    lastTime = millis();
}