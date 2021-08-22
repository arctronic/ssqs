#ifndef SIMULATION_H
#define SIMULATION_H

#include <bits/stdc++.h>
#include "customer.h"
#include "event.h"
#include "exponential_random_generator.h"
#include "stat.h"
#include "server.h"
class Simulation
{
private:

    std::vector<Server>servers;

    Server server;

    // it's the clock for the entire system depends in the Event Invokation
    double systemClock;

    // hold the server status BUSY or IDLE
    ServerStatus server_status;

    // Customer that are serving right now
    Customer currently_serving;

    // Customer queue (assuming infinite length)
    std::queue<Customer> service_queue;

    // Priority Queue to keep the event sorted according to the invoke time
    std::priority_queue<Event, std::vector<Event>, Compare> event_queue;

    // this two will be used to generate the inter arrival and service time
    double inter_arrivale_time_mean;
    double service_time_mean;
    int number_of_customers;

    ExponentialRandom interArrivalTimeGenerator;
    ExponentialRandom serviceTimeGenerator;
    Stat stat;

public:
    int numsOfServer;
    int numOfLines;
    // Constructor for the simulation class
    Simulation(double inter_arrival, double service_mean, int num_customers);

    void init();

    // to update the system clock according to the event invoke
    void updateTime(double _time);

    // run the simulation
    void Run();

    // handle arrival event
    void HandleArrival();

    // handle depurture event
    void HandleDepart();

    // write to file
    void entryLog(std::string eventType, double _time, int serial);
};

#endif