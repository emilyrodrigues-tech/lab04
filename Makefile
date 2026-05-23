CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

all: examheap

examheap: examheap.cpp heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -o examheap examheap.cpp heap.cpp

clean:
	rm -f examheap
