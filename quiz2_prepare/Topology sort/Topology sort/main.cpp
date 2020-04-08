//
//  main.cpp
//  Topology sort
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
vector<int> G[1010];
stack<int> s;
char color[1010];
void dfs(int now){
    color[now] = 'G';
    for(int x : G[now]){
        if(color[x] == 'W'){
            dfs(x);
        }
    }
    color[now] = 'B';
    s.push(now);
}
int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=0; i<N; i++){
        int M;
        cin>>M;
        for(int j=0; j<M; j++){
            int a;
            cin>>a;
            G[a].push_back(i);
        }
    }
    for(int i=0; i<N; i++) color[i] = 'W';
    for(int i=0; i<N; i++){
        if(color[i] == 'W'){
            dfs(i);
        }
    }
    vector<int> ans;
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}
