#!/bin/bash

c++ QPSK_QAM.cc table.cc -o QPSK_QAM
./QPSK_QAM
python3 graph.py