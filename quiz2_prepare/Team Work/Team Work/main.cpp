//
//  main.cpp
//  Team Work
//
//  Created by Metis Sotangkur on 4/6/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, M;
    cin>>N>>M;
    vector<int> data(M);
    for(int i=0; i<M; i++){
        cin>>data[i];
    }
    sort(data.begin(), data.end());
    /*for(int i=0; i<data.size(); i++){
        cout<<data[i]<<endl;
    }*/
    vector<vector<int>> v(N);
    for(int i=0; i<M; i++){
        if(v[i%N].size()==0){
            v[i%N].push_back(data[i]);
        }
        else{
            int lastDataIndex = v[i%N].size()-1;
            v[i%N].push_back(v[i%N][lastDataIndex] + data[i]);
        }
    }
    double k = 0;
    for(int i=0; i<N; i++){
        for(auto x:v[i]){
            //cout<<x<<" ";
            k+=x;
        }
        //cout<<"\n";
    }
    k/=M;
    printf("%.3lf\n", k);
    return 0;
}
