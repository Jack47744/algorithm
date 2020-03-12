//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by Metis Sotangkur on 2/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int saveData[500][500];
int lcs(char dataA[], char dataB[], int i, int j){
    if(i < 0 || j < 0) return 0;
    if(saveData[i][j] > 0) return saveData[i][j];
    if(dataA[i] == dataB[j]){
        return saveData[i][j] = 1 + lcs(dataA, dataB, i-1, j-1);
    }
    return saveData[i][j] = max(lcs(dataA, dataB, i-1, j), lcs(dataA, dataB, i, j-1));
    
}
int main(int argc, const char * argv[]) {
    string A, B;
   
    cin>>A;
    cin>>B;
    char dataA[A.length()], dataB[B.length()];
    for(int i=0; i<A.length(); i++){
        dataA[i] = A[i];
    }
    for(int i=0; i<B.length(); i++){
        dataB[i] = B[i];
    }
    cout<<lcs(dataA, dataB, A.length()-1, B.length()-1)<<"\n";
    
    
}
/*
 acbdegcedbg
 begcfeubk
 
 aaa
 bbbbbbbbb
 */
