//
//  main.h
//  algo 1.001
//
//  Created by Can Babaoğlu on 4.10.2017.
//  Copyright © 2017 Can Babaoğlu. All rights reserved.
//

#ifndef main_h
#define main_h
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Cards{
    
public:
    char Name[40];
    char Class[10];
    char Rarity[15];
    char Set[20];
    char Type[10];
    int Cost;

};

struct CardManager {
    
     vector<Cards> myvec;
     FILE *OcakTasi;
    
    bool OpenTheFile(const char []);
    void ReadFromFile(vector<Cards> &);
    void PrintTheVector(vector<Cards> &); // test methodu
    void WriteToFile(vector<Cards> &, long int, const char argi[]);
    void FullInsertionSort(vector<Cards> &,long int );
    void FilterInsertionSort(vector<Cards> &,long int );
    void FilterMerge(vector<Cards>& , long int , long int, long int );
    void FullMerge(vector<Cards>& , long int , long int, long int );
    void FilterMergeSort(vector<Cards>& , long int , long int );
    void FullMergeSort(vector<Cards>& , long int , long int );
    
};

#endif /* main_h */
