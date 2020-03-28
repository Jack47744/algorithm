//
//  main.cpp
//  Mass Relay
//
//  Created by Metis Sotangkur on 3/27/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, Q, D;
vector<int> G[5050];
int w[5050][5050];
int main(int argc, const char * argv[]) {
    cin>>N>>M>>Q;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        w[a][b] = c;
        w[b][a] = c;
        G[b].push_back(a);
        G[a].push_back(b);
    }
    for(int q=0; q<Q; q++){
        cin>>D;
        
    }
    return 0;
}
