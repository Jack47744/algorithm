//
//  main.cpp
//  Perimeter
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, e, k;
vector<int> G[1010];
int dis[1010];
void bfs(){
    for(int i=1; i<=n; i++) dis[i] = -1;
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(q.size()>0){
        int tmp = q.front();
        q.pop();
        for(auto x : G[tmp]){
            if(dis[x] == -1){
                dis[x] = dis[tmp] + 1;
                q.push(x);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n>>e>>k;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs();
    int count = 0;
    for(int i=0; i<=n; i++){
        if(dis[i] == k) count++;
    }
    cout<<count<<"\n";
    return 0;
}
