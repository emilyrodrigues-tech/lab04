// heap.cpp
// Emily Rodrigues

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
    vdata.push_back(0);                    
    vdata.insert(vdata.end(), start, end); 

    int n = (int)vdata.size() - 1;       
    for (int i = n / 2; i >= 1; --i)    
        bubbleDown(i);
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
      if (vdata.empty())
        vdata.push_back(0);   
    vdata.push_back(value);
    bubbleUp((int)vdata.size() - 1);

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if (empty()) return;

    vdata[1] = vdata.back(); 
    vdata.pop_back();       

    if (!empty())
        bubbleDown(1);      

}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[1];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
    return vdata.size() <= 1;
}
void Heap::bubbleUp(int i) {
    while (i > 1) {
        int parent = i / 2;
        if (vdata[i] < vdata[parent]) {
            std::swap(vdata[i], vdata[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

void Heap::bubbleDown(int i) {
    int n = (int)vdata.size() - 1;

    while (true) {
        int left     = 2 * i;
        int right    = 2 * i + 1;
        int smallest = i;

        if (left  <= n && vdata[left]  < vdata[smallest]) smallest = left;
        if (right <= n && vdata[right] < vdata[smallest]) smallest = right;

        if (smallest != i) {
            std::swap(vdata[i], vdata[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

    
