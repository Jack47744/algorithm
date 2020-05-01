//
//  main.cpp
//  Shortest Path in Grid
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int R, C;
    cin>>R>>C;
    int dis[R][C];
    int data[R][C];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char k;
            cin>>k;
            if(k=='#') data[i][j] = 0;
            else data[i][j] = 1;
            dis[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 0;
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(q.size()>0){
        pair<int, int> tmp = q.front();
        q.pop();
        for(auto pp:move){
            int y = tmp.first + pp.first;
            int x = tmp.second + pp.second;
            if(dis[y][x] == -1 and y>=0 and x>=0 and y<R and x<C and data[y][x]){
                dis[y][x] = dis[tmp.first][tmp.second] + 1;
                q.push({y, x});
            }
            
        }
    }
    cout<<dis[R-1][C-1]<<"\n";
    
    return 0;
}
