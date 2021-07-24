#include "customer.h"

Customer::Customer() {}
Customer::Customer(double arrival_time)
{
    this->counter++;
    this->arrival_time = arrival_time;
    this->serial = this->counter;
}

int Customer::getSerial()
{
    return this->serial;
}

int Customer::getTotalCustomer()
{
    return Customer::counter;
}