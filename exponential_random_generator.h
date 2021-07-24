#ifndef EXPONENTIAL_RANDOM_GENERATOR_H
#define EXPONENTIAL_RANDOM_GENERATOR_H
#include<random>

class ExponentialRandom{
    private:
        double mean;
        std::random_device rand_device;
        std::mt19937_64 generator;

        std::uniform_real_distribution<double> uniform_random_distribution;
    
    public:
        ExponentialRandom();
        void SetMean(double _mean);
        double RandomNumber();
};

/*
    ref: https://en.cppreference.com/w/cpp/numeric/random/exponential_distribution
*/

#endif