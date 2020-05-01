//
//  main.cpp
//  Game Ranking
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int N, P;
vector<int> G[5010];
vector<int> GT[5010];
int f[5050];
int t = 0;
bool isVisit[5010];
void dfsOfGT(int now, int last){
    t++;
    for(auto x : GT[now]){
        if(x == last) continue;
        else dfsOfGT(x, now);
    }
    f[now] = ++t;
    
}
void mainDfsOfGT(){
    for(int i=0; i<N; i++) isVisit[i] = false;
    for(int i=0; i<N; i++){
        if(!isVisit[i]){
            dfsOfGT(i, -1);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>N>>P;
    for(int i=0; i<P; i++){
        int a,b ;
        cin>>a>>b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
    for(int i=0; i<N; i++) f[i] = 0;
    return 0;
}
