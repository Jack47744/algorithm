//
//  main.cpp
//  IKEA
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, e;
vector<int> G[1010];
vector<int> GT[1010];
int main(int argc, const char * argv[]) {
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
    for(int i=0; i<5; i++){
        vector<int> queries;
        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            queries.push_back(a);
        }
        set<int> s;
        bool ans = true;
        bool isFalse = false;
        for(auto x:queries){
            if(isFalse) break;
            if(GT[x].size() > 0){
                for(auto y:GT[x]){
                    if(s.find(y) == s.end()){
                        isFalse = true;
                        ans = false;
                        break;
                    }
                }
            }
            s.insert(x);
        }
        if(ans) cout<<"SUCCESS\n";
        else cout<<"FAIL\n";
    }
    return 0;
}
