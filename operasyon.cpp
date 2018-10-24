//
//  operasyon.cpp
//  algo 1.001
//
//  Created by Can Babaoğlu on 8.10.2017.
//  Copyright © 2017 Can Babaoğlu. All rights reserved.
//

#include "main.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

bool CardManager::OpenTheFile(const char argi[]){
   
    string a = argi;
    //cout<<"acmanin ici" <<a;
    OcakTasi = fopen(argi, "r+" );
    if(!OcakTasi){
        if(!(OcakTasi = fopen(argi, "w+" ))){
            return false;
        }
    }
    return true;
}

void CardManager::ReadFromFile(vector<Cards> &a){
    
    Cards tutucu; // tek tek çek içe
    fseek(OcakTasi, 0, SEEK_SET); // al başa
    
    while(!feof(OcakTasi)){
        
        fscanf(OcakTasi,"%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d",tutucu.Name,tutucu.Class,tutucu.Rarity,tutucu.Set,tutucu.Type,&tutucu.Cost);
       
        //cout<<tutucu.Name<<tutucu.Class<<tutucu.Rarity<<tutucu.Set<<tutucu.Type<<tutucu.Cost;
        // OKUYOR!!!
        //if(feof(OcakTasi)) break; gerek yok
        a.push_back(tutucu);// ver vektöre
    }
}

void CardManager::PrintTheVector(vector<Cards> &a ){ // test edebilmek için yazılmış bir fonksiyon
    
    for(int i=0;i<a.size();i++){
        cout<<a[i].Name<<"-"<<a[i].Class<<"-"<<a[i].Rarity<<"-"<<a[i].Set<<"-"<<a[i].Type<<"-"<<a[i].Cost<<endl;
    }
}

void CardManager::WriteToFile(vector<Cards> &a, long int n, const char argi[]){
    FILE *OcakTasi1;
    OcakTasi1 = fopen(argi, "w+");
    fseek(OcakTasi1,0,SEEK_SET);
    for(int i=0;i<n;i++)//tek tek al˝p aralara tab atarak dosyaya yaz.
    {
        fprintf(OcakTasi1,"%s\t%s\t%s\t%s\t%s\t%d",a[i].Name,a[i].Class,a[i].Rarity,a[i].Set,a[i].Type,a[i].Cost);
    }
    fclose(OcakTasi1);
}


void CardManager::FullInsertionSort(vector<Cards> &a, long int n){
    
    int i,j;
    Cards key;
    // = operatorünü overload edip yapamadım olmadı nedense :)
    for (j = 2; j <n; j++) // burda class a göre sort
    {
        strcpy(key.Name, a[j].Name);
        strcpy(key.Class, a[j].Class);
        strcpy(key.Rarity, a[j].Rarity);
        strcpy(key.Set, a[j].Set);
        strcpy(key.Type, a[j].Type);
        key.Cost=a[j].Cost;
        
        i = j-1;
        
        while (i >= 0 && (strcmp(a[i].Class,key.Class)>=0) )
        {
            strcpy(a[i+1].Name,a[i].Name);
            strcpy(a[i+1].Class,a[i].Class);
            strcpy(a[i+1].Rarity,a[i].Rarity);
            strcpy(a[i+1].Set,a[i].Set);
            strcpy(a[i+1].Type,a[i].Type);
            a[i+1].Cost = a[i].Cost;
          
            i = i-1;
        }
        strcpy(a[i+1].Name, key.Name);
        strcpy(a[i+1].Class,key.Class);
        strcpy(a[i+1].Rarity, key.Rarity);
        strcpy(a[i+1].Set, key.Set);
        strcpy(a[i+1].Type, key.Type);
        a[i+1].Cost=key.Cost;
    }
    for (j = 2; j <n; j++) // burda eğer clasları aynıysa cost a göre sort
    {
        strcpy(key.Name, a[j].Name);
        strcpy(key.Class, a[j].Class);
        strcpy(key.Rarity, a[j].Rarity);
        strcpy(key.Set, a[j].Set);
        strcpy(key.Type, a[j].Type);
        key.Cost=a[j].Cost;
        
        i = j-1;
        
        while (i >= 0 && (strcmp(a[i].Class,key.Class)==0) && ((a[i].Cost)>=(key.Cost)))
        {
            strcpy(a[i+1].Name,a[i].Name);
            strcpy(a[i+1].Class,a[i].Class);
            strcpy(a[i+1].Rarity,a[i].Rarity);
            strcpy(a[i+1].Set,a[i].Set);
            strcpy(a[i+1].Type,a[i].Type);
            a[i+1].Cost = a[i].Cost;
            
            i = i-1;
        }
        strcpy(a[i+1].Name, key.Name);
        strcpy(a[i+1].Class,key.Class);
        strcpy(a[i+1].Rarity, key.Rarity);
        strcpy(a[i+1].Set, key.Set);
        strcpy(a[i+1].Type, key.Type);
        a[i+1].Cost=key.Cost;
    }
    for (j = 2; j <n; j++) // burda eğer clasları aynıysa cost a göre sort
    {
        strcpy(key.Name, a[j].Name);
        strcpy(key.Class, a[j].Class);
        strcpy(key.Rarity, a[j].Rarity);
        strcpy(key.Set, a[j].Set);
        strcpy(key.Type, a[j].Type);
        key.Cost=a[j].Cost;
        
        i = j-1;
        
        while (i >= 0 && (strcmp(a[i].Class,key.Class)==0) && (a[i].Cost==key.Cost) && (strcmp(a[i].Name,key.Name)>=0))
        {
            strcpy(a[i+1].Name,a[i].Name);
            strcpy(a[i+1].Class,a[i].Class);
            strcpy(a[i+1].Rarity,a[i].Rarity);
            strcpy(a[i+1].Set,a[i].Set);
            strcpy(a[i+1].Type,a[i].Type);
            a[i+1].Cost = a[i].Cost;
            
            i = i-1;
        }
        strcpy(a[i+1].Name, key.Name);
        strcpy(a[i+1].Class,key.Class);
        strcpy(a[i+1].Rarity, key.Rarity);
        strcpy(a[i+1].Set, key.Set);
        strcpy(a[i+1].Type, key.Type);
        a[i+1].Cost=key.Cost;
    }
    
}

void CardManager::FilterInsertionSort(vector<Cards> &a, long int n){
    
    int i,j;
    Cards key;
    // = operatorünü overload edip yapamadım olmadı nedense :)
    for (j = 2; j <n; j++) // burda class a göre sort
    {
        strcpy(key.Name, a[j].Name);
        strcpy(key.Class, a[j].Class);
        strcpy(key.Rarity, a[j].Rarity);
        strcpy(key.Set, a[j].Set);
        strcpy(key.Type, a[j].Type);
        key.Cost=a[j].Cost;
        
        i = j-1;
        
        while (i >= 0 && (strcmp(a[i].Type,key.Type)>=0) )
        {
            strcpy(a[i+1].Name,a[i].Name);
            strcpy(a[i+1].Class,a[i].Class);
            strcpy(a[i+1].Rarity,a[i].Rarity);
            strcpy(a[i+1].Set,a[i].Set);
            strcpy(a[i+1].Type,a[i].Type);
            a[i+1].Cost = a[i].Cost;
            
            i = i-1;
        }
        strcpy(a[i+1].Name, key.Name);
        strcpy(a[i+1].Class,key.Class);
        strcpy(a[i+1].Rarity, key.Rarity);
        strcpy(a[i+1].Set, key.Set);
        strcpy(a[i+1].Type, key.Type);
        a[i+1].Cost=key.Cost;
    }
    
}

void CardManager::FilterMerge(vector<Cards>& a, long int p , long int q, long int r){
    
    long int i,j;
    long int n1 = (q-p)+1; // sol dizim
    long int n2 = (r-q); // sağ dizim
    
    vector<Cards> Left;
    vector<Cards> Right;

    for(i=0; i<n1; i++){
        Left.push_back(a[p+i]);
    }
    for(j=0; j<n2; j++){
        Right.push_back(a[q+j+1]);
    }
    ////////////////////////////
    
    Cards sonsuzluk;
    strcpy(sonsuzluk.Name, "{"); // ASCII tablosunda harflerden sonra gelen bi sembol tilde
    strcpy(sonsuzluk.Class, "{");
    strcpy(sonsuzluk.Rarity, "{");
    strcpy(sonsuzluk.Set, "{");
    strcpy(sonsuzluk.Type, "{");
    sonsuzluk.Cost = 99999; // 999 çok sonsuz bi sayı
    
    Left.push_back(sonsuzluk);
    Right.push_back(sonsuzluk);
    
    i=0;
    j=0;
    
    for(long int k=p; k<=r; k++){
        if(strcmp(Left[i].Type,Right[j].Type)<=0){ //if(Left[i] <= Right[j]){
            strcpy(a[k].Name,Left[i].Name);
            strcpy(a[k].Class,Left[i].Class);
            strcpy(a[k].Rarity,Left[i].Rarity);
            strcpy(a[k].Set,Left[i].Set);
            strcpy(a[k].Type,Left[i].Type);
            a[k].Cost = Left[i].Cost;
            i++;
        }
        else{
            strcpy(a[k].Name,Right[j].Name);
            strcpy(a[k].Class,Right[j].Class);
            strcpy(a[k].Rarity,Right[j].Rarity);
            strcpy(a[k].Set,Right[j].Set);
            strcpy(a[k].Type,Right[j].Type);
            a[k].Cost = Right[j].Cost;
            j++;
        }
    }
}

void CardManager::FullMerge(vector<Cards>& a, long int p , long int q, long int r){
    long int i,j;
    long int n1 = (q-p)+1; // sol dizim
    long int n2 = (r-q); // sağ dizim
    
    vector<Cards> Left;
    vector<Cards> Right;
    
    for(i=0; i<n1; i++){
        Left.push_back(a[p+i]);
    }
    for(j=0; j<n2; j++){
        Right.push_back(a[q+j+1]);
    }
    
    Cards sonsuzluk;
    strcpy(sonsuzluk.Name, "~~~"); // ASCII tablosunda harflerden sonra gelen bi sembol tilde
    strcpy(sonsuzluk.Class, "~~~");
    strcpy(sonsuzluk.Rarity, "~~~");
    strcpy(sonsuzluk.Set, "~~~");
    strcpy(sonsuzluk.Type, "~~~");
    sonsuzluk.Cost = 99999; // 999 çok sonsuz bi sayı
    
    //Left.push_back(sonsuzluk);
    //Right.push_back(sonsuzluk);
    
    i=0;
    j=0;
    
    for(long int k=p; k<=r; k++){
        if(strcmp(Left[i].Class,Right[j].Class)<0 ){ //Class a göre sırala
            strcpy(a[k].Name,Left[i].Name);
            strcpy(a[k].Class,Left[i].Class);
            strcpy(a[k].Rarity,Left[i].Rarity);
            strcpy(a[k].Set,Left[i].Set);
            strcpy(a[k].Type,Left[i].Type);
            a[k].Cost = Left[i].Cost;
            i++;
        }
        else if( strcmp(Left[i].Class,Right[j].Class )==0){
            if(Left[i].Cost < Right[j].Cost ){
                strcpy(a[k].Name,Left[i].Name);
                strcpy(a[k].Class,Left[i].Class);
                strcpy(a[k].Rarity,Left[i].Rarity);
                strcpy(a[k].Set,Left[i].Set);
                strcpy(a[k].Type,Left[i].Type);
                a[k].Cost = Left[i].Cost;
                i++;
                }
            else if (Left[i].Cost == Right[j].Cost){
                if(strcmp(Left[i].Name,Right[j].Name )<=0){
                    strcpy(a[k].Name,Left[i].Name);
                    strcpy(a[k].Class,Left[i].Class);
                    strcpy(a[k].Rarity,Left[i].Rarity);
                    strcpy(a[k].Set,Left[i].Set);
                    strcpy(a[k].Type,Left[i].Type);
                    a[k].Cost = Left[i].Cost;
                    i++;
                    
                }
                else{
                    strcpy(a[k].Name,Right[j].Name);
                    strcpy(a[k].Class,Right[j].Class);
                    strcpy(a[k].Rarity,Right[j].Rarity);
                    strcpy(a[k].Set,Right[j].Set);
                    strcpy(a[k].Type,Right[j].Type);
                    a[k].Cost = Right[j].Cost;
                    j++;
                    
                }
                
                
            }
        
                else{
                    strcpy(a[k].Name,Right[j].Name);
                    strcpy(a[k].Class,Right[j].Class);
                    strcpy(a[k].Rarity,Right[j].Rarity);
                    strcpy(a[k].Set,Right[j].Set);
                    strcpy(a[k].Type,Right[j].Type);
                    a[k].Cost = Right[j].Cost;
                    j++;
            }
        }
        else{
            strcpy(a[k].Name,Right[j].Name);
            strcpy(a[k].Class,Right[j].Class);
            strcpy(a[k].Rarity,Right[j].Rarity);
            strcpy(a[k].Set,Right[j].Set);
            strcpy(a[k].Type,Right[j].Type);
            a[k].Cost = Right[j].Cost;
            j++;
        }
    }
}

void CardManager::FilterMergeSort(vector<Cards>&a , long int p , long int r){
    
    if(p < r){
        
        long int q = (p/2) + (r/2);
        
        FilterMergeSort(a, p, q); //sol yanım
        FilterMergeSort(a, q+1, r); // sağ yanım
        
        FilterMerge(a, p, q, r);
    }
}

void CardManager::FullMergeSort(vector<Cards>&a , long int p , long int r){
    
    if(p < r){
        
        long int q = (p/2) + (r/2);
        
        FullMergeSort(a, p, q); //sol yanım
        FullMergeSort(a, q+1, r); // sağ yanım
        
        FullMerge(a, p, q, r);
    }
}

