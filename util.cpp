#include "util.h"
#include "heap.h"
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
using namespace std; 


void readCommands(string command, int ADT, heap &Heap){
    if(command.compare("Stop") == 0){
        stop();

    } else if(command.compare("Print") == 0){
        print(Heap,ADT);
        cin >> command;
        readCommands(command, ADT, Heap);
       
    } else if(command.compare("Read") == 0){
        read(Heap, ADT);
        cin >> command;
        readCommands(command, ADT, Heap);
     
    } else if(command.compare("Write") == 0){
        write(Heap, ADT);
        cin >> command;
        readCommands(command, ADT, Heap);

    } else if(command.compare("Insert") == 0){
        int userKey;
        cin >> userKey;
        insert(userKey, Heap, ADT);
        cin >> command;
        readCommands(command,ADT,Heap);
        
    } else if(command.compare("ExtractMax") == 0){ 
        if(ADT == 2 || Heap.size == 0){
             cerr << "Error: ExtractMax in a min heap or a null/empty heap" << '\n';
             cin >> command;
             readCommands(command, ADT, Heap);
        } else {
            extractMax(Heap, ADT);
            cin >> command;
            readCommands(command, ADT, Heap);
        }      
    } else if(command.compare("ExtractMin") == 0){
        if(ADT == 1 || Heap.size == 0){
            cerr << "Error: ExtractMin in a max heap or a null/empty heap" << '\n';
            cin >> command;
            readCommands(command, ADT, Heap);
        } else {
            extractMin(Heap, ADT);
            cin >> command;
            readCommands(command, ADT, Heap);
        }
    } else if(command.compare("IncreaseKey") == 0){
        int userKey;
        int pos;
        cin >> pos;
        cin >> userKey;
        if(ADT == 2 || Heap.size == 0 || pos > Heap.size || userKey < Heap.A[pos]->key){
            cerr << "Error: Invalid position or newKey in IncreaseKey" << '\n';
            cin >> command;
            readCommands(command, ADT, Heap);

        }

        increaseKey(Heap, pos, userKey);
        cin >> command;
        readCommands(command, ADT, Heap);

    } else if (command.compare("DecreaseKey") == 0){
        int userKey;
        int pos;
        cin >> pos;
        cin >> userKey;
        if(ADT == 1 || Heap.size == 0 || pos > Heap.size || userKey > Heap.a[pos]->key){
            cerr << "Error: Invalid position or newKey in DecreaseKey" << '\n';
            cin >> command;
            readCommands(command, ADT, Heap);
        }

        decreaseKey(Heap, pos, userKey);
        cin >> command;
        readCommands(command, ADT, Heap);

    } else {
      cerr << "Invalid command, please use a valid command" << '\n';  
      cin >> command;
      readCommands(command, ADT, Heap);
    }
}

void stop(){
    exit(0);
}

void print(heap &Heap, int ADT){
    string command; 
    cout << "capacity="<<Heap.capacity<< ", size=" <<Heap.size<<'\n';
    if(Heap.size == 0){
        cin >> command;
        readCommands(command, ADT, Heap);
    } else {
    if(ADT == 1){
         cout<< "MaxHeap: ";
        cout << Heap.A[0]->key;
         for(int j = 1; j <Heap.size; j++){
         cout << ", ";
         cout << Heap.A[j]->key;
    }

    } else if (ADT == 2){ 
        cout << "MinHeap: ";
         cout << Heap.a[0]->key;
         for(int j = 1; j <Heap.size; j++){
         cout << ", ";
         cout << Heap.a[j]->key;
    }

    } else {
        cout << "MaxHeap: ";
        cout << Heap.A[0]->key;
         for(int j = 1; j <Heap.size; j++){
         cout << ", ";
         cout << Heap.A[j]->key;
    }
    
        cout << '\n';
        cout << "MinHeap: ";
         cout << Heap.a[0]->key;
         for(int j = 1; j <Heap.size; j++){
         cout << ", ";
         cout << Heap.a[j]->key;
    }

    }
    }
    cout << '\n';
}

void read(heap &Heap, int ADT){
    ifstream inputFile ("HEAPifile.txt");
    if (inputFile.is_open()){
        inputFile >> Heap.size;
        if(Heap.size > Heap.capacity){
            cerr << "n < capacity";
                inputFile.close();
                string command;
                cin >> command;
                readCommands(command, ADT, Heap);
        } else {
            if(ADT == 1){
        Heap.A = (ELEMENT**)malloc(sizeof(ELEMENT*) * Heap.size);
        for (int i = 0; i < Heap.size; i++) {
            int buff;
            inputFile >> buff;
            ELEMENT * node = new ELEMENT();
                    node->key = buff;
                    Heap.A[i] = node;
            }
            inputFile.close();
            buildHeapMax(Heap);
        } else if (ADT == 2){
        Heap.a = (ELEMENT**)malloc(sizeof(ELEMENT*) * Heap.size);
        for (int i = 0; i < Heap.size; i++) {
            int buff;
            inputFile >> buff;
            ELEMENT * node = new ELEMENT();
                    node->key = buff;
                    Heap.a[i] = node;
            }
            inputFile.close();
            buildHeapMin(Heap);
        } else {
        Heap.a = (ELEMENT**)malloc(sizeof(ELEMENT*) * Heap.size);
        Heap.A = (ELEMENT**)malloc(sizeof(ELEMENT*) * Heap.size);
        for (int i = 0; i < Heap.size; i++) {
            int buff;
            inputFile >> buff;
            ELEMENT * node = new ELEMENT();
                    node->key = buff;
                    Heap.a[i] = node;
                    Heap.A[i] = node;
            }
            inputFile.close();
            buildHeapMin(Heap);
            buildHeapMax(Heap);
        }
        }
    } else {
        cerr << "Can't open file";
    }
}

void write(heap &Heap, int ADT){
    ofstream outputFile ("HEAPofile.txt");
    if(outputFile.is_open()){
        outputFile << "capacity="<<Heap.capacity<< ", size=" <<Heap.size<<'\n';
        if (ADT == 1){
            outputFile << "MaxHeap: ";
            outputFile << Heap.A[0]->key;
            for (int i = 1 ; i < Heap.size; i++){
                outputFile << ", ";
                outputFile << Heap.A[i]->key;
            }
            outputFile << '\n';
            outputFile.close();
        } else if (ADT == 2){
            outputFile << "MinHeap: ";
              outputFile << Heap.a[0]->key;
            for (int i = 1 ; i < Heap.size; i++){
                outputFile << ", ";
                outputFile << Heap.a[i]->key;
            }
            outputFile << '\n';
            outputFile.close();
        } else {
            outputFile << "MaxHeap: ";
            outputFile << Heap.A[0]->key;
            for (int i = 1 ; i < Heap.size; i++){
                outputFile << ", ";
                outputFile << Heap.A[i]->key;
            }
            outputFile << '\n';
            outputFile << "MinHeap: ";
            outputFile << Heap.a[0]->key;
            for (int i = 1 ; i < Heap.size; i++){
                outputFile << ", ";
                outputFile << Heap.a[i]->key;
            }
            outputFile << '\n';
            outputFile.close();
        }
       
    } else {
        cerr << "Can't open file";
    }

}

