CXX = g++

TARGET = main

SRCS = QPSK_QAM.cc Table.cc Gauss_noise.cc

OBJS = $(SRCS:.cc=.o)

HEADERS = QPSK_QAM.h Gauss_noise.h

all: run_graph clean_objs

$(TARGET): $(OBJS)
	$(CXX)  -o $@ $^

%.o: %.cc $(HEADERS)
	$(CXX)  -c $< -o $@

run_graph: $(TARGET)
	./$(TARGET)
	python3 graph.py

clean_objs:
	rm -f $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean clean_objs run_graph
