#include "simulation.h"

Simulation::Simulation(double inter_arrival, double service_mean, int num_customers)
{
    this->inter_arrivale_time_mean = inter_arrival;
    this->service_time_mean = service_mean;
    this->number_of_customers = num_customers;

    this->interArrivalTimeGenerator.SetMean(this->inter_arrivale_time_mean);
    this->serviceTimeGenerator.SetMean(this->service_time_mean);
}

void Simulation::init()
{
    this->systemClock = 0.0f;
    this->server_status = ServerStatus::IDLE;

    // now the program need to schedule an arrival event
    Event arrival_event(EventType::ARRIVAL, this->systemClock + this->interArrivalTimeGenerator.RandomNumber());
    this->event_queue.push(arrival_event);
}

void Simulation::Run()
{
    while (!(this->event_queue.empty()))
    {
        Event currentevent = this->event_queue.top();
        this->event_queue.pop();
        updateTime(currentevent.getInvokeTime());

        if(currentevent.getEventType()==EventType::ARRIVAL){
            HandleArrival();
        }else if(currentevent.getEventType()==EventType::DEPARTURE){
            HandleDepart();
        }
    }
}