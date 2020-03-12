//
//  main.cpp
//  barcode
//
//  Created by Metis Sotangkur on 2/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    int data[N], ans[N][2], ans2[N];
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++) cin>>data[i];
    for(int i=0; i<N; i++){
        if(i==0){
            ans2[i] = data[i];
        }
        else if(i==1){
            ans2[i] = max(data[i], data[i-1]);
        }
        else if(i==2){
            ans2[i] = max(data[i], ans2[i-1]);
        }
        else{
            int maxValue=-1;
            for(int j=-2; j<=2; j++){
                if(j-3>=0) maxValue = max(maxValue, ans2[j-3]+data[j]);
                else maxValue = max(maxValue, data[j]);
            }
            ans2[i] = maxValue;
        }
    }
    
    
    
}
