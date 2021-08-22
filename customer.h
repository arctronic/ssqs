#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
    double arrival_time;
    int serial;
    static int total;

public:
    Customer();
    int server_no;
    Customer(double arrival_time);
    int getSerial();
    
    static int getTotalCustomer();
};

#endif