#include "Gauss_noise.h"

vector<complex<double>> noise::Gauss_noise(double disp, int lenQAM, vector<complex<double>> QAM, double mean) {
    vector<complex<double>> qwn;
    double stddev = sqrt(disp);
    
    random_device rd;
    mt19937 gen(rd());
    
    normal_distribution<> dist(mean, stddev);

    for (int i = 0; i < lenQAM; ++i) {
        double real_part = dist(gen);
        double imag_part = dist(gen);
        complex<double> sample(real_part, imag_part);
        QAM[i] += sample;
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
