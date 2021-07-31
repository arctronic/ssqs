#ifndef STAT_H
#define STAT_H
#include <iostream>
#include <bits/stdc++.h>
class StatVar
{
public:
    std::string type;
    double currentTime;
    int customerID;
    std::string status;
    int qlen;
    StatVar(std::string type,double currentTime,int customerID,std::string status,int qlen);
};

class Stat
{
public:
    std::vector<StatVar> holder;
    double totalSimulationTime;
    int totalCustomer;

    double totalInterArrivalTime;
    double totalServiceTime;
    double totalQueueDelay;
    double totalQueueLength;
    double utilization;
    Stat();
    Stat(int totalCustomer);
    void pushRecord(StatVar statHolder);
    void generateStat();
};

#endif