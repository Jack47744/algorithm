//
//  main.cpp
//  Graph Coloring
//
//  Created by Metis Sotangkur on 4/13/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int N, E;

vector<int> G[51];
int minColor = 51;
void f(int node, vector<int> v, set<int> s){
    
    if(node==N){
        cout<<node<<" "<<s.size()<<" ";
        for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<"\n";
        int k = s.size();
        for(auto i : s){
            cout<<i<<" ";
        }
        cout<<"\n";
        
        
        if(minColor>k){
            minColor = k;
            cout<<k<<"........\n";
        }
        return;
    }
    if(s.size() >= minColor) return;
    for(int i=0; i<=node; i++){
        set<int> tmp = s;
        for(auto x:G[node]){
            if(i!=v[x]){
                v[node] = i;
                tmp.insert(i);
                f(node+1, v, tmp);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> v(N);
    set<int> s;
    s.insert(0);
    for(int i=0; i<N; i++){
        v[i] = -1;
    }
    f(0, v, s);
    cout<<minColor<<endl;
    
}
/*
 
 4 6
 0 1
 0 2
 0 3
 1 2
 1 3
 2 3
 */
