//
//  main.cpp
//  Task Planning
//
//  Created by Metis Sotangkur on 3/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
char color[1001];
stack<int> ans;
void tsort2(vector<vector<int>> G, int startNode){
    color[startNode] = 'G';
    for(auto x : G[startNode]){
        if(color[x] == 'W'){
            tsort2(G, x);
        }
    }
    color[startNode] = 'B';
    
    ans.push(startNode);
    //cout<<startNode<<endl;
}
void tsort(vector<vector<int>> G){
    for(int i=0; i<G.size(); i++){
        color[i] = 'W';
    }
    for(int i=0; i<G.size(); i++){
        if(color[i] == 'W'){
            tsort2(G, i);
        }
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<vector<int>> adjacencyList(N);
    for(int i=0; i<N; i++){
        int M;
        cin>>M;
        for(int j=0; j<M; j++){
            int node;
            cin>>node;
            adjacencyList[node].push_back(i);
        }
    }
    /*for(int i=0; i<adjacencyList.size(); i++){
        cout<<i<<" : ";
        for(auto x:adjacencyList[i]) cout<<x<<" ";
        cout<<"\n";
    }*/
    tsort(adjacencyList);
    while(ans.size()>0){
        cout<<ans.top()<<" ";
        ans.pop();
    }
    
    return 0;
}
