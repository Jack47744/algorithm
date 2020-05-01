//
//  main.cpp
//  Team Work
//
//  Created by Metis Sotangkur on 4/17/20.
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
    for(int i=0; i<M; i++) cin>>data[i];
    vector<vector<int>> v(N);
    sort(data, data+M);
    for(int i=0; i<M; i++){
        if(v[i%N].size() == 0) v[i%N].push_back(data[i]);
        else v[i%N].push_back(data[i] + v[i%N][v[i%N].size()-1]);
    }
    double ans = 0;
    for(auto x:v){
        for(auto y:x) ans += y;
    }
    ans/=M;
    printf("%.3lf\n", ans);
    return 0;
}
