#include "customer.h"

int Customer::total = 0;

Customer::Customer() {}
Customer::Customer(double arrival_time)
{
    this->total++;
    this->arrival_time = arrival_time;
    this->serial = this->total;
    this->server_no = 0;
}

int Customer::getSerial()
{
    return this->serial;
}

int Customer::getTotalCustomer()
{
    return Customer::total;
}