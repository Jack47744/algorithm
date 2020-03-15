//
//  main.cpp
//  Perimeter
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> G[1010];
vector<int> dis(1000);
int n, e, k;
int bfs(){
    for(int i=1; i<=n; i++){
        dis[i] = -1;
    }
    queue<int> q;
    dis[0] = 0;
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
    int count = 0;
    for(int i=1; i<=n; i++){
        if(dis[i] == k) count++;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    cin>>n>>e>>k;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout<<bfs()<<endl;
    return 0;
}
/*
 3 4 1
 0 1
 1 2
 1 3
 0 3
 */
