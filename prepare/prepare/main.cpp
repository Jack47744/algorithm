//
//  main.cpp
//  prepare
//
//  Created by Metis Sotangkur on 3/15/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
vector<int> G[100100];
int count2[100100];
bool checked[100100];
void dfs(int now, int last, int count){
   // cout<<now<<" "<<last<<" "<<count<<endl;
    if(checked[now]){
        cout<<count - count2[now]<<endl;
        exit(0);
        return;
       
    }
    checked[now] = true;
    count2[now] = count;
    for(auto x : G[now]){
        if(x == last) continue;
        else{
            dfs(x, now, count+1);
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        count2[i] = 0;
        checked[i] = false;
    }
    
    dfs(0, -1, 1);
}
