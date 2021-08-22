#include "simulation.h"
#include "stat.h"
#include <iomanip>
Simulation::Simulation(double inter_arrival, double service_mean, int num_customers)
{
    this->inter_arrivale_time_mean = inter_arrival;
    this->service_time_mean = service_mean;
    this->number_of_customers = num_customers;
    this->numOfLines = 0;
    this->interArrivalTimeGenerator.SetMean(this->inter_arrivale_time_mean);
    this->serviceTimeGenerator.SetMean(this->service_time_mean);
    this->stat.totalCustomer = num_customers;
    this->server.setServerStatus(ServerStatus::IDLE);
    this->numsOfServer = 2;
    this->servers.resize(2);
}

void Simulation::init()
{

    this->systemClock = 0.0f;
    this->server.setServerStatus(ServerStatus::IDLE);
    this->numOfLines = 0;
    // now the program need to schedule an arrival event
    Event arrival_event(EventType::ARRIVAL, this->systemClock + this->interArrivalTimeGenerator.RandomNumber());
    this->event_queue.push(arrival_event);
    for (int i = 0; i < this->numsOfServer; i++)
    {
        this->servers[i].setServerStatus(ServerStatus::IDLE);
    }
}

void Simulation::entryLog(std::string eventType, double _time, int serial)
{
    std::cout << std::setw(2) << ++this->numOfLines << "\t" << std::setw(8) << eventType << "\t" << std::setw(8) << _time << "\t" << std::setw(10) << serial << "\t" << std::setw(15) << (this->server.getServerStatus() == ServerStatus::IDLE ? "Idle" : "Busy") << "\t" << std::setw(12) << this->service_queue.size() << "\t";
    for (int i = 0; i < numsOfServer; i++)
    {
        std::cout << (this->servers[i].getServerStatus() == ServerStatus::IDLE ? "Idle" : "Busy") << "\t";
        std::string status = this->servers[i].getServerStatus() == ServerStatus::IDLE ? "Idle" : "Busy";
        StatVar temp(eventType, _time, serial, status, this->service_queue.size());
        this->stat.pushRecord(temp);
    }
    std::cout << "\n";
}

void Simulation::updateTime(double _time)
{
    this->systemClock = _time;
}

void Simulation::Run()
{
    while (!(this->event_queue.empty()))
    {
        Event currentevent = this->event_queue.top();
        this->event_queue.pop();
        updateTime(currentevent.getInvokeTime());

        if (currentevent.getEventType() == EventType::ARRIVAL)
        {
            HandleArrival();
        }
        else if (currentevent.getEventType() == EventType::DEPARTURE)
        {
            HandleDepart();
        }
    }
    this->stat.totalSimulationTime = this->systemClock;
    this->stat.generateStat();
}

void Simulation::HandleArrival()
{
    Customer customer(this->systemClock);
    if (this->number_of_customers > Customer::getTotalCustomer())
    {
        double _time = this->systemClock + this->interArrivalTimeGenerator.RandomNumber();
        Event arrival_event(EventType::ARRIVAL, _time);
        this->event_queue.push(arrival_event);
    }
    int flag = 0;
    for (int i = 0; i < this->numsOfServer; i++)
    {
        if (this->servers[i].getServerStatus() == ServerStatus::IDLE)
        {
            entryLog("Arrival", this->systemClock, customer.getSerial());

            this->currently_serving = customer;
            this->currently_serving.server_no = i;

            this->servers[i].setServerStatus(ServerStatus::BUSY);

            double _time = this->systemClock + this->serviceTimeGenerator.RandomNumber();
            Event depart_event(EventType::DEPARTURE, _time);
            this->event_queue.push(depart_event);
            entryLog(i==0? "Service0":"Service1", this->systemClock, customer.getSerial());
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        this->service_queue.push(customer);
        entryLog("Arrival", this->systemClock, customer.getSerial());
    }
}

void Simulation::HandleDepart()
{
    this->servers[this->currently_serving.server_no].setServerStatus(ServerStatus::IDLE);
    int idx = this->currently_serving.server_no;
    entryLog("Departure", this->systemClock, this->currently_serving.getSerial());
    if (!(this->service_queue.empty()))
    {
        Customer customer = service_queue.front();

        this->service_queue.pop();
        for (int i = 0; i < this->numsOfServer; i++)
        {
            if (this->servers[i].getServerStatus() == ServerStatus::IDLE)
            {
                this->servers[i].setServerStatus(ServerStatus::BUSY);
                customer.server_no = i;
                this->currently_serving = customer;
                this->currently_serving.server_no=i;
                break;
            }
        }
        double _time = this->systemClock + this->serviceTimeGenerator.RandomNumber();
        Event departure(EventType::DEPARTURE, _time);
        this->event_queue.push(departure);

        entryLog("Service", this->systemClock, currently_serving.getSerial());
    }
}