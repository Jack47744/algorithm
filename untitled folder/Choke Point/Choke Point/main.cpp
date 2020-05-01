//
//  main.cpp
//  Choke Point
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
vector<int> G[100001];
int ans[100100];
int myCount[100100];
int startNode;
vector<int> ppp[100100];
map<pair<int, int>, int> mp;
int dfs(int now, int last){
    int s = 0;
    for(auto x:G[now]){
        if(x==last) continue;
        else s+=dfs(x, now);
    }
    mp[{now, last}] = s;
    return s;
}
int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    for(int i=0; i<n; i++){
        for(auto x:G[i]){
            ppp[i].push_back(mp[{i, x}]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            
        }
    }
    
    
    
    
    return 0;
}
