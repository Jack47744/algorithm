//
//  main.cpp
//  IKea
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<set<int>> G2[1010];
int n, e;
bool f(vector<vector<int>> G){
    vector<int> tmp;
    for(int i=0; i<n; i++){
        int number;
        cin>>number;
        tmp.push_back(number-1);
    }
    set<int> previousSet;
    previousSet.insert(tmp[0]);
    for(int i=1; i<tmp.size(); i++){
       // cout<<i<<" ";
        for(auto x : G[tmp[i]]){
            //cout<<x<<" ";
            if(previousSet.find(x)!=previousSet.end()){
                return false;
            }
        }
       // cout<<endl;
        previousSet.insert(tmp[i]);
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cin>>n>>e;
    //map<int, set<int>> mp;
    vector<vector<int>> G(n);
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        a-=1;
        b-=1;
        G[a].push_back(b);
    }
   /* for(int i=0; i<n; i++){
        for(auto x : G[i]) cout<<x<<" ";
        cout<<endl;
    }*/
    for(int j=0; j<5; j++){
        if(f(G)) cout<<"SUCCESS"<<endl;
        else cout<<"FAIL"<<endl;
        
    }
    return 0;
}
