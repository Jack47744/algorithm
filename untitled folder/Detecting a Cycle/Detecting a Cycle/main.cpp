//
//  main.cpp
//  Detecting a Cycle
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> G[1010];
bool isVisit[1010];
int N, E;
bool hasCircleDfs(int node, int last){
    if(isVisit[node]) return true;
    isVisit[node] = true;
    for(auto x : G[node]){
        if(x == last) continue;
        if(hasCircleDfs(x, node)) return true;
    }
    return false;
}
bool mainDfs(){
    for(int i=0; i<N; i++) isVisit[i] = false;
    for(int i=0; i<N; i++){
        if(!isVisit[i]){
            if(hasCircleDfs(i, -1)) return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        cin>>N>>E;
        for(int i=0; i<N; i++) G[i].clear();
        for(int i=0; i<E; i++){
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(mainDfs()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
