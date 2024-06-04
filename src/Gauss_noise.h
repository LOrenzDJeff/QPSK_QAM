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
     * \brief функция для наложения шума
     * \param Дисперсия
     * \param Длина битов
     * \param Вектор QAM
     * \param Матожидание
     * \return Возвращает QAM с шумом
    */
        vector<complex<double>> Gauss_noise(double disp, int numSamples, vector<complex<double>>QAM, double mean);
    /**
     * \param сетер дисперсии
    */
        void set_dispersion(double Disp);
    /**
     * \param сетер мат ожидания
    */
        void set_mean(double Mean);
    /**
     * \return гетер дисперсии
    */    
        double get_dispersion();
    /**
     * \return гетер мат ожидания
    */ 
        double get_mean();
    private:
        double disp;
        double mean;
};

#endif