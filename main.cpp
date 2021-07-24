#include <iostream>
#include <ctime>
#include "exponential_random_generator.h"
#include "simulation.h"
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.tsv", "w", stdout);

    std::cout << "No\tEvent Type\tCurrent Time\tCustomer Serial\tServer Status\tQueue Size"<< std::endl;

    int num_of_customers;
    double inter_arrival_mean, service_mean;
    std::cin >> inter_arrival_mean >> service_mean >> num_of_customers;

    Simulation simulation(inter_arrival_mean, service_mean, num_of_customers);
    simulation.init();
    simulation.Run();
    return 0;
}