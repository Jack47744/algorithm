//
//  main.cpp
//  Coin Change
//
//  Created by Metis Sotangkur on 2/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
int saveData[20][10000];
int minCoin(int data[], int coinIndex, int value){
    //cout<<coinIndex<<" "<<value<<endl;
    if(value == 0) return 0;
    if(coinIndex == 0) return value;
    if(saveData[coinIndex][value] > 0) return saveData[coinIndex][value];
    if(data[coinIndex] > value) return saveData[coinIndex][value] = minCoin(data, coinIndex - 1, value);
    int minvalue = min(1 + minCoin(data, coinIndex, value-data[coinIndex]), minCoin(data, coinIndex-1, value));
    return saveData[coinIndex][value] = minvalue;
}
int main(int argc, const char * argv[]) {
    int N, M;
    cin>>N>>M;
    
    vector<int> v;
    int data[N];
    for(int i=0; i<N; i++){
        int number;
        cin>>number;
        v.push_back(number);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) data[i] = v[i];
    cout<<minCoin(data, v.size()-1, M)<<"\n";
}
/*
4 28
10 5 2 1
 */
