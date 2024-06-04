CXX = g++

TARGET = main

SRCS = src/QPSK_QAM.cc src/Table.cc src/Gauss_noise.cc

OBJS = $(SRCS:.cc=.o)

HEADERS = src/QPSK_QAM.h src/Gauss_noise.h

all: run_graph clean_objs

$(TARGET): $(OBJS)
	$(CXX)  -o $@ $^

%.o: %.cc $(HEADERS)
	$(CXX)  -c $< -o $@

run_graph: $(TARGET)
	./$(TARGET)
	python3 src/Graph.py

clean_objs:
	rm -f $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean clean_objs run_graph
