#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

enum class EventType
{
    ARRIVAL,
    DEPARTURE
};

class Event
{
private:
    EventType type;
    double invocking_time;

public:
    Event(EventType type, double invoke_time);
    void setType(EventType e);
    EventType getEventType();
    double getInvokeTime();
};

class Compare{
    public:
        bool operator()(Event a, Event b);
};

#endif