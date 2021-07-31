#include "stat.h"
#include <stdio.h>

StatVar::StatVar(std::string type, double currentTime, int customerID, std::string status, int qlen)
{
    this->type = type;
    this->currentTime = currentTime;
    this->customerID = customerID;
    this->qlen = qlen;
    this->status = status;
}
Stat::Stat() {}
void Stat::pushRecord(StatVar statHolder)
{
    this->holder.push_back(statHolder);
}

void Stat::generateStat()
{
    for (int i = 0; i < this->holder.size(); i++)
    {
        for (int j = i + 1; j < this->holder.size() - 1; j++)
        {
            if (this->holder[i].type == holder[j].type && holder[j].type == "Arrival")
            {
                double delta = holder[j].currentTime - holder[i].currentTime;
                this->totalInterArrivalTime += delta;
                i = j;
            }
        }
    }

    for (int i = 1; i < totalCustomer + 1; i++)
    {
        double t1 = 0.0;
        double t2 = 0.0;
        for (int j = 0; j < holder.size(); j++)
        {
            if (holder[j].customerID == i && holder[j].type == "Service")
            {
                t1 = holder[j].currentTime;
            }
        }
        for (int j = 0; j < holder.size(); j++)
        {
            if (holder[j].customerID == i && holder[j].type == "Departure")
            {
                t2 = holder[j].currentTime;
            }
        }
        double delta = t2 - t1;
        totalServiceTime += delta;
    }

    int delayCounter = 0;
    for (int i = 0; i < holder.size(); i++)
    {
        totalQueueLength += holder[i].qlen;
        if (holder[i].qlen != 0)
        {
            delayCounter++;
        }
    }
  

    for (int i = 0; i < this->holder.size(); i++)
    {
        for (int j = i + 1; j < this->holder.size() - 1; j++)
        {
            if (this->holder[i].type == "Arrival" && this->holder[j].type == "Service" && holder[j].customerID == this->holder[i].customerID)
            {
                double delta = this->holder[j].currentTime - this->holder[i].currentTime;
                if (delta > 0.0)
                {
                    this->totalQueueDelay += delta;
                }
                i = j;
            }
        }
    }

    printf("Total customer: %d\n",this->totalCustomer);
    printf("Total simulation time: %lf\n",this->totalSimulationTime);
    printf("avg Inter arrival: %lf\n", this->totalInterArrivalTime / ((double)this->totalCustomer));
    printf("avg service time: %lf\n", this->totalServiceTime / this->totalCustomer);
    printf("avg queue delay: %lf\n", this->totalQueueDelay / (double)delayCounter);
    printf("avg queue len: %lf\n", this->totalQueueLength / (3 * totalCustomer));
    printf("total utilization: %lf\n", 100 * (totalServiceTime / totalSimulationTime));
}