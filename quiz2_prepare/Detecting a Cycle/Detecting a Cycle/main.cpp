//
//  main.cpp
//  Detecting a Cycle
//
//  Created by Metis Sotangkur on 4/6/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> G[1010];
int N,E;
bool isVisitted[1010];
bool ans = false;
void dfs(int now, int last){
    if(isVisitted[now]){
        ans = true;
        return;
    }
    isVisitted[now] = true;
    for(auto x:G[now]){
        if(x==last) continue;
        else{
            dfs(x, now);
        }
    }
}
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        cin>>N>>E;
        ans = false;
        for(int i=0; i<1010; i++){
            G[i].clear();
        }
        for(int i=0; i<E; i++){
            int a, b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for(int i=0; i<N; i++){
            isVisitted[i] = false;
        }
        for(int i=0; i<N; i++){
            if(!isVisitted[i]){
                dfs(i, -1);
            }
        }
        if(ans) cout<<"YES"<<endl;
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
