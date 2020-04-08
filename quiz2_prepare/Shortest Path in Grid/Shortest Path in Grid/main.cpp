//
//  main.cpp
//  Shortest Path in Grid
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int R, C;
int data[101][101];
int dis[101][101];
void bfs(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) dis[i][j] = -1;
    }
    dis[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(q.size()>0){
        pair<int, int> tmp = q.front();
        q.pop();
        for(auto a : move){
            int x = tmp.second + a.second;
            int y = tmp.first + a.first;
            if(dis[y][x] == -1 and x>=0 and y>=0 and x<C and y<R and data[y][x]){
                //cout<<x<<" "<<y<<" "<<dis[tmp.first][tmp.second]+1<<"\n";
                dis[y][x] = dis[tmp.first][tmp.second] + 1;
                q.push({y, x});
            }
        }
    }
    
    cout<<dis[R-1][C-1]<<"\n";
}
int main(int argc, const char * argv[]) {
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char c;
            cin>>c;
            if(c=='.') data[i][j] = 1;
            else data[i][j] = 0;
        }
    }
    bfs();
    
    return 0;
}
/*
 
 
 5 5
 .#...
 .#...
 .#...
 .#.#.
 ...#.
 
 5 5
 .....
 ...##
 ...#.
 ..##.
 .###.
 */
