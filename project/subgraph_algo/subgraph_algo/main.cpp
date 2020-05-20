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
