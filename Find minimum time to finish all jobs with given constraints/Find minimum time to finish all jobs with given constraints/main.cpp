//
//  main.cpp
//  Find minimum time to finish all jobs with given constraints
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int K ,T, N;
    cin>>K>>T>>N;
    priority_queue<int> data2;
    for(int i=0; i<N; i++) {
        int number;
        cin>>number;
        data2.push(number);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<K && data2.size()>0; i++){
        pq.push(data2.top());
        data2.pop();
    }
    while(data2.size()>0){
        int tmp = pq.top();
        pq.pop();
        tmp += data2.top();
        data2.pop();
        pq.push(tmp);
    }
    int k = 0;
    while(pq.size()>0){
        k = pq.top();
        pq.pop();
    }
    cout<<T*k<<endl;
    
    return 0;
}
