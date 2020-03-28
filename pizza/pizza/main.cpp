//
//  main.cpp
//  pizza
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int V,E;
int W[1010][1010];
vector<int> G[1010];
int p = 0;
bool isCircle = false;
bool isChecked[1010];
void dfs(int now, int last, int count){
    if(isChecked[now]){
        if(now == 1){ //วกกลับมาที่จุดที่ 1
            isCircle = true;
            
            p = count;
        }
        else{
            p = -1;  // assume ว่า ระยะทุกจุดเป็นบวก
        }
    }
    isChecked[now] = true;
    for(auto x : G[now]){
        if(x == last) continue;
        else{
            dfs(x, now, count + W[x][now]);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int a, b, w;
        cin>>a>>b>>w;
        G[a].push_back(b);
        G[b].push_back(a);
        W[a][b] = w;
        W[b][a] = w;
    }
    dfs(1, -1, 0);
    return 0;
}
