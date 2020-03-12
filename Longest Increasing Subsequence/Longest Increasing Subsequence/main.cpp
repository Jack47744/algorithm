//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by Metis Sotangkur on 2/9/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    cin>>N;
    int data[N];
    int ans[N];
    for(int i=0; i<N; i++) cin>>data[i];
    for(int i=0; i<N; i++){
        if(i==0) {
            ans[i] = 1;
            continue;
        }
        int maxval = 0;
        for(int j = i-1; j>=0; j--){
            if(data[j] <= data[i]){
                maxval = max(maxval, ans[j]);
            }
        }
        ans[i] = maxval +  1;
    }
    priority_queue<int> pq;
    for(int i=0; i<N; i++) pq.push(ans[i]);
    cout<<pq.top();
    return 0;
}
/*
 13
 7 0 10 21 1 6 22 4 3 5 9 8 71
 
 
 
 */
