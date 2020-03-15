//
//  main.cpp
//  Choke Point
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int n;
vector<int> G[100100];
vector<int> checked(100100);
vector<int> ans(100100);
vector<pair<int, int>> edge;
int sumOfNode = 0;
map<pair<int, int>, pair<int, int>> edgeData;
void dfs2(int node, int ngNode){
    sumOfNode++;
    for(auto x:G[node]){
        if(x!=ngNode){
            dfs2(x, node);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        edge.push_back({a, b});
    }
    for(int i=0; i<edge.size(); i++){
        pair<int, int> tmp = edge[i];
        sumOfNode = 0;
        vector<int> checked(100100);
        dfs2(tmp.first, tmp.first);
        int left =sumOfNode;
        int right = n - 1 - left;
        edgeData[{tmp.first, tmp.second}] = {left, right};
        edgeData[{tmp.second, tmp.first}] = {right, left};
    }
    for(int i=0; i<n; i++){
        ans[i] += n-1;
        int sum = 0;
        vector<int> v;
        for(auto x : G[i]){
            v.push_back(edgeData[{i, x}].second);
            //cout<<edgeData[{i, x}].second<<endl;
        }
        for(int j=0; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                sum += v[j]*v[k];
            }
        }
        ans[i]+=sum;
        //cout<<"\n";
        
    }
    //cout<<"\n";
    for(int i=0; i<n; i++) cout<<ans[i]<<endl;
    
    return 0;
}
