//
//  main.cpp
//  algo 1.001
//
//  Created by Can Babaoğlu on 4.10.2017.
//  Copyright © 2017 Can Babaoğlu. All rights reserved.
//
#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <chrono>

using namespace std;

using  ms = chrono::microseconds;
using get_time = chrono::steady_clock ;

CardManager canbaba;

int main(int argc, const char * argv[]) {
    
    
    long int size;
    // cout<<"ne yazdım-> "<<argv[1]<<endl; TEST
    
    if((canbaba.OpenTheFile(argv[3])==false)){/////////dosyayı aç, dosya adını terminalden al yolla.
        cerr << "File can not be opened" << endl;
        exit(1);
    }
    canbaba.ReadFromFile(canbaba.myvec);/////dosyadan vektöre oku.
    size=canbaba.myvec.size();// vektör dolduktan sonra size ı alalım.
    long int p = 0;
    long int r = size-1;
    //canbaba.PrintTheVector(canbaba.myvec); // doğru dolduruyor vektörü TEST
    
////////////////TERMİNALDEN GİRİLENLERE GÖRE UYGUN METHODU ÇAĞIR/////////////////////////
    
    auto start = get_time::now(); //süreyi burda alıyorum  bu küçük işlemler sortun yanında göz ardı edilebilir
    
    if(strcmp((argv[1]),"-full")==0){
        if(strcmp((argv[2]),"-i")==0){
            canbaba.FullInsertionSort(canbaba.myvec, size);
        }
        else if(strcmp(argv[2],"-m")==0 ){
            canbaba.FullMergeSort(canbaba.myvec, p, r);
            
        }
        else {
            cout<<"please type the second argv properly ( -i or -m) "<<endl;
            return 0;
        }
    }
    else if(strcmp(argv[1],"-filter")==0 ){
        if(strcmp((argv[2]),"-i")==0){
            canbaba.FilterInsertionSort(canbaba.myvec, size);
        }
        else if(strcmp(argv[2],"-m")==0 ){
            canbaba.FilterMergeSort(canbaba.myvec, p, r);
        }
        else {
            cout<<"please type the second argv properly ( -i or -m) "<<endl;
            return 0;
        }
    }
    else {
        cout<<"please type the first argv properly ( -full or -filter) "<<endl;
        return 0;
    }
    
    auto end = get_time::now();
    auto diff = end - start;
    cout<<"Elapsed time is :  "<< chrono::duration_cast<ms>(diff).count()<<" ms "<<endl; /// sortta işi bitirip gelince süreyi yaz
////////////////TERMİNALDEN GİRİLENLERE GÖRE UYGUN METHODU ÇAĞIR/////////////////////////
    
    //cout<<"---Sort called---"<<endl; TEST
    canbaba.WriteToFile(canbaba.myvec, size, argv[4]);
    //canbaba.PrintTheVector(canbaba.myvec); // TEST
    return 0;
}
