#ifndef HEAP_H
#define HEAP_H
struct ELEMENT {
    int key;
};

struct heap {
    int capacity;
    int size;
    ELEMENT ** A;
    ELEMENT ** a;
};

void insert(int key, heap &Heap, int ADT);

void extractMax(heap &maxHeap, int ADT);

void extractMin(heap &minHeap, int ADT);

void increaseKey(heap &minHeap ,int position, int key);

void decreaseKey(heap &maxHeap, int position, int key);

void deleteForMax(heap &maxHeap, int pos);

void deleteForMin(heap &minHeap, int pos);

void heapifyMax(heap &maxHeap, int j);

void heapifyMin(heap &minHeap, int j);

void buildHeapMax(heap &Heap);

void buildHeapMin(heap &Heap);

int findMinDeleteIndex(heap &minHeap);

int findMaxDeleteIndex(heap &maxHeap);
#endif