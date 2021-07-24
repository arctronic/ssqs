#include "event.h"

Event::Event(EventType type, double invocking_time)
{
    this->invocking_time = invocking_time;
    this->type = type;
}

double Event::getInvokeTime()
{
    return this->invocking_time;
}

void Event::setType(EventType e)
{
    this->type = e;
}

EventType Event::getEventType()
{
    return this->type;
}

bool Compare::operator()(Event a, Event b)
{
    if (a.getInvokeTime() > b.getInvokeTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}
