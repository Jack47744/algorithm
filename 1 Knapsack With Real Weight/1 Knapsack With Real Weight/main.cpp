//
//  main.cpp
//  1 Knapsack With Real Weight
//
//  Created by Metis Sotangkur on 3/27/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
double w;
int n;
double W[101], V[101];
double maxValue = 0;
double h(int i, double availableWeight){
    priority_queue<pair<double, pair<double, double>>> pq;
    for(int j=i; j<n; j++){
        pq.push({V[j]/W[j], {W[j], V[j]}});
    }
    double tmpWeight = availableWeight;
    double ans = 0;
    while(pq.size()>0){
        pair<double, pair<double, double>> tmp = pq.top();
        pq.pop();
        if(tmpWeight - tmp.second.first >= 0){
            tmpWeight -= tmp.second.first;
            ans += tmp.second.second;
        }
        else if(tmpWeight>0){
            ans += tmp.first * tmpWeight;
            tmpWeight = 0;
        }
        else if(tmpWeight<=0) break;
    }
    return ans;
}
double mySum(vector<int> v, int start, int end, double data[]){
    double ans = 0;
    for(int i=start; i<=end; i++){
        if(v[i]) ans += data[i];
    }
    return ans;
}
void f(int i, vector<int> v, double nowWeight, double nowValue){
    //cout<<i<<" "<<nowWeight<<" "<<nowValue<<" "<<mySum(v, 0, i-1, V) + h(i, w-nowWeight)<<"\n";
    //for(auto x:v) cout<<x<<" ";
    //cout<<"\n";
    if(nowWeight>w) return;
    if(mySum(v, 0, i-1, V) + h(i, w-nowWeight) <= maxValue) return;
    if(i<n){
        vector<int> tmp = v;
        tmp.push_back(0);
        f(i+1, tmp, nowWeight, nowValue);
        v.push_back(1);
        f(i+1, v, nowWeight + W[i], nowValue + V[i]);
    }
    else{
       // cout<<mySum(v, 0, i-1, V)<<endl;
        maxValue = max(maxValue, mySum(v, 0, i-1, V));
    }
    
}
int main(int argc, const char * argv[]) {
    cin>>w>>n;
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    for(int i=0; i<n; i++){
        cin>>W[i];
    }
    vector<int> tmp;
    f(0, tmp, 0, 0);
    printf("%.4f", maxValue);
}
/*
 10.0 4
 1.2 3.4 6.3 1.3
 4.2 1.4 6.7 4.3
 
 */
