//
//  main.cpp
//  Cable Company
//
//  Created by Metis Sotangkur on 3/26/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool inMST[1001];
vector<int> G[1010];
int w[1010][1010];
int d[1010];
int N;
void prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<>> pq;
    pq.push({0, 0});
    //inMST[0] = true;
    d[0] = 0;
    for(int i=1; i<N; i++){
        pq.push({100000, i});
        inMST[i] = false;
        d[i] = 100000;
    }
    while(pq.size()>0){
        pair<int, int> tmp = pq.top();
        int u = tmp.second;
        pq.pop();
        inMST[u] = true;
        for(auto v : G[u]){
            if(!inMST[v] and w[u][v] < d[v]){
                //cout<<u<<" "<<v<<" "<<w[u][v]<<endl;
                d[v] = w[u][v];
                pq.push({d[v], v});
            }
        }
        
    }
    int p = 0;
    for(int i=0; i<N; i++){
        //cout<<d[i]<<endl;
        p+=d[i];
    }
    cout<<p<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>N;
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            int a;
            cin>>a;
            w[i][j] = a;
            w[j][i] = a;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            //cout<<w[i][j]<<" ";
            if(j==i) continue;
            G[i].push_back(j);
            //G[j].push_back(i);
            
        }
        //cout<<"\n";
    }
    /*for(int i=0; i<N; i++){
        for(auto x: G[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }*/
    
    prim();
    return 0;
}
