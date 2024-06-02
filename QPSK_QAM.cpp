#include <iostream>
#include <ctime>
#include <vector>
#include <complex>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;

vector<complex<double>> QPSK(int len_bits, vector<int> bits) {
    vector<complex<double>> QPSK_table;
    for  (int i  =  0; i  < len_bits; i = i + 2)
    {
        if (bits[i + 1] == 0 && bits[i] == 0)
        {
            QPSK_table.push_back(complex<double>(1, 1));
        }
        else if (bits[i + 1] == 1 && bits[i] == 0)
        {
            QPSK_table.push_back(complex<double>(1, -1));
        }
        else if (bits[i + 1] == 0 && bits[i] == 1)
        {
            QPSK_table.push_back(complex<double>(-1, 1));
        }
        else
        {
            QPSK_table.push_back(complex<double>(-1, -1));
        }
    }
    return  QPSK_table;
}

vector<complex<double>> noise(double disp, int numSamples, vector<complex<double>>qpsk) {
    vector<complex<double>> qwn;
    double mean = 0;
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

vector<int> demodQPSK(int len_bits, vector<complex<double>> QPSK_with_noise) {
    
    vector<int> new_bits;
    for  (int i  =  0; i  < len_bits; i++)
    {
        if (QPSK_with_noise[i].real()  >  0  && QPSK_with_noise[i].imag()  >  0)
        {
            new_bits.push_back(0);
            new_bits.push_back(0);
        }
        else if (QPSK_with_noise[i].real()  >  0  && QPSK_with_noise[i].imag()  <  0)
        {
            new_bits.push_back(0);
            new_bits.push_back(1);
        }
        else if (QPSK_with_noise[i].real()  <  0  && QPSK_with_noise[i].imag()  >  0)
        {
            new_bits.push_back(1);
            new_bits.push_back(0);
        }
        else
        {
            new_bits.push_back(1);
            new_bits.push_back(1);
        }

    }
    return new_bits;
}

double calculateBER(vector<int> original_bits, vector<int> received_bits) {
    int error_count = 0;
    for (int i = 0; i < original_bits.size(); i++) {
        if (original_bits[i] != received_bits[i]) {
            error_count++;
        }
    }
    return static_cast<double>(error_count) / original_bits.size();
}

int main()
{
    srand(time(0));
    vector<int> bits;
    int num_bits = 100;
    for (int i = 0; i < num_bits; i++)
        bits.push_back(rand()%2);

    vector<complex<double>> QPSK_table;
    QPSK_table = QPSK(num_bits, bits);

    vector<complex<double>> qpskwithnoise;
    vector<int> return_bits;

    vector<double> dispersions;
    vector<double> ber_values;

    ofstream outFile("ber_data.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (float j  =  0; j  <  1; j = j + 0.1)
    {
        qpskwithnoise = noise(j, num_bits / 2, QPSK_table);
        return_bits = demodQPSK(num_bits, qpskwithnoise);
        double ber = calculateBER(bits, return_bits);
        dispersions.push_back(j);
        ber_values.push_back(ber);
        outFile << j << " " << ber << endl;
        cout << "Dispersion: " << j << ", BER: " << ber << endl;
    }

    outFile.close();
    return 0;
}