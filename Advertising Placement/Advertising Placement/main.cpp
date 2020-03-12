//
//  main.cpp
//  Advertising Placement
//
//  Created by Metis Sotangkur on 2/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int dataSave[10000];
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int C[N];
    for(int i=0; i<N; i++) cin>>C[i];
    int tmp[N];
    tmp[0] = C[0];
    if(N>0) tmp[1] = max(C[0],C[1]);
    if(N>1) tmp[2] = max(C[0]+C[2], C[1]);
    if(N>2){
        for(int i=2; i<N;i++){
            tmp[i] = max(tmp[i-1], tmp[i-2] + C[i]);
        }
    }
    cout<<tmp[N-1]<<endl;
    
    
    
}
/*
 10
 48 1 3 95 2 1 3 44 22 2
 */
