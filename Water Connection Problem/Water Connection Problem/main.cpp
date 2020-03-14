//
//  main.cpp
//  Water Connection Problem
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
map<pair<int, int>, int> sizeData;
queue<int> endPoints;
int check[1000];
int endPoint = 0;
int minSize = 100000;
bool isEnd = false;
int bfs(vector<vector<int>> G, int startNode){
    check[startNode] = 1;
    for(auto x : G[startNode]){
        minSize = min(sizeData[{startNode, x}], minSize);
        if(!check[x]){
            bfs(G, x);
        }
    }
    if(!isEnd){
        endPoint = startNode;
        isEnd = true;
    }
    
    
    return minSize;
}
int main(int argc, const char * argv[]) {
    int n, p;
    cin>>n>>p;
    vector<vector<int>> G(n+1);
    for(int i=0; i<p; i++){
        int a, b, size;
        cin>>a>>b>>size;
        G[a].push_back(b);
        G[b].push_back(a);
        sizeData[{a, b}] = size;
        sizeData[{b ,a}] = size;
        
    }
    vector<int> tmp;
    for(int i = 1; i<=n; i++){
        if(G[i].size()==1) tmp.push_back(i);
    }
    for(int i = 1; i<=1000; i++) check[i] = 0;
    vector<pair<int, pair<int, int>>> ans;
    for(int i=0; i<tmp.size(); i++){
        int startNode = tmp[i];
        endPoint = 0;
        minSize = 100000;
        isEnd = false;
        int tmpSize;
        if(!check[startNode]){
            tmpSize = bfs(G, startNode);
            minSize = tmpSize;
            ans.push_back({minSize, {startNode, endPoint}});
        }
        
        
    }
    for(auto x : ans){
        cout<<x.second.first<<" "<<x.second.second<<" "<<x.first<<endl;
    }
    
    
    return 0;
}
