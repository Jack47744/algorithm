//
//  main.cpp
//  Connect n ropes with minimum cost
//
//  Created by Metis Sotangkur on 3/13/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class myComparator{
public:
    bool operator() (const int& a, const int& b){
        return a<b;
    }
};
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<int> data(N);
    for(int i=0; i<N; i++){
        cin>>data[i];
    }
    sort(data.begin(), data.end());
    priority_queue <int, vector<int>, greater<int> > pq;
    for(int i=0; i<N; i++){
        pq.push(data[i]);
    }
    int cost = 0;
    while(pq.size()!=1){
        int newRope = pq.top();
        cost += pq.top();
        pq.pop();
        
        newRope += pq.top();
        cost += pq.top();
        pq.pop();
        pq.push(newRope);
    }
    cout<<cost<<endl;
}
