//
//  main.cpp
//  15 puzzle
//
//  Created by Metis Sotangkur on 4/24/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, pair<int, int>> mp;
int cost(vector<vector<int>> v){
    int c = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            c+=abs(i - mp[v[i][j]].first)+abs(j-mp[v[i][j]].second);
        }
    }
    return c;
}
class board{
public:
    int value;
    int count;
    int holeX, holeY;
    vector<int> move;
    vector<vector<int>> table;
    board(int v, int c, int x, int y, vector<int> m, vector<vector<int>> b){
        value = v;
        count = c;
        holeX = x;
        holeY = y;
        move = m;
        table = b;
    }
};
class myComp{
public:
    int operator() (const board& b1, const board& b2){
        return b1.value > b2.value;
    }
};



int main(int argc, const char * argv[]) {
    int p = 1;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            mp[p++] = {i, j};
        }
    }
    vector<vector<int>> v(4);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int n;
            cin>>n;
            if(n==0) v[i].push_back(16);
            else v[i].push_back(n);
        }
    }
    priority_queue<board, vector<board>, myComp> pq;
    pq.push(board(cost(v), ))
        
    }
    
    
    return 0;
}
