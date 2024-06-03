/*
 * Эта программа является выполнением задания по модуляции и демодуляции
 * QAM (QPSK, QAM16, QAM64). А также для сохранения среднего значения
 * BER для каждой QAM, в дальнейшем для построения графиков.
 * 
 * Автор: Бабенко Денис Максимович<dmbabenko9@gmail.com>
 */


#ifndef QPSK_QAM_H
#define QPSK_QAM_H

#include <iostream>
#include <ctime>
#include <vector>
#include <complex>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;


/**
 * Данные значения были взяты из книги ETSI TS 138 211 V16.2.0 (2020-07)
 * На странице номер 17
 */
#define QPSK_LEVEL (1.0 / sqrt(2.0))

#define QAM16_LEVEL_1  (1.0f / sqrt(10.0f))
#define QAM16_LEVEL_2  (3.0f / sqrt(10.0f))

#define QAM64_LEVEL_1  (1.0f  / sqrt(42.0f))
#define QAM64_LEVEL_2  (3.0f  / sqrt(42.0f))
#define QAM64_LEVEL_3  (5.0f  / sqrt(42.0f))
#define QAM64_LEVEL_4  (7.0f  / sqrt(42.0f))

/**
 * Данный класс хранит в себе комплексные числа для дальнейшего преобразования
 * из десятичных целых чисел в комплексные числа, в соответвии с QAM 
*/
class QAM_table
{
    public:
        complex<double>* QPSKt();
        complex<double>* QAM16t();
        complex<double>* QAM64t();
};

/**
 * Данный класс производит модуляцию QAM 
*/
class QAMmod 
{
    public:
        vector<complex<double>> QPSK(int len_bits, vector<int> bits);
        vector<complex<double>> QAM16(int len_bits, vector<int> bits);
        vector<complex<double>> QAM64(int len_bits, vector<int> bits);
};

class noise
{
    public:
        vector<complex<double>> haus_noise(double disp, int numSamples, vector<complex<double>>qpsk);
};

class QAMdemod
{
    public:
        vector<int> demodQPSK(int len_bits, vector<complex<double>> QPSK_with_noise);
        vector<int> demodQAM16(int len_bits, vector<complex<double>> QPSK_with_noise);
        vector<int> demodQAM64(int len_bits, vector<complex<double>> QPSK_with_noise);
};

#endif