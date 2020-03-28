//
//  main.cpp
//  Graph Coloring
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int N, E;
vector<int> G[51];
int ans = 100;
void f(int x[], int now){
    if(now > N){
        bool checked[51];
        for(int i=0; i<N; i++){
            checked[i] = false;
        }
        int p = 0;
        for(int i=0; i<N; i++){
           // cout<<x[i]<<" ";
            if(!checked[x[i]]){
                checked[x[i]] = true;
                p++;
            }
        }
        //cout<<"\n";
        ans = min(p, ans);
        return;
    }
    bool isBreak = false;
    for(int i=0; i<=now; i++){
        for(auto v : G[now]){
            if(x[v]==i){
                isBreak = true;
                break;
            }
        }
        if(isBreak){
            isBreak = false;
            continue;
        }
        else{
            x[now] = i;
            f(x, now+1);
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
    int color[N+1];
    for(int i=0; i<N; i++) color[i] = -1;
    f(color, 0);
    cout<<ans<<endl;
}
