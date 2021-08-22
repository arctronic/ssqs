#include <random>
#include "exponential_random_generator.h"

ExponentialRandom::ExponentialRandom()
{
    // creating an instance of generator for random number
    this->generator = std::mt19937_64(this->rand_device());
    // returns a random number between 0,1 (floating)
    this->uniform_random_distribution = std::uniform_real_distribution<double>(0, 1);
}

void ExponentialRandom::SetMean(double _mean)
{
    this->mean = _mean;
}

double ExponentialRandom::RandomNumber()
{
    double exp_rand = -log(this->uniform_random_distribution(this->generator)) * this->mean;
    return exp_rand;
}