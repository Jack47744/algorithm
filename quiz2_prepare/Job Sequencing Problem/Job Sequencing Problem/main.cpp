//
//  main.cpp
//  Job Sequencing Problem
//
//  Created by Metis Sotangkur on 4/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    bool data[N+1];
    for(int i=1; i<=N; i++) data[i] = true;
    vector<pair<int, pair<int, char>>> v; // Profit Deadline Name
    for(int i=0; i<N; i++){
        int profit, deadline;
        char name;
        cin>>name>>deadline>>profit;
        v.push_back({profit, {deadline, name}});
    }
    sort(v.begin(), v.end());
    vector<char> ans;
    for(int i=N-1; i>=0; i--){
        pair<int, pair<int, char>> tmp = v[i];
        bool canInsert = false;
        for(int j = tmp.second.first; j>=1; j--){
            if(data[j]){
                data[j] = false;
                canInsert = true;
                ans.push_back(tmp.second.second);
                break;
            }
        }
    }
    for(auto x:ans) cout<<x<<" "; 
    return 0;
}
