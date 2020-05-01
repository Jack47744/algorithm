//
//  main.cpp
//  Fractional Knapsack
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    double W;
    int N;
    cin>>W>>N;
    vector<pair<double, pair<double, double>>> data(N);
    for(int i=0; i<N; i++) cin>>data[i].second.first;
    for(int i=0; i<N; i++) {
        cin>>data[i].second.second;
        data[i].first = data[i].second.first/data[i].second.second;
    }
    double ans = 0;
    sort(data.begin(), data.end());
    for(int i=N-1; i>=0; i--){
        if(W<=0) break;
        else if(W>=data[i].second.second){
            ans += data[i].second.first;
            W -= data[i].second.second;
        }
        else{
            ans += data[i].first * W;
            W = 0;
        }
    }
    printf("%.4lf\n", ans);
    return 0;
}
