//
//  main.cpp
//  เมืองใกลสุด
//
//  Created by Metis Sotangkur on 4/29/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> G[1010];
int data[1010][1010];
int d[1010];
int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a;
            cin>>a;
            if(a>0){
                G[i].push_back(j);
                data[i][j] = a;
            }
        }
    }
    
    for(int i=1; i<N; i++){
        d[i] = 100000000;
    }
    d[0] = 0;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            for(auto x:G[j]){
                if(d[j] + data[j][x] < d[x]){
                    d[x] = d[j] + data[j][x];
                }
            }
        }
    }
    
    /*
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[0] = 0;
    pq.push({0, 0});
    for(int i=1; i<N; i++){
        d[i] = 100000000;
        pq.push({d[i], i});
    }
    while(pq.size()>0){
        int tmp = pq.top().second;
        pq.pop();
        for(auto x:G[tmp]){
            if(d[tmp] + data[tmp][x] < d[x]){
                d[x] = d[tmp] + data[tmp][x];
                pq.push({d[x], x});
            }
        }
        
    }*/
    
    int ans = 0;
    for(int i=1; i<N; i++) ans = max(d[i], ans);
    if(ans == 0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
/*
 5
 0 1 -1 -1 7
 -1 0 2 3 5
 -1 -1 0 4 -1
 -1 4 2 0 -1
 -1 -1 -1 4 0
 */
