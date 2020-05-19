//
//  main.cpp
//  subgraph_isomorphism
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
int MtxOfG[1000][1000];
int MtxOfH[1000][1000];
map<int, int> E1;
map<int, int> E2;
bool checkIso(map<int, int> mp, map<int, int> mp2){
    cout<<"is checked"<<endl;
    for(auto x : E2){
        if(MtxOfG[mp[x.first]][mp[x.second]] == 0){
            cout<<"A"<<endl;
            return false;
        }
    }
    for(auto x : E1){
        if(mp2.find(x.first) != mp2.end() and mp2.find(x.second) != mp2.end()){
            if(MtxOfH[mp2[x.first]][mp2[x.second]] == 0){
                cout<<"B"<<endl;
                return false;
            }
        }
    }
    cout<<"gonna true"<<endl;
    return true;
}
bool f(int step, map<int, int> mp, map<int, int> mp2, set<int> s){
    cout<<step<<endl;
    if(step == v2){
        cout<<"reach"<<endl;
        if(checkIso(mp, mp2)){
            cout<<"just true"<<endl;
            return true;
        }
    }
    for(int i=0; i<v1; i++){
        if(s.find(i) != s.end()) continue;
        if(AdjOfH[step].size() != AdjOfG[i].size()) continue;
        bool isContinue = false;
        for(auto v : AdjOfH[step]){
            if(mp.find(v) != mp.end() and AdjOfG[mp[step]][mp[v]] == 0) isContinue = true;
            if(isContinue) break;
        }
        if(isContinue) continue;
        map<int, int> tmp = mp;
        map<int, int> tmp2 = mp2;
        set<int> s2 = s;
        mp[step] = i;
        mp2[i] = step;
        s2.insert(i);
        f(step+1, tmp, tmp2, s2);
    }
    cout<<"gonna false"<<endl;
    return false;
}
int main(int argc, const char * argv[]) {
    cin>>v1>>e1;
    int count = 0;
    map<int, int> pp;
    for(int i=0; i<e1; i++){
        int a, b;
        cin>>a>>b;
        int tmpA, tmpB;
        if(pp.find(a) == pp.end()){
            tmpA = count;
            pp[a] = tmpA;
            count++;
        }
        else{
            tmpA = pp[a];
        }
        if(pp.find(b) == pp.end()){
            tmpB = count;
            pp[b] = tmpB;
            count++;
        }
        else{
            tmpB = pp[b];
        }
        MtxOfG[tmpB][tmpA] = 1;
        MtxOfG[tmpA][tmpB] = 1;
        AdjOfG[tmpB].push_back(tmpA);
        AdjOfG[tmpA].push_back(tmpB);
        E1[tmpB] = tmpA;
        E1[tmpA] = tmpB;
    }
   /* for(int i=0; i<v1; i++){
        cout<<i<<" : ";
        for(auto x:AdjOfG[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }*/
    cin>>v2>>e2;
    count = 0;
    pp.clear();
    for(int i=0; i<e2; i++){
        int a, b;
        cin>>a>>b;
        int tmpA, tmpB;
        if(pp.find(a) == pp.end()){
            tmpA = count;
            pp[a] = tmpA;
            count++;
        }
        else{
            tmpA = pp[a];
        }
        if(pp.find(b) == pp.end()){
            tmpB = count;
            pp[b] = tmpB;
            count++;
        }
        else{
            tmpB = pp[b];
        }
        MtxOfH[tmpB][tmpA] = 1;
        MtxOfH[tmpA][tmpB] = 1;
        AdjOfH[tmpB].push_back(tmpA);
        AdjOfH[tmpA].push_back(tmpB);
        E2[tmpA] = tmpB;
        E2[tmpB] = tmpA;
    }
    map<int, int> mp;
    map<int, int> mp2;
    set<int> s;
    if(f(0, mp, mp2, s)) cout<<"YES";
    else cout<<"NO";
    return 0;
}
/*
 4 4
 400 300
 300 200
 300 100
 100 200
 3 3
 1 3
 3 8
 1 8
 */
