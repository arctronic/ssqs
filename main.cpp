#include <iostream>
#include "exponential_random_generator.h"

int main()
{
    ExponentialRandom *number = new ExponentialRandom();
    number->SetMean(5);
    double temp = 0.0f;
    for (int i = 0; i < 10000; i++)
    {
        temp += number->RandomNumber();
    }
    std::cout<<temp/10000.0;
}