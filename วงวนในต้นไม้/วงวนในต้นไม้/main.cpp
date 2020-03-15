//
//  main.cpp
//  วงวนในต้นไม้
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
char color[100001];
int isChecked[100001];
int step[100001];
vector<int> G[100100];
set<int> s;
int N;
void dfs(int current, int last, int count){
    if(isChecked[current]){
        cout<<count - step[current]<<endl;
        exit(0);
        return;
    }
    isChecked[current] = 1;
    step[current] = count;
    for(auto x : G[current]){
        if(x!=last){
            dfs(x, current, count+1);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    cin>>N;
    
    for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1, 1);
}
/*
 9
 0 1
 0 2
 1 3
 1 4
 2 5
 2 6
 2 7
 4 5
 5 8
 */
