#!/bin/bash

c++ QPSK_QAM.cpp -o QPSK_QAM
./QPSK_QAM
python3 graph.py