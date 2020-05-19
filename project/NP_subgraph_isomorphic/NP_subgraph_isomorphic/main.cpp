//
//  main.cpp
//  NP_subgraph_isomorphic
//
//  Created by Metis Sotangkur on 5/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
int v1, e1, v2, e2;
vector<int> AdjOfG[1000];
vector<int> AdjOfH[1000];
set<pair<int, int>> E1;
set<pair<int, int>> E2;
bool subgraphIso(map<int, int> mp, map<int, int> mp2){
    for(auto x : E2){
        if(E1.find({mp[x.first], mp[x.second]}) == E1.end()) return false;
    }
    /*for(auto x : E1){
        if(mp2.find(x.first) != mp2.end() and mp2.find(x.second) != mp2.end()){
            if(E2.find({mp2[x.first], mp2[x.second]}) == E2.end()) return false;
        }
    }*/
    return true;
}
int main(int argc, const char * argv[]) {
    cout<<"input G"<<endl;
    cin>>v1>>e1;
    for(int i=0; i<e1; i++){
        int a, b;
        cin>>a>>b;
        AdjOfG[a].push_back(b);
        AdjOfG[b].push_back(a);
        E1.insert({a, b});
        E1.insert({b, a});
    }
    cout<<"input H "<<endl;
    cin>>v2>>e2;
    for(int i=0; i<e2; i++){
        int a, b;
        cin>>a>>b;
        AdjOfH[a].push_back(b);
        AdjOfH[b].push_back(a);
        E2.insert({a, b});
        E2.insert({b, a});
    }
    map<int, int> mp = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}};
    map<int, int> mp2;
    for(auto x: mp){
        mp2[x.second] = x.first;
    }
    cout<<subgraphIso(mp, mp2)<<endl;
    return 0;
}
