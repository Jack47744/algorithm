//
//  main.cpp
//  Component Count
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> G[10010];
bool checked[10010];
int v, e;
void dfs(int now, int last){
    if(checked[now]) return;
    checked[now] = true;
    for(auto x: G[now]){
        if(x == last) continue;
        else dfs(x, now);
    }
}
int main(int argc, const char * argv[]) {
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    for(int i=0; i<=v; i++) checked[i] = false;
    for(int i=1; i<=v; i++){
        if(!checked[i]){
            ans++;
            dfs(i, -1);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
