//
//  main.cpp
//  Fractional Knapsack
//
//  Created by Metis Sotangkur on 2/24/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    double W;
    int N;
    cin>>W>>N;
    //vector<pair<double, double>> data(N);
    //vector<double> dataFraction;
    vector<pair<double, pair<double, double>>> data2(N);
    for(int i=0; i<N; i++){
        double n;
        cin>>n;
        //data[i].first = n;
        data2[i].second.first = n;
    }
    for(int i=0; i<N; i++){
        double n;
        cin>>n;
        //data[i].second = n;
        data2[i].second.second = n;
    }
    for(int i=0; i<N; i++){
        //data[i].first = data[i].first/data[i].second;
        data2[i].first = data2[i].second.first/data2[i].second.second;
    }
   // sort(data.begin(), data.end());
    sort(data2.begin(), data2.end());
    double price = 0;
    for(int i=N-1; i>=0; i--){
        if(W>=data2[i].second.second){
            price += data2[i].second.first;
            W -= data2[i].second.second;
        }
        else if(W>0){
            price += data2[i].first*W;
            W = 0;
            break;
        }
    }
    //cout<<price<<endl;
    printf("%.4lf",price);
    return 0;
}
