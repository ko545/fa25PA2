//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64]; // heap array ?
    int size; // stores current size of the heap

    MinHeap() { size = 0; }

    void push(int keyIndex, int weightArr[]) {
        if (size >= 64) {
            cout << "Full Heap" << endl;
            return;
        }
        // TODO: insert index at end of heap
        //       Restore order using upheap()
        weightArr[size] = keyIndex;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        if (size <= 0) {
            cout << "Empty Heap" << endl;
            return 0;
        }
        // TODO: remove and return smallest index
        //       Replace root with last element, then call downheap()
        int smallestIndex = weightArr[0]; // get smallest index
        weightArr[0] = weightArr[size]; // replace root with last element
        size--; //reduce size of array
        downheap(size, weightArr);
        return smallestIndex; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif