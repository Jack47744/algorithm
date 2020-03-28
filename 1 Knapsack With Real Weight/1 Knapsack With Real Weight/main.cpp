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
using namespace std;
double w, ans = 0;
int n;
int u=0;
double W[101], V[101];
vector<pair<double, double>> data;
double sum(double d[], int m, vector<int> v){
    double k = 0;
    for(int i=0; i<m; i++){
        if(v[i]) k += d[i];
    }
    return k;
}
void t(double currentWeight, int m, vector<int> v){
    u++;
    //cout<<u<<endl;
    //cout<<currentWeight<<" "<<m<<" ";
    //for(auto x : v) cout<<x<<" ";
    //cout<<"\n";
    if(currentWeight>w) return;
    if(m==n or currentWeight + W[m] > w){
        ans = max(ans, sum(V, m, v));
        return;
    }
    else{
        vector<int> tmp1 = v;
        vector<int> tmp2 = v;
        tmp1.push_back(0);
        tmp2.push_back(1);
        t(currentWeight, m+1, tmp1);
        
        t(currentWeight + W[m], m+1, tmp2);
    }
}
int main(int argc, const char * argv[]) {
    cin>>w>>n;
    vector<double> v;
    vector<double> w;
    for(int i=0; i<n; i++){
        double vi;
        cin>>vi;
        v.push_back(vi);
    }
    for(int i=0; i<n; i++){
        double wi;
        cin>>wi;
        w.push_back(wi);
    }
    for(int i=0; i<n; i++){
        data.push_back({w[i], v[i]});
    }
    sort(data.begin(), data.end());
    for(int i=0; i<n; i++){
        W[i] = data[i].first;
        V[i] = data[i].second;
    }
    vector<int> p;
    t(0, 0, p);
    printf("%.4f", ans);
    //cout<<ans<<endl;
    return 0;
}
/*
 10.0 4
 1.2 3.4 6.3 1.3
 4.2 1.4 6.7 4.3
 
 */
