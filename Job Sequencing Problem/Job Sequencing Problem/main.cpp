//
//  main.cpp
//  Job Sequencing Problem
//
//  Created by Metis Sotangkur on 3/13/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<pair<int, pair<int, char>>> jobs; // profit deadLine name
    for(int i=0; i<N; i++){
        char id;
        int deadLine, profit;
        cin>>id>>deadLine>>profit;
        jobs.push_back({profit, {deadLine, id}});
    }
    vector<int> slot(1000);
    vector<char> ans;
    for(int i=0; i<1000; i++) slot[i] = 1;
    sort(jobs.begin(), jobs.end());
    for(int i=N-1; i>=0; i--){
        
        for(int j = jobs[i].second.first; j>=1; j--){
            if(slot[j]){
                slot[j] = false;
                ans.push_back(jobs[i].second.second);
                break;
            }
        }
    }
    for(auto x:ans) cout<<x<<" ";
    
    
    
}
/*
 4
 a 4 20
 b 1 10
 c 1 40
 d 1 30
 
 5
 a 2 100
 b 1 10
 c 2 27
 d 1 25
 e 3 15
 
 */
