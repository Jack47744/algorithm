//
//  main.cpp
//  Kruskal
//
//  Created by Metis Sotangkur on 4/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, Q;
int p[5050], h[5050];
int ans[5050];
int findSet(int a){
    while(p[a]!=a) a = p[a];
    return p[a];
}
void unionSet(int a, int b){
    if(h[a]>h[b]){
        p[b] = a;
    }
    else{
        p[a] = b;
        if(h[a] == h[b]) h[b]++;
    }
}
int main(int argc, const char * argv[]) {
    cin>>N>>M>>Q;
    for(int i=0; i<N; i++){
        p[i] = i;
        h[i] = 0;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int edgeNumber = 0;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({c, {a, b}});
    }
    int k = N;
    //cout<<"pq has size of "<<pq.size()<<"\n";
    while(edgeNumber<N-1){
        
        pair<int, pair<int, int>> tmp = pq.top();
        pq.pop();
        int tmpW = tmp.first;
        int tmpA = tmp.second.first;
        int tmpB = tmp.second.second;
        //cout<<tmpA<<" "<<tmpB<<" weight is "<<tmpW<<" pq has size of "<<pq.size()<<"\n";
        if(findSet(tmpA)!=findSet(tmpB)){
            edgeNumber++;
            unionSet(findSet(tmpA), findSet(tmpB));
            ans[--k] = tmpW;
        }
        
    }
    while(Q--){
        int q;
        cin>>q;
        cout<<ans[q]<<"\n";
    }
    return 0;
}
/*
 5 6 4
 0 1 20
 0 2 10
 2 3 30
 1 3 10
 2 4 40
 3 4 50
 1
 2
 3
 4
 */
