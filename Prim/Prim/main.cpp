//
//  main.cpp
//  Prim
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> G[1010];
int adjMTX[1010][1010];
int p[1010];
bool inMST[1010];
int w[1010][1010];
int v, e;
vector<int> prim(){
    vector<int> d(1010);
    for(int i=1; i<=v; i++){
        d[i] = 1000000; //infinite
        p[i] = -1;
        inMST[v] = false;
    }
    d[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=1; i<=v; i++){
        pq.push(make_pair(d[i], i));
    }
    while(pq.size()>0){
        pair<int, int> tmp = pq.top();
        pq.pop();
        inMST[tmp.second] = true;
        for(auto x : G[tmp.second]){
            if(!inMST[x] && w[tmp.second][x] < d[x]){
                d[x] = w[tmp.second][x];
                pq.
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
