#include "QPSK_QAM.h"

void QAMmod::QPSK(int len_bits, vector<int>& bits, vector<complex<double>>& QPSK_mod, vector<complex<double>>& table, int bit) {
    int Zqpsk;
    vector<int> cache(bit);
    QPSK_mod.reserve(len_bits / bit);
    for (int i = 0; i < len_bits; i += bit)
    {
        for (int j = i; j < i + bit; j++)
            cache[j - i] = bits[j];
        Zqpsk = cache[0] * 2 + cache[1];
        QPSK_mod.push_back(table[Zqpsk]);
    }
}

/*vector<complex<double>> QAMmod::QAM16(int len_bits, vector<int> bits) {
    int num_qam16;
    vector<complex<double>> QAM16_Mod;
    QAM_table QAM16_table;
    complex<double>* table = QAM16_table.QAM16t();
    for (int i = 0; i < len_bits; i += 4)
    {
        int cache[4];
        for (int j = i; j < i + 4; j++)
            cache[j - i] = bits[j];
        num_qam16 = cache[0] * 8 + cache[1] * 4 + cache[2] * 2 + cache[3];
        QAM16_Mod.push_back(table[num_qam16]);
    }
    return QAM16_Mod;
}

vector<complex<double>> QAMmod::QAM64(int len_bits, vector<int> bits) {
    int num_qam64;
    vector<complex<double>> QAM64_Mod;
    QAM_table QAM64_table;
    complex<double>* table = QAM64_table.QAM64t();
    for (int i = 0; i < len_bits; i += 6)
    {
        int cache[6];
        for (int j = i; j < i + 6; j++)
            cache[j - i] = bits[j];
        num_qam64 = cache[0] * 32 + cache[1] * 16 + cache[2] * 8 + cache[3] * 4 + cache[4] * 2 + cache[5];
        QAM64_Mod.push_back(table[num_qam64]);
    }
    return QAM64_Mod;
}
*/
vector<int> QAMdemod::demodQPSK(int len_bits, vector<complex<double>>& QPSK_with_noise, vector<complex<double>>& table, int bit) {    
    vector<int> new_bits;
    double mindistance;
    int bitdis;
    for (int i = 0; i < len_bits / bit; i++) 
    {
        double distance;
        mindistance = abs(table[0] - QPSK_with_noise[i]);
        bitdis = 0;
        for (int j = 1; j < bit ^ 2; j++)  
        {
            distance = abs(table[j] - QPSK_with_noise[i]);
            if (distance  <  mindistance)
            {
                mindistance = distance;
                bitdis = j;
            }
        }
        vector<int> cache;
        for (int j = 0; j < 2; j++)
        {
            cache.push_back(bitdis % 2);
            bitdis = bitdis / 2;
        }
        for (auto j = cache.rbegin(); j != cache.rend(); ++j)
        {
            new_bits.push_back(*j);
        }
    }
    return new_bits;
}
/*
vector<int> QAMdemod::demodQAM16(int len_bits, vector<complex<double>> QAM16_with_noise) {    
    vector<int> new_bits;
    QAM_table QAM16_table;
    complex<double>* table = QAM16_table.QAM16t();
    double mindistance;
    int bitdis;
    for (int i = 0; i < len_bits / 4; i++) 
    {
        double distance;
        mindistance = abs(table[0] - QAM16_with_noise[i]);
        bitdis = 0;
        for (int j = 1; j < 16; j++)
        {
            distance = abs(table[j] - QAM16_with_noise[i]);
            if (distance  <  mindistance)
            {
                mindistance = distance;
                bitdis = j;
            }
        }
        vector<int> cache;
        for (int j = 0; j < 4; j++)
        {
            cache.push_back(bitdis % 2);
            bitdis = bitdis / 2;
        }
        for (auto j = cache.rbegin(); j != cache.rend(); ++j)
        {
            new_bits.push_back(*j);
        }
    }
    return new_bits;
}

vector<int> QAMdemod::demodQAM64(int len_bits, vector<complex<double>> QAM64_with_noise) {    
    vector<int> new_bits;
    QAM_table QAM64_table;
    complex<double>* table = QAM64_table.QAM64t();
    double mindistance;
    int bitdis;
    for (int i = 0; i < len_bits / 6; i++) 
    {
        double distance;
        mindistance = abs(table[0] - QAM64_with_noise[i]);
        bitdis = 0;
        for (int j = 1; j < 64; j++)
        {
            distance = abs(table[j] - QAM64_with_noise[i]);
            if (distance  <  mindistance)
            {
                mindistance = distance;
                bitdis = j;
            }
        }
        vector<int> cache;
        for (int j = 0; j < 6; j++)
        {
            cache.push_back(bitdis % 2);
            bitdis = bitdis / 2;
        }
        for (auto j = cache.rbegin(); j != cache.rend(); ++j)
        {
            new_bits.push_back(*j);
        }
    }
    return new_bits;
}
*/
// Функция для суммы ошибок на бит
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
    QAMtable QAM_table;
    vector<complex<double>> tableQPSK;
    int bitQPSK = 2;
    QAM_table.QPSK_formul(tableQPSK, bitQPSK);
    QAMmod QAM_modulate;
    noise make_some_noise;
    QAMdemod QAM_demodulate;
    srand(time(0));
    int len_bits = 240;
    vector<int> bits;
    for (int i  =  0; i  < len_bits; i++)  
    {
        bits.push_back(rand() % 2);
        cout << bits[i];
    }
    cout << endl;

    vector<complex<double>> QPSK_table;
    QAM_modulate.QPSK(len_bits, bits, QPSK_table, tableQPSK, bitQPSK);
    
    vector<double> global_ber(10);
    for (int i = 0; i < 1000; i++)
    {
        for (float j  =  0; j  <  1; j = j + 0.1)
        {
            vector<complex<double>> QPSK_with_noise = make_some_noise.Gauss_noise(j, len_bits / bitQPSK, QPSK_table, 0);
            vector<int> return_bits  =  QAM_demodulate.demodQPSK(len_bits, QPSK_with_noise, tableQPSK, bitQPSK);
        }

    }
    //vector<complex<double>> QAM16_table = QAM_modulate.QAM16(num_bits, bits);
    //vector<complex<double>> QAM64_table = QAM_modulate.QAM64(num_bits, bits);

    /*
    vector<double> ber_values;

    double global_ber[10], global_ber_16[10], global_ber_64[10];
    for  (int i  =  0; i  < 10; i++)
    {
        global_ber[i] = 0;
        global_ber_16[i] = 0;
        global_ber_64[i] = 0;
    }

    for (int i = 0; i < 1000; i++)
    {
        for (float j  =  0; j  <  1; j = j + 0.1)
        {
            vector<complex<double>> QPSK_with_noise = make_some_noise.Gauss_noise(j, num_bits, QPSK_table, 0);
            vector<complex<double>> QAM16_with_noise = make_some_noise.Gauss_noise(j, num_bits, QAM16_table, 0);
            vector<complex<double>> QAM64_with_noise = make_some_noise.Gauss_noise(j, num_bits, QAM64_table, 0);

            vector<int> return_bits  =  QAM_demodulate.demodQPSK(num_bits, QPSK_with_noise);
            vector<int> return_bits_16  =  QAM_demodulate.demodQAM16(num_bits, QAM16_with_noise);
            vector<int> return_bits_64  =  QAM_demodulate.demodQAM64(num_bits, QAM64_with_noise);

            double ber = calculateBER(bits, return_bits);
            double ber16 = calculateBER(bits, return_bits_16);
            double ber64 = calculateBER(bits, return_bits_64);

            global_ber[int(j * 10)] += ber;
            global_ber_16[int(j * 10)] += ber16;
            global_ber_64[int(j * 10)] += ber64;
        }
    }
    ofstream outFile("ber_data.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    ofstream outFile16("ber_data_16.txt");
    if (!outFile16) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    ofstream outFile64("ber_data_64.txt");
    if (!outFile64) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (float i  =  0; i  <  1; i = i + 0.1)
    {
        outFile << i << " " << global_ber[int(10 * i)] / 1000 << endl;
        outFile16 << i << " " << global_ber_16[int(10 * i)] / 1000 << endl;
        outFile64 << i << " " << global_ber_64[int(10 * i)] / 1000 << endl;

    }

    outFile.close();
    outFile16.close();
    outFile64.close();
*/
    return 0;
}