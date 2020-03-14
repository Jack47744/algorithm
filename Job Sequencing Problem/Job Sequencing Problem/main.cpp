//
//  main.cpp
//  Job Sequencing Problem
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int slot[1000];
    for(int i=0; i<1000; i++) slot[i] = 1;
    priority_queue<pair<int, pair<int, char>>> data;
    for(int i=0; i<N; i++){
        char name;
        int profit, deadLine;
        cin>>name>>deadLine>>profit;
        data.push({profit, {deadLine, name}});
    }
    vector<char> ans;
    while(data.size()>0){
        pair<int, pair<int, char>> tmp = data.top();
        cout<<"name : "<<tmp.second.second<<" deadline : "<<tmp.second.first<<" profit : "<<tmp.first<<endl;
        data.pop();
        for(int i = tmp.second.first; i>=1; i--){
            if(slot[i]){
                slot[i] = 0;
                ans.push_back(tmp.second.second);
                break;
            }
        }
    }
    for(int i=0; i<5; i++) cout<<slot[i]<<" ";
    cout<<"\n";
    for(auto x : ans) cout<<x<<" ";
    return 0;
}
