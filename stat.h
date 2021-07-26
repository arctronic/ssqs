#ifndef STAT_H
#define STAT_H

class Stat
{
private:
    double totalDelay;
    double totalServerIdle;
    double totalQueueLen;
    double totalServiceTime;
    double totalInterArrival;
    double totalSimulationTime;


public:
    Stat();

    void SetTotalDelay(double time);
    void SetTotalServerIdle(double time);
    void SetTotalQueueLen(double time);
    void SetTotalServiceTime(double time);
    void SetTotalInterArrival(double time);
    void SetTotalSimulationTime(double time);

    
};

#endif