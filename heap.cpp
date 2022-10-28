#include "heap.h"
#include <iostream>
using namespace std;

void heapifyMax(heap &maxHeap, int i){
    int largestElement = 0;
    int leftElement = 2 * i + 1; 
    int rightElement = 2 * i + 2;

    if(leftElement < maxHeap.size && maxHeap.A[leftElement]->key > maxHeap.A[i]->key) {
        largestElement = leftElement;
    }  else {
        largestElement = i;
    }
    
    if(rightElement < maxHeap.size && maxHeap.A[rightElement]->key > maxHeap.A[largestElement]->key){
        largestElement = rightElement;
    } 
    if(largestElement != i){
        ELEMENT* temp = new ELEMENT();
        temp = maxHeap.A[i];
        maxHeap.A[i] = maxHeap.A[largestElement];
        maxHeap.A[largestElement] = temp;
        heapifyMax(maxHeap, largestElement);
    } 
}



void heapifyMin(heap &minHeap, int i){
    int smallestElement = 0;
    int leftElement = 2 * i +1; 
    int rightElement = 2 * i +2;

    if(leftElement < minHeap.size && minHeap.a[leftElement]->key < minHeap.a[i]->key){
        smallestElement = leftElement;
    } else {
        smallestElement = i;
    }
    
    if(rightElement < minHeap.size && minHeap.a[rightElement]->key < minHeap.a[smallestElement]->key){
        smallestElement = rightElement;
    } 

    if(smallestElement != i){
        ELEMENT* temp = minHeap.a[i];
        minHeap.a[i] = minHeap.a[smallestElement];
        minHeap.a[smallestElement] = temp;
        heapifyMin(minHeap,smallestElement);

    }
}

void buildHeapMax(heap &Heap){
    for(int i = Heap.size/2; i >= 0; i--){
        heapifyMax(Heap, i);
    }
}

void buildHeapMin(heap &Heap){
    for(int i = Heap.size/2; i >= 0; i--){
        heapifyMin(Heap,i);
    }

}

void extractMin(heap &minHeap, int ADT){
    if(minHeap.size == 1){
        cout << minHeap.a[0]->key;
        minHeap.size = minHeap.size - 1;
        return;
    } 
        
    ELEMENT* root = minHeap.a[0];
    minHeap.a[0] = minHeap.a[minHeap.size-1];
    if(ADT == 3){
        deleteForMax(minHeap, findMaxDeleteIndex(minHeap));
    }
    minHeap.size = minHeap.size -1; 
    cout << "ExtractMin: " << root->key << '\n';
    buildHeapMin(minHeap);
}

void extractMax(heap &maxHeap, int ADT){
    if(maxHeap.size == 1){
        cout << maxHeap.A[0]->key;
        maxHeap.size = maxHeap.size - 1;
        return;
    } 
        
    ELEMENT* root = maxHeap.A[0];
    maxHeap.A[0] = maxHeap.A[maxHeap.size-1];
    if (ADT == 3) {
        deleteForMin(maxHeap, findMinDeleteIndex(maxHeap));
    }
    maxHeap.size = maxHeap.size -1; 
    cout <<"ExtractMax: " << root->key << '\n';
    buildHeapMax(maxHeap);
}

void insert(int key, heap &Heap, int ADT){
    if(Heap.size == Heap.capacity){
        cout << "Heap full can't insert anymore"; 
    } else {
        Heap.size = Heap.size + 1;
        int i = Heap.size-1;
        if (ADT == 1){
            ELEMENT * newElement = new ELEMENT();
            newElement->key = key;
            Heap.A[i] = newElement;
            buildHeapMax(Heap);
        } else if (ADT == 2){
            ELEMENT * newElement = new ELEMENT();
            newElement->key = key;
            Heap.a[i] = newElement;
            buildHeapMin(Heap);
        } else {
            ELEMENT * newElement = new ELEMENT();
            newElement->key = key;
            Heap.A[i] = newElement;
            Heap.a[i] = newElement;
            buildHeapMax(Heap);
            buildHeapMin(Heap);
        }
    }
}

void deleteForMax(heap &minHeap, int pos){
    if(pos < minHeap.size) {
        minHeap.A[pos] = minHeap.A[minHeap.size-1];
        // minHeap.size = minHeap.size -1; 

        if (pos > 0 && pos < minHeap.size && minHeap.A[pos]->key > minHeap.A[pos/2]->key){
            while (pos > 0 && minHeap.A[pos]->key > minHeap.A[pos/2]->key){
                ELEMENT* temp = minHeap.A[pos];
                minHeap.A[pos] = minHeap.A[pos/2];
                minHeap.A[pos/2] = temp;
                pos = pos/2;
            }
        }else{
            heapifyMax(minHeap, pos);
        }
    }
}

void increaseKey(heap &maxHeap, int pos, int newKey){
    if ((pos < maxHeap.size) && (maxHeap.A[pos]->key < newKey)){
        maxHeap.A[pos]->key = newKey;
        buildHeapMax(maxHeap);
    }
}

void decreaseKey(heap &minHeap, int pos, int newKey){
    if ((pos < minHeap.size) && (minHeap.a[pos]->key > newKey)){
        minHeap.a[pos]->key = newKey;
        buildHeapMin(minHeap);
    }
}

void deleteForMin(heap &maxHeap, int pos){
   if(pos < maxHeap.size){
        maxHeap.a[pos] = maxHeap.a[maxHeap.size-1];
        //maxHeap.size = maxHeap.size -1; 

        if (pos >= 0 && pos < maxHeap.size && maxHeap.a[pos]->key < maxHeap.a[pos/2]->key){
            while (pos > 0 && pos < maxHeap.size && maxHeap.a[pos]->key < maxHeap.a[pos/2]->key){
                ELEMENT* temp = maxHeap.a[pos];
                maxHeap.a[pos] = maxHeap.a[pos/2];
                maxHeap.a[pos/2] = temp;
                pos = pos/2;
            }
        }else{
            heapifyMin(maxHeap, pos);
        }
    }
}

int findMinDeleteIndex(heap &minHeap) {
   ELEMENT* largestElement = minHeap.a[0];
   int largestIndex = 0;
   for (int i = 0; i < minHeap.size; i++){  
        if(minHeap.a[i]->key > largestElement->key){
            largestElement = minHeap.a[i];
            largestIndex = i;
        }
   }
   return largestIndex;
}

int findMaxDeleteIndex(heap &maxHeap){
   ELEMENT* smallestElement = maxHeap.A[0];
   int smallestIndex = 0;
   for (int i = 0; i < maxHeap.size; i++){  
        if(maxHeap.A[i]->key < smallestElement->key){
            smallestElement = maxHeap.A[i];
            smallestIndex = i;
        }
   }
   return smallestIndex;
}