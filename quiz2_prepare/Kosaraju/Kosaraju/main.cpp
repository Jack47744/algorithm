//
//  main.cpp
//  Kosaraju
//
//  Created by Metis Sotangkur on 4/7/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int N, t = 0;
char color[1010];
int f[1010];
int myCount = 0;
void dfs(int now, vector<vector<int>> G){
    ++t;
    color[now] = 'G';
    for(auto x: G[now]){
        if(color[x] == 'W'){
            dfs(x, G);
        }
    }
    color[now] = 'B';
    f[now] = ++t;
    myCount++;
}
int main(int argc, const char * argv[]) {
    
    cin>>N;
    vector<vector<int>> G(N);
    vector<vector<int>> GT(N);
    for(int i=0; i<N; i++){
        int M;
        cin>>M;
        for(int j=0; j<M; j++){
            int n;
            cin>>n;
            G[i].push_back(n);
            GT[n].push_back(i);
        }
    }
    for(int i=0; i<N; i++) {
        color[i] = 'W';
        f[i] = 0;
    }
    for(int i=0; i<N; i++){
        if(color[i] == 'W') dfs(i, GT);
    }
    vector<pair<int, int>> ll;
    for(int i=0; i<N; i++){
        ll.push_back({f[i], i});
    }
    sort(ll.begin(), ll.end());
    for(int i=0; i<N; i++) color[i] = 'W';
    vector<int> ans;
    for(int i = N-1; i>=0; i--){
        if(color[ll[i].second] == 'W'){
            myCount = 0;
            dfs(ll[i].second, G);
            ans.push_back(myCount);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x:ans) cout<<x<<" ";
    return 0;
}
