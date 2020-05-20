//
//  main.cpp
//  subgraph_algo
//
//  Created by Metis Sotangkur on 5/18/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int v1, e1, v2, e2;
vector<int> G[100];
vector<int> H[100];
set<pair<int, int>> E1;
set<pair<int, int>> E2;
int visitNode = 0;
bool isoCheck(map<int, int> mp){
    for(auto x : E2){
        if(E1.find({mp[x.first], mp[x.second]}) == E1.end()) return false;
    }
    return true;
}
bool isSubgraphIso(int step, map<int, int> mp, set<int> s){
    visitNode++;
    if(v2>v1) return false;
    if(step == v2){
        if(isoCheck(mp)){
            for(auto x:mp){
                cout<<x.first<<" is mapped with "<<x.second<<endl;
            }
            return true;
        }
    }
    for(int x=0; x<v1; x++){
        if(s.find(x) != s.end()) continue;  // checked if the map is one-to-one
        
        bool isContinue = false;
        for(auto y : H[step]){
            if(mp.find(y) != mp.end() and E1.find({x, mp[y]}) == E1.end()){
                isContinue = true;
                break;
            }
        }
        if(isContinue) continue;
        
        int unmappedH = 0, unmappedG = 0;
        for(auto y : H[step]){
            if(mp.find(y) == mp.end()) unmappedH++;
        }
        for(auto y : G[x]){
            if(s.find(y) == s.end()) unmappedG++;
        }
        if(unmappedH>unmappedG) continue;
        
        map<int, int> tmp = mp;
        set<int> tmp2 = s;
        tmp[step] = x;
        tmp2.insert(x);
        if(isSubgraphIso(step + 1, tmp, tmp2)) return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    cout<<"input graph G"<<endl;
    cin>>v1>>e1;
    for(int i=0; i<e1; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        E1.insert({a, b});
        E1.insert({b, a});
    }
    cout<<"input graph H"<<endl;
    cin>>v2>>e2;
    for(int i=0; i<e2; i++){
        int a, b;
        cin>>a>>b;
        H[a].push_back(b);
        H[b].push_back(a);
        E2.insert({a, b});
        E2.insert({b, a});
    }
    map<int, int> mp;
    set<int> s;
    if(isSubgraphIso(0, mp, s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<"visit "<<visitNode<<" nodes."<<endl;
    return 0;
}
/*
 example 1
 7 9
 0 2
 2 1
 2 3
 2 6
 1 6
 3 4
 4 6
 4 5
 6 5
 //////
 5 5
 0 1
 1 3
 3 4
 4 2
 2 0
 
 example 2
 5 5
 0 1
 1 2
 2 3
 3 4
 4 0
 /////
 5 4
 0 1
 1 2
 2 3
 3 0
 
 exmaple 3
 8 11
 0 1
 0 4
 0 6
 1 5
 4 5
 4 7
 5 7
 5 2
 7 2
 2 3
 3 6
 /////
 7 8
 1 6
 6 0
 6 3
 0 5
 3 5
 5 2
 2 4
 4 1
 
 example 4
 8 11
 0 1
 0 4
 0 6
 1 5
 4 5
 4 7
 5 7
 5 2
 7 2
 2 3
 3 6
 ///////
 8 10
 0 1
 0 5
 0 6
 1 2
 6 2
 2 3
 3 7
 3 4
 7 5
 4 5
 
 example 5
 16 17
 0 1
 1 2
 2 3
 3 4
 4 5
 5 0
 4 6
 6 7
 7 8
 8 9
 9 10
 10 11
 11 6
 8 12
 12 13
 12 14
 14 15
 ///////
 13 13
 0 1
 1 2
 2 3
 2 4
 4 5
 5 6
 6 7
 7 8
 8 9
 9 4
 6 11
 11 10
 11 12
 */
