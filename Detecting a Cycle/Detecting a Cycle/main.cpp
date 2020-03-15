//
//  main.cpp
//  Detecting a Cycle
//
//  Created by Metis Sotangkur on 3/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
char color[1001];
int checked[1001];
int N, E;
int ppp = 0;
vector<int> G[1001];
void dfs(int now, int last){
    checked[now] = 1;
    for(int i=0; i<G[now].size(); i++){
        if(last == G[now][i]) continue;
        if(checked[G[now][i]]){
            ppp=1;
            return;
        }
        else dfs(G[now][i], now);
    }
}
bool mainDfs(){
    
    ppp = 0;
    for(int i=0; i<N; i++){
        if(!checked[i]){
            dfs(i, -1);
        }
    }
    return ppp;
}
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    vector<bool> ans;
    for(int i=0; i<T; i++){
        
        cin>>N>>E;
        for(int i=0; i<N; i++) checked[i] = 0;
        for(int i=0; i<N; i++) G[i].clear();
        
        for(int j=0; j<E; j++){
            int x, y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        ans.push_back(mainDfs());
        
    }
    cout<<"\n";
    for(auto x:ans){
        if(x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
/*
 4
 4 0
 4 4
 2 3
 0 1
 1 2
 2 0
 4 3
 0 1
 1 2
 2 0
 4 1
 1 3
 */
