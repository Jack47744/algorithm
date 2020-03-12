//
//  main.cpp
//  rope
//
//  Created by Metis Sotangkur on 3/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int saveData[4000][4000], data[3];
int maxNumber(int i, int j){
    if(j==0 || i<0) return 0;
    if(i==0 && data[i]>j) return 0;
    if(i==0 && j%data[i]!=0) return -1;
    if(i==0 && data[i] == j) return 1;
    if(saveData[i][j]>0) return saveData[i][j];
    if(data[i]>j){
        return saveData[i][j] = maxNumber(i-1, j);
    }
    return saveData[i][j] = max(maxNumber(i-1, j), maxNumber(i, j-data[i]) + 1);
    
       
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=0; i<3; i++) cin>>data[i];
    sort(data, data+3);
    //for(int i=0; i<3; i++) cout<<data[i]<<endl;
    for(int i=0; i<4000; i++){
        for(int j=0; j<3; j++) saveData[i][j] = 0;
    }
    cout<<maxNumber(2, n);
    return 0;
}
