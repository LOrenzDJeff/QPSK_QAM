#include "QPSK_QAM.h"

complex<double>* QAM_table::QPSKt()
{
    complex<double>* table = new complex<double>[4];
    table[0] = complex<double>(QPSK_LEVEL, QPSK_LEVEL);
    table[1] = complex<double>(QPSK_LEVEL, -QPSK_LEVEL);
    table[2] = complex<double>(-QPSK_LEVEL, QPSK_LEVEL);
    table[3] = complex<double>(-QPSK_LEVEL, -QPSK_LEVEL);
    return table;
}

complex<double>* QAM_table::QAM16t()
{
    complex<double>* table = new complex<double>[16];
    table[0] = complex<double>(QAM16_LEVEL_1, QAM16_LEVEL_1);
    table[1] = complex<double>(QAM16_LEVEL_1, QAM16_LEVEL_2);
    table[2] = complex<double>(QAM16_LEVEL_2, QAM16_LEVEL_1);
    table[3] = complex<double>(QAM16_LEVEL_2, QAM16_LEVEL_2);
    table[4] = complex<double>(QAM16_LEVEL_1, -QAM16_LEVEL_1);
    table[5] = complex<double>(QAM16_LEVEL_1, -QAM16_LEVEL_2);
    table[6] = complex<double>(QAM16_LEVEL_2, -QAM16_LEVEL_1);
    table[7] = complex<double>(QAM16_LEVEL_2, -QAM16_LEVEL_2);
    table[8] = complex<double>(-QAM16_LEVEL_1, QAM16_LEVEL_1);
    table[9] = complex<double>(-QAM16_LEVEL_1, QAM16_LEVEL_2);
    table[10] = complex<double>(-QAM16_LEVEL_2, QAM16_LEVEL_1);
    table[11] = complex<double>(-QAM16_LEVEL_2, QAM16_LEVEL_2);
    table[12] = complex<double>(-QAM16_LEVEL_1, -QAM16_LEVEL_1);
    table[13] = complex<double>(-QAM16_LEVEL_1, -QAM16_LEVEL_2);
    table[14] = complex<double>(-QAM16_LEVEL_2, -QAM16_LEVEL_1);
    table[15] = complex<double>(-QAM16_LEVEL_2, -QAM16_LEVEL_2);
    return table;
}

complex<double>* QAM_table::QAM64t()
{
    complex<double>* table = new complex<double>[64];
    table[0] = complex<double>(QAM64_LEVEL_2, QAM64_LEVEL_2);
    table[1] = complex<double>(QAM64_LEVEL_2, QAM64_LEVEL_1);
    table[2] = complex<double>(QAM64_LEVEL_1, QAM64_LEVEL_2);
    table[3] = complex<double>(QAM64_LEVEL_1, QAM64_LEVEL_1);
    table[4] = complex<double>(QAM64_LEVEL_2, QAM64_LEVEL_3);
    table[5] = complex<double>(QAM64_LEVEL_2, QAM64_LEVEL_4);
    table[6] = complex<double>(QAM64_LEVEL_1, QAM64_LEVEL_3);
    table[7] = complex<double>(QAM64_LEVEL_1, QAM64_LEVEL_4);
    table[8] = complex<double>(QAM64_LEVEL_3, QAM64_LEVEL_2);
    table[9] = complex<double>(QAM64_LEVEL_3, QAM64_LEVEL_1);
    table[10] = complex<double>(QAM64_LEVEL_4, QAM64_LEVEL_2);
    table[11] = complex<double>(QAM64_LEVEL_4, QAM64_LEVEL_1);
    table[12] = complex<double>(QAM64_LEVEL_3, QAM64_LEVEL_3);
    table[13] = complex<double>(QAM64_LEVEL_3, QAM64_LEVEL_4);
    table[14] = complex<double>(QAM64_LEVEL_4, QAM64_LEVEL_3);
    table[15] = complex<double>(QAM64_LEVEL_4, QAM64_LEVEL_4);
    table[16] = complex<double>(QAM64_LEVEL_2, -QAM64_LEVEL_2);
    table[17] = complex<double>(QAM64_LEVEL_2, -QAM64_LEVEL_1);
    table[18] = complex<double>(QAM64_LEVEL_1, -QAM64_LEVEL_2);
    table[19] = complex<double>(QAM64_LEVEL_1, -QAM64_LEVEL_1);
    table[20] = complex<double>(QAM64_LEVEL_2, -QAM64_LEVEL_3);
    table[21] = complex<double>(QAM64_LEVEL_2, -QAM64_LEVEL_4);
    table[22] = complex<double>(QAM64_LEVEL_1, -QAM64_LEVEL_3);
    table[23] = complex<double>(QAM64_LEVEL_1, -QAM64_LEVEL_4);
    table[24] = complex<double>(QAM64_LEVEL_3, -QAM64_LEVEL_2);
    table[25] = complex<double>(QAM64_LEVEL_3, -QAM64_LEVEL_1);
    table[26] = complex<double>(QAM64_LEVEL_4, -QAM64_LEVEL_2);
    table[27] = complex<double>(QAM64_LEVEL_4, -QAM64_LEVEL_1);
    table[28] = complex<double>(QAM64_LEVEL_3, -QAM64_LEVEL_3);
    table[29] = complex<double>(QAM64_LEVEL_3, -QAM64_LEVEL_4);
    table[30] = complex<double>(QAM64_LEVEL_4, -QAM64_LEVEL_3);
    table[31] = complex<double>(QAM64_LEVEL_4, -QAM64_LEVEL_4);
    table[32] = complex<double>(-QAM64_LEVEL_2, QAM64_LEVEL_2);
    table[33] = complex<double>(-QAM64_LEVEL_2, QAM64_LEVEL_1);
    table[34] = complex<double>(-QAM64_LEVEL_1, QAM64_LEVEL_2);
    table[35] = complex<double>(-QAM64_LEVEL_1, QAM64_LEVEL_1);
    table[36] = complex<double>(-QAM64_LEVEL_2, QAM64_LEVEL_3);
    table[37] = complex<double>(-QAM64_LEVEL_2, QAM64_LEVEL_4);
    table[38] = complex<double>(-QAM64_LEVEL_1, QAM64_LEVEL_3);
    table[39] = complex<double>(-QAM64_LEVEL_1, QAM64_LEVEL_4);
    table[40] = complex<double>(-QAM64_LEVEL_3, QAM64_LEVEL_2);
    table[41] = complex<double>(-QAM64_LEVEL_3, QAM64_LEVEL_1);
    table[42] = complex<double>(-QAM64_LEVEL_4, QAM64_LEVEL_2);
    table[43] = complex<double>(-QAM64_LEVEL_4, QAM64_LEVEL_1);
    table[44] = complex<double>(-QAM64_LEVEL_3, QAM64_LEVEL_3);
    table[45] = complex<double>(-QAM64_LEVEL_3, QAM64_LEVEL_4);
    table[46] = complex<double>(-QAM64_LEVEL_4, QAM64_LEVEL_3);
    table[47] = complex<double>(-QAM64_LEVEL_4, QAM64_LEVEL_4);
    table[48] = complex<double>(-QAM64_LEVEL_2, -QAM64_LEVEL_2);
    table[49] = complex<double>(-QAM64_LEVEL_2, -QAM64_LEVEL_1);
    table[50] = complex<double>(-QAM64_LEVEL_1, -QAM64_LEVEL_2);
    table[51] = complex<double>(-QAM64_LEVEL_1, -QAM64_LEVEL_1);
    table[52] = complex<double>(-QAM64_LEVEL_2, -QAM64_LEVEL_3);
    table[53] = complex<double>(-QAM64_LEVEL_2, -QAM64_LEVEL_4);
    table[54] = complex<double>(-QAM64_LEVEL_1, -QAM64_LEVEL_3);
    table[55] = complex<double>(-QAM64_LEVEL_1, -QAM64_LEVEL_4);
    table[56] = complex<double>(-QAM64_LEVEL_3, -QAM64_LEVEL_2);
    table[57] = complex<double>(-QAM64_LEVEL_3, -QAM64_LEVEL_1);
    table[58] = complex<double>(-QAM64_LEVEL_4, -QAM64_LEVEL_2);
    table[59] = complex<double>(-QAM64_LEVEL_4, -QAM64_LEVEL_1);
    table[60] = complex<double>(-QAM64_LEVEL_3, -QAM64_LEVEL_3);
    table[61] = complex<double>(-QAM64_LEVEL_3, -QAM64_LEVEL_4);
    table[62] = complex<double>(-QAM64_LEVEL_4, -QAM64_LEVEL_3);
    table[63] = complex<double>(-QAM64_LEVEL_4, -QAM64_LEVEL_4);
    return table;
}
