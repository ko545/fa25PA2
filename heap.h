//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64]; // heap array ?
    int size{0}; // stores current size of the heap

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
            return -1;
        }
        // TODO: remove and return smallest index
        //       Replace root with last element, then call downheap()
        int smallestIndex = weightArr[0]; // get smallest index
        weightArr[0] = weightArr[size-1]; // replace root with last element
        downheap(0, weightArr);
        size--;
        return smallestIndex; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[pos] >= weightArr[parent])
                break; // heap property holds
            swap(weightArr[pos], weightArr[parent]); //bubble up
            pos = parent; // move up the tree
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (2 * pos + 1 < size) { //while left child exists
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = left;

            if (right < size && weightArr[right] < weightArr[left])
                smallest = right; // find smaller child
            if (weightArr[pos] <= weightArr[smallest])
                break; // heap property holds

            swap(weightArr[pos], weightArr[smallest]); // bubble down
            pos = smallest; // move down the tree
        }
    }
};

#endif