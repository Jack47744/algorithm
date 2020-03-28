//
//  main.cpp
//  Kruskal
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int V, E;
int people[1010];
int edge[1010][1010];
bool inMST[1010];
vector<int> G[1010];
int minIndex(vector<int> d){
    int ans = -1;
    int k = -1;
    for(int i=1; i<=V; i++){
        if(d[i]>k){
            k = d[i];
            ans = i;
        }
    }
    return ans;
}
vector<int> kruskal(){
    vector<int> d(1010);
    for(int i=1; i<=V; i++) {
        d[i] = 1000000;
        inMST[i] = false;
    }
    d[1] = 0;
    for(int i=1; i<=V; i++){
        int u = minIndex(d);
        d[u] = 1000000;
        inMST[u] = true;
        for(int v = 1; v<=V; v++){
            if(!inMST[v] and G[u][v]<d[v]){
                d[v] = G[u][v];
            }
        }
    }
    for(int i=2; i<=V; i++){
        d[i] = d[i]*people[i];
    }
    return d;
}
int main(int argc, const char * argv[]) {
    cin>>V>>E;
    for(int i=2; i<=V; i++) cin>>people[i];
    for(int i=0; i<E; i++){
        int a, b, length;
        cin>>a>>b>>length;
        edge[a][b] = length;
        edge[b][a] = length;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans = kruskal();
}
