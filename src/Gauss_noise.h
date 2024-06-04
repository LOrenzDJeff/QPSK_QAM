#ifndef GAUSS_NOISE_H
#define GAUSS_NOISE_H

#include <iostream>
#include <vector>
#include <complex>
#include <random>

using namespace std;

class noise
{
    public:
    /**
     * \brief На вход подаётся значение дисперсии, длина битов, мат ожидание и QAM
     * \return Возвращает QAM с шумом
    */
        vector<complex<double>> Gauss_noise(double disp, int numSamples, vector<complex<double>>qpsk, double mean);
        void set_dispersion(double Disp);
        void set_mean(double Mean);
        double get_dispersion();
        double get_mean();
    private:
        double disp;
        double mean;
};

#endif