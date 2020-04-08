//
//  main.cpp
//  cycle in tree
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int dis[100100];
bool checked[100100];
int n;
vector<int> G[100100];
void dfs(int now, int last, int count){
    if(checked[now]){
        cout<<count - dis[now]<<"\n";
        //for(int i=0; i<n; i++) cout<<dis[i]<<" ";
        exit(0);
    }
    dis[now] = count;
    checked[now] = true;
    for(auto x : G[now]){
        if(x == last) continue;
        else dfs(x, now, count + 1);
    }
}

int main(int argc, const char * argv[]) {
    
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1, 0);
    
    return 0;
}
/*
 9
 0 1
 0 2
 1 3
 1 4
 2 5
 2 6
 2 7
 4 5
 5 8
 */
