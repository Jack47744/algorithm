//
//  main.cpp
//  Detecting a Cycle
//
//  Created by Metis Sotangkur on 3/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
char color[1001];

bool isDag(vector<vector<int>> G, int node, set<pair<int, int>> pairOfPoint){
    color[node] = 'G';
    for(auto x : G[node]){
        if(color[x] == 'G' && pairOfPoint.find({node, x})==pairOfPoint.end()) return false;
        if(color[x] == 'W'){
            pairOfPoint.insert({node, x});
            pairOfPoint.insert({x, node});
            if(!isDag(G, x, pairOfPoint)) return false;
        }
    }
    //cout<<"\n";
    color[node] = 'B';
    return true;
}
bool bfsMain(vector<vector<int>> G){
    for(int i=0; i<G.size(); i++) color[i] = 'W';
    set<pair<int, int>> pairOfPoint;
    for(int i=0; i<G.size(); i++){
        if(color[i] == 'W'){
            if(!isDag(G, i, pairOfPoint)) return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    //vector<bool> ans;
    for(int i=0; i<T; i++){
        int N, E;
        cin>>N>>E;
        bool ans = false;
        vector<vector<int>> G(N);
        for(int j=0; j<E; j++){
            int x, y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(!bfsMain(G)) ans = true;
        else ans = false;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //cout<<"\n";
    //for(auto x:ans) cout<<x<<endl;
    return 0;
}
/*
 4
 4 0
 4 4
 2 3
 0 1
 1 2
 2 0
 4 3
 0 1
 1 2
 2 0
 4 1
 1 3
 */
