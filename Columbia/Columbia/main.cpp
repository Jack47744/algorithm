//
//  main.cpp
//  Columbia
//
//  Created by Metis Sotangkur on 3/26/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int R, C;
    cin>>R>>C;
    int d[R][C];
    vector<vector<int>> w;
    for(int i=0; i<R; i++){
        vector<int> tmp(C);
        w.push_back(tmp);
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>w[i][j];
            d[i][j] = 10000000;
            if(i==0 and j==0){
                pq.push({0, {0, 0}});
                d[i][j] = 0;
            }
            else{
                pq.push({100000, {i, j}});
            }
        }
    }
    vector<pair<int, int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(pq.size()>0){
        pair<int, pair<int, int>> tmp = pq.top();
        int r = tmp.second.first;
        int c = tmp.second.second;
        pq.pop();
        for(auto m : move){
            int tmpY = r + m.first;
            int tmpX = c + m.second;
            if(tmpY>=0 and tmpX>=0 and tmpY<R and tmpX<C){
                if(d[r][c] + w[tmpY][tmpX] < d[tmpY][tmpX]){
                    d[tmpY][tmpX] = d[r][c] + w[tmpY][tmpX];
                    pq.push({d[tmpY][tmpX], {tmpY, tmpX}});
                }
            }
        }
        
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}
/*
 4 4
 1 1 1 1
 9 8 7 1
 1 1 1 1
 1 2 4 9
 */
