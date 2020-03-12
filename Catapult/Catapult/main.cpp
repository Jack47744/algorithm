//
//  main.cpp
//  Catapult
//
//  Created by Metis Sotangkur on 3/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fOfGT[1001];
char color[1001];
char color2[1001];
int t = 0;
int count2 = 0;
void DFS2(vector<vector<int>> G, int node){
    ++t;
    color[node] = 'G';
    for(auto x:G[node]){
        if(color[x] == 'W'){
            DFS2(G, x);
        }
    }
    color[node] = 'B';
    fOfGT[node] = ++t;
}
void DFS3(vector<vector<int>> G, int node){
    color2[node] = 'G';
    for(auto x:G[node]){
        if(color2[x] == 'W'){
            DFS3(G, x);
        }
    }
    color2[node] = 'B';
    count2++;
}
void DFS(vector<vector<int>> G){
    for(int i=0; i<G.size(); i++) color[i] = 'W';
    for(int i=0; i<G.size(); i++){
        if(color[i] == 'W'){
            DFS2(G, i);
        }
    }
}
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<vector<int>> G(N), GT(N);
    for(int i=0; i<N; i++){
        int M;
        cin>>M;
        for(int j=0; j<M; j++){
            int node;
            cin>>node;
            G[i].push_back(node);
            GT[node].push_back(i);
        }
    }
    vector<int> ans;
    DFS(GT);
    vector<pair<int, int>> v;
    for(int i=0; i<N; i++){
        v.push_back({fOfGT[i], i});
    }
    sort(v.begin(), v.end());
    //for(int i = v.size()-1; i>=0; i--)cout<<v[i].second<<" : time is "<<v[i].first<<endl;
    for(int i=0; i<G.size(); i++) color2[i] = 'W';
  //  cout<<"size of v is "<<v.size()<<endl;
    for(int i=G.size()-1; i>=0; i--){
        //cout<<i<<endl;
        count2=0;
       // cout<<v[i].second<<" time is "<<v[i].first <<endl;
        if(color2[v[i].second] == 'W'){
            DFS3(G, v[i].second);
            ans.push_back(count2);
        }
    }
    
    sort(ans.begin(), ans.end());

   
    for(auto x:ans) cout<<x<<" ";
    
    
    return 0;
}
/*
 5
 2 1 2
 2 0 3
 1 3
 1 2
 0
 
 3
 1 1
 1 0
 0
 
 3
 1 1
 1 2
 1 0
 */
