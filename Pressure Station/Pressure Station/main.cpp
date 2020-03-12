//
//  main.cpp
//  Pressure Station
//
//  Created by Metis Sotangkur on 2/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, K;
    cin>>N>>K;
    int data[N];
    int sumData[N];
    for(int i=0; i<N; i++) cin>>data[i];
    set<int> s;
    for(int i=0; i<=K && i<N; i++){
        
        s.insert(data[i]);
    }
    for(int i=0; i<N; i++) sumData[i] = 2147483647;
    for(int i=0; i<N; i++){
        if(i<=K){
            sumData[i] = (*s.begin());
        }
        else{
            int minValue = 2147483647;
            int index;
            //set<pair<int, int>> s2;
            for(int j=i-K; j<=i+K && j<N; j++){
                if(j-K-1<0) continue;
                int valueTmp = data[j] + sumData[j - K - 1];
                if(valueTmp < minValue){
                    minValue = valueTmp;
                    index = j;
                }
            }
            sumData[i] = minValue;
            
        }
    }
    cout<<sumData[N-1]<<endl;
    
    
    
    
    
    
    return 0;
}
/*
 5 1
 1 99 1 99 1
 */
