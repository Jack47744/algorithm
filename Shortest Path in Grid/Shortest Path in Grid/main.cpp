//
//  main.cpp
//  Shortest Path in Grid
//
//  Created by Metis Sotangkur on 3/10/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int R, C;
    cin>>R>>C;
    vector<vector<char>> data;
    for(int i=0; i<R; i++){
        vector<char> v(C);
        for(int j=0; j<C; j++) cin>>v[j];
        data.push_back(v);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dis;
    for(int i=0; i<R; i++){
        vector<int> tmp(C);
        for(int j=0; j<C; j++) tmp[j] = -1;
        dis.push_back(tmp);
    }
    dis[0][0] = 0;
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 
    while(q.size()>0){
        pair<int, int> tmpNode = q.front();
        q.pop();
        int nowX = tmpNode.second;
        int nowY = tmpNode.first;
        for(auto a : move){
            int x = nowX + a.first;
            int y = nowY + a.second;
            if(x>=0 && x<C && y>=0 && y<R && data[y][x]=='.' && dis[y][x] == -1){
                dis[y][x] = dis[nowY][nowX] + 1;
                q.push({y, x});
            }
        }
    }
   /* for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) cout<<dis[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<dis[R-1][C-1]<<endl;
}
/*
 
 5 5
 .#...
 .#...
 .#...
 .#.#.
 ...#.
5 5
 ..... ...## ...#. ..##. .###.
*/
