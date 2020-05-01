//
//  main.cpp
//  quiz_2_1
//
//  Created by Metis Sotangkur on 4/19/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, e;
vector<int> G[100100];
bool check[100100];
bool dfs(int now, int last){
    //cout<<now<<" "<<last<<endl;
    if(check[now]) return false;
    //cout<<"pass check"<<endl;
    if(G[now].size()!=1 and G[now].size()!=2) return false;
    //cout<<"pass size"<<endl;
    check[now] = true;
    for(auto x:G[now]){
        if(x==last) continue;
        if(!dfs(x, now)) return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    cin>>n>>e;
    int count = 0;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    /*for(int i=0; i<n; i++){
        cout<<i<<" : ";
        for(auto x:G[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }*/
    for(int i=0; i<n; i++){
        check[i] = false;
    }
    for(int i=0; i<n; i++){
        if(!check[i]){
            if(G[i].size() == 0){
                count++;
                check[i] = true;
            }
            else if(G[i].size()==1 or G[i].size() == 2){
                if(dfs(i, -1)){
                    count++;
                }
            }
        }
        //cout<<"..."<<endl;
    }
    cout<<count<<endl;
    return 0;
}
