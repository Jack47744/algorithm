//
//  main.cpp
//  Component Count
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool visit[10100];
vector<int> G[10100];
void dfs(int startNode){
    visit[startNode] = true;
    for(auto x : G[startNode]){
        if(!visit[x]){
            dfs(x);
        }
    }
}
int main(int argc, const char * argv[]) {
    int v, e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int a, b;
        scanf("%d %d",&a,&b);
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0; i<v; i++) visit[i] = false;
    int ans = 0;
    for(int i=0; i<v; i++){
        if(!visit[i]){
            dfs(i);
            ans++;
        }
    }
    
    cout<<ans<<endl;
    
    
    //cout<<mainDfs(G)<<endl;
}
