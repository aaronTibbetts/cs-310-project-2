#ifndef UTIL_H
#define UTIL_H
#include <string>
#include "heap.h"
using namespace std; 

void readCommands(string command, int ADT, heap &Heap);

void stop();

void print(heap &Heap,int ADT);

void read(heap &Heap, int ADT);

void write(heap &Heap, int ADT);

#endif