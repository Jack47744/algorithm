//
//  main.cpp
//  Connection
//
//  Created by Metis Sotangkur on 3/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N, E, K;
int bfs(vector<vector<int>> G, int startNode, int K, int ans[]){
    vector<int> distance(N);
    for(int i=0; i<G.size(); i++){
        distance[i] = -1;
    }
    queue<int> q;
    q.push(startNode);
    distance[startNode] = 0;
    while(q.size()>0){
        int tmp = q.front();
        q.pop();
        for(auto x : G[tmp]){
            if(distance[x] == -1){
                distance[x] = distance[tmp] + 1;
                q.push(x);
            }
        }
    }
    int count = 0;
    //cout<<"startNode is "<<startNode<<" : ";
    for(int i=0; i<N; i++){
        //cout<<distance[i]<<" ";
        if(distance[i] <= K && distance[i] >= 0){
            count ++;
        }
    }
    //cout<<"  "<<ans[startNode];
    //cout<<"\n";
    return count;
}
int main(int argc, const char * argv[]) {

    cin>>N>>E>>K;
    vector<vector<int>> data(N);
    for(int i=0; i<E; i++){
        int a, b;
        cin>>a>>b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    int maxKNumber = 0;
    int ans[N];
    for(int i=0; i<N; i++) ans[i] = 0;
    for(int i=0; i<N; i++){
        maxKNumber = max(maxKNumber, bfs(data, i, K, ans));
    }

    
    cout<<maxKNumber;
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
