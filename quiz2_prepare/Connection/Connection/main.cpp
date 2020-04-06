//
//  main.cpp
//  Connection
//
//  Created by Metis Sotangkur on 4/6/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> G[1010];
int ans[1010];
int dis[1010];
int N, E, K;
void bfs(int start){
    //cout<<start<<endl;
    for(int i=0; i<N; i++) dis[i] = -1;
    dis[start] = 0;
    queue<int> q;
    q.push(start);
    while(q.size()>0){
        int tmp = q.front();
        q.pop();
        for(auto v:G[tmp]){
            if(dis[v]==-1){
                dis[v] = dis[tmp]+1;
                q.push(v);
            }
        }
    }
    for(int i=0; i<N; i++){
        if(dis[i]<=K and dis[i]>-1){
            ans[start]+=1;
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
    for(int i=0; i<N; i++){
        bfs(i);
    }
    int maxAns = 0;
    for(int i=0; i<N; i++){
        maxAns = max(maxAns, ans[i]);
    }
    cout<<maxAns<<endl;
    
    return 0;
}
/*
 7 8 2
 0 6
 1 6
 1 5
 1 4
 2 3
 3 4
 4 5
 5 6
 */
