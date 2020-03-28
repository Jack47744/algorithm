//
//  main.cpp
//  Shortest Path with Negative Edge
//
//  Created by Metis Sotangkur on 3/26/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> G[101];
int w[101][101];
int d[101];
int N, E, s;
void Bellman_Ford(){
    for(int i=0; i<N; i++){
        d[i] = 1000000;
    }
    d[s] = 0;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N; j++){
            for(int k : G[j]){
                if(d[j] + w[j][k] < d[k]){
                    d[k] = d[j] + w[j][k];
                }
            }
        }
    }
    bool hasNegativeCircle = false;
    for(int j=0; j<N; j++){
        for(int k : G[j]){
            if(d[j] + w[j][k] < d[k]) hasNegativeCircle = true;
        }
    }
    if(hasNegativeCircle) cout<<-1<<endl;
    else{
        for(int i=0; i<N; i++){
            cout<<d[i]<<" ";
        }
        cout<<"\n";
    }
}
int main(int argc, const char * argv[]) {
    cin>>N>>E>>s;
    for(int i=0; i<E; i++){
        int a, b, c;
        cin>>a>>b>>c;
        G[a].push_back(b);
        w[a][b] = c;
    }
    Bellman_Ford();
    return 0;
}
