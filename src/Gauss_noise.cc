#include "Gauss_noise.h"

vector<complex<double>> noise::Gauss_noise(double disp, int numSamples, vector<complex<double>>qpsk, double mean) {
    vector<complex<double>> qwn;
    double stddev = std::sqrt(disp);
    
    random_device rd;
    mt19937 gen(rd());
    
    normal_distribution<> dist(mean, stddev);

    for (int i = 0; i < numSamples; ++i) {
        double real_part = dist(gen);
        double imag_part = dist(gen);
        std::complex<double> sample(real_part, imag_part);
        qwn.push_back(qpsk[i] + sample);
    }
    return qwn;
}

void noise::set_dispersion(double Disp)
{
    disp = Disp;
}

double noise::get_dispersion()
{
    return disp;
}

void noise::set_mean(double Mean)
{
    mean = Mean;
}

double noise::get_mean()
{
    return mean;
}
