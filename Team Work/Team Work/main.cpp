//
//  main.cpp
//  Team Work
//
//  Created by Metis Sotangkur on 2/24/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, M;
    cin>>N>>M;
    int data[M];
    vector<vector<int>> v(N);
    int data2[N];
    for(int i=0; i<M; i++) cin>>data[i];
    sort(data, data+M);
    int count = 0;
    double ans;
    for(int i=0; i<M; i++){
        data2[i%N] += data[i];
        if(v[i%N].size()==0) v[i%N].push_back(data[i]);
        else v[i%N].push_back(v[i%N][v[i%N].size()-1] + data[i]);
    }
    /*for(int i=0; i<N; i++){
        for(auto x: v[i]) cout<<x<<" ";
        cout<<"\n";
    }*/
    for(int i=0; i<N; i++){
        for(auto x: v[i]) ans+=x;
    }
    ans/=M;
    printf("%.3lf",ans);
    
    return 0;
}
