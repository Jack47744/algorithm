//
//  main.cpp
//  15 Puzzle
//
//  Created by Metis Sotangkur on 3/30/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
int data[5][5];
using namespace std;
map<int, pair<int, int>> mp;
int costFunction(map<int, pair<int, int>> m){
    int ans = 0;
    for(int i=0; i<16; i++){
        ans += (mp[i].first - m[i].first)*(mp[i].first - m[i].first);
        ans += (mp[i].second - m[i].second)*(mp[i].second-m[i].second);
    }
    return ans;
}
struct board{
    map<int, pair<int, int>> location;
    int cost = -1;
    int count = 0;
    void cal(){
        cost = costFunction(location);
    }
    bool operator<(const board other){
        return cost>other.cost;
    }
};

int main(int argc, const char * argv[]) {
    int p=1;
    map<int, pair<int, int>> start;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int n;
            cin>>n;
            start[n] = {i, j};
            mp[p] = {i, j};
        }
    }
    mp[0] = {3,3};
    board ss;
    ss.count = 0;
    ss.location = start;
    ss.cal();
    set<board> s;
    priority_queue<board> pq;
    pq.push(ss);
    s.insert(ss);
    while(pq.size()>0){
        board tmp = pq.top();
        pq.pop();
        if(tmp.cost == 0){
            cout<<tmp.count<<endl;
            exit(0);
        }
        if(s.find(tmp)==s.end()){
            
        }
    }
    
    return 0;
}
