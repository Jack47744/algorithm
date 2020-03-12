//
//  main.cpp
//  Matrix Chain Multiplication
//
//  Created by Metis Sotangkur on 2/11/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int saveData[101][101];
int mcm(int data[], int i, int j){
    if(i == j) return 0;
    if(saveData[i][j] > 0) return saveData[i][j];
    saveData[i][j] = 2147483647;
    for(int k=i; k<=j-1; k++){
        saveData[i][j] = min(saveData[i][j], mcm(data, i, k) + mcm(data, k+1, j) + data[i-1]*data[j]*data[k]);
    }
    return saveData[i][j];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int N;
    cin>>N;
    int data[N+1];
    for(int i=0; i<=N; i++) cin>>data[i];
    cout<<mcm(data, 1, N);
    //std::cout << "Hello, World!\n";
    return 0;
}
