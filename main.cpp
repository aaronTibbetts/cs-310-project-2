#include <cstring>
#include <iostream>
#include "util.h"
#include "heap.h"

using namespace std; 
int main(int argc, char* argv[]){
  
    try{
        int userCapacity; 
        int ADT;
        string command;
        if(argv[1]==NULL || strlen(argv[1]) == 0 || argv[2] == NULL || strlen(argv[2]) == 0){
            throw(1);
        }
        try {
            userCapacity = std::stoi(argv[2]); 
        } catch(...) {
            throw(1);
        }
        
        if (strcmp("MaxHeap", argv[1]) == 0 && userCapacity > 0){
            ADT = 1;
            heap maxHeap;
            
            maxHeap.capacity = userCapacity;
            maxHeap.size = 0;
            cin >> command;
            readCommands(command, ADT, maxHeap);

        } else if (strcmp("MinHeap", argv[1]) == 0 && userCapacity > 0 ){
            ADT = 2;
            heap minHeap; 
            minHeap.capacity = userCapacity;
            minHeap.size = 0;
            cin >> command;
            readCommands(command, ADT, minHeap);
        } else if (strcmp("DoubleHeap", argv[1]) == 0 && userCapacity > 0){
            ADT = 3; 
            heap doubleHeap;
            doubleHeap.capacity = userCapacity;
            doubleHeap.size = 0;
            cin >> command;
            readCommands(command, ADT, doubleHeap);
        } else {
            throw(1);
        }
    }

   catch(int n){
   cerr <<"Usage: ./PJ2 DataStructure Capacity\n";
   cerr <<"       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}\n";
   cerr <<"       Capacity must be a positive integer\n";
   }
   return 0;
}