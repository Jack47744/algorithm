//
//  main.cpp
//  Connection
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dis[1010];
int N, E, K;
vector<int> G[1010];
int ans[1010];
void bfs(int node){
    for(int i=0; i<N; i++) dis[i] = -1;
    dis[node] = 0;
    queue<int> q;
    q.push(node);
    while(q.size()>0){
        int tmp = q.front();
        q.pop();
        for(auto x: G[tmp]){
            if(dis[x] == -1){
                dis[x] = dis[tmp] + 1;
                q.push(x);
            }
        }
    }
    for(int i=0; i<N; i++){
        if(dis[i]<=K and dis[i]>=0){
            ans[node]++;
        }
    }
    
}
int main(int argc, const char * argv[]) {
    cin>>N>>E>>K;
    for(int i=0; i<E; i++){
        int a, b;
        cin>>a>>b; 
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int p = 0;
    for(int i=0; i<N; i++) ans[i] = 0;
    for(int i=0; i<N; i++) bfs(i);
    for(int i=0; i<N; i++) p = max(p, ans[i]);
    cout<<p<<endl;
    return 0;
}
