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
map<char, vector<char>> G;
map<char, vector<char>> H;
vector<char> V1;
vector<char> V2;
set<pair<char, char>> E1;
set<pair<char, char>> E2;
int visitNode = 0;
bool isoCheck(map<char, char> mp){
    for(auto x : E2){
        if(E1.find({mp[x.first], mp[x.second]}) == E1.end()) return false;
    }
    return true;
}
bool isSubgraphIso(int step, map<char, char> mp, set<char> s){
    visitNode++;
    char vertexOfH = V2[step];
    if(v2>v1) return false;
    if(step == v2){
        if(isoCheck(mp)){
            for(auto x:mp){
                cout<<x.first<<" is mapped with "<<x.second<<endl;
            }
            return true;
        }
    }
    for(auto x:V1){
        if(s.find(x) != s.end()) continue;  // checked if the map is one-to-one
        
        bool isContinue = false;
        for(auto y : H[vertexOfH]){
            if(mp.find(y) != mp.end() and E1.find({x, mp[y]}) == E1.end()){
                isContinue = true;
                break;
            }
        }
        if(isContinue) continue;
        
        int unmappedH = 0, unmappedG = 0;
        for(auto y : H[vertexOfH]){
            if(mp.find(y) == mp.end()) unmappedH++;
        }
        for(auto y : G[x]){
            if(s.find(y) == s.end()) unmappedG++;
        }
        if(unmappedH>unmappedG) continue;
        
        map<char, char> tmp = mp;
        set<char> tmp2 = s;
        tmp[vertexOfH] = x;
        tmp2.insert(x);
        if(isSubgraphIso(step + 1, tmp, tmp2)) return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    cout<<"input graph G"<<endl;
    cin>>v1>>e1;
    set<char> tmp2;
    for(int i=0; i<e1; i++){
        char a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        E1.insert({a, b});
        E1.insert({b, a});
        tmp2.insert(a);
        tmp2.insert(b);
    }
    for(auto x:tmp2) V1.push_back(x);
    cout<<"input graph H"<<endl;
    cin>>v2>>e2;
    set<char> tmp;
    for(int i=0; i<e2; i++){
        char a, b;
        cin>>a>>b;
        H[a].push_back(b);
        H[b].push_back(a);
        E2.insert({a, b});
        E2.insert({b, a});
        tmp.insert(a);
        tmp.insert(b);
    }
    for(auto x:tmp){
        V2.push_back(x);
    }
    map<char, char> mp;
    set<char> s;
    if(isSubgraphIso(0, mp, s)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<"visit "<<visitNode<<" nodes."<<endl;
    return 0;
}
/*
 5 7
 a b
 a d
 a e
 b c
 b e
 c d
 d e
 
 4 5
 f g
 f h
 g h
 g i
 h i
 
 
 4 4
 a b
 a c
 b c
 c d
  
 9 9
 e j
 j f
 j i
 j l
 k l
 i g
 i h
 i m
 g h
 
 5 5
 a b
 b c
 c d
 d e
 e a
 
 7 9
 f g
 f l
 l h
 l j
 l k
 k j
 g j
 g i
 j i
 
 
 7 9
 j f
 j k
 j g
 j i
 i g
 k l
 g l
 g h
 l h
 
 13 14
 A B
 B C
 B D
 D E
 E F
 F H
 H G
 G D
 F L
 L K
 K J
 J I
 I H
 K M
 
 
 16 17
 a b
 b c
 c d
 d e
 e f
 f a
 e i
 i h
 h j
 j k
 k l
 l m
 m i
 l n
 n o
 o p
 n q
 
 13 13
 A C
 C D
 D B
 D E
 E F
 F G
 G H
 H I
 I J
 J E
 G K
 K L
 K M
 
 
 //////
 8 11
 a g
 a f
 a b
 b c
 c e
 e h
 e i
 h i
 h f
 h g
 i g
 
 8 10
 k j
 k l
 j q
 j p
 p o
 p n
 o m
 n m
 m l
 l q
 //////
 8 11
 a g
 a f
 a b
 b c
 c e
 e h
 e i
 h i
 h f
 h g
 i g
 
 7 8
 k j
 k l
 l m
 m o
 m n
 o p
 n p
 j p
 ///////
 
 
 */
