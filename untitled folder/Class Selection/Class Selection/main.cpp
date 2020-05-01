//
//  main.cpp
//  Class Selection
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, count = 1;
    cin>>N;
    vector<pair<int, int>> data(N);
    for(int i=0; i<N; i++) cin>>data[i].second;
    for(int i=0; i<N; i++) cin>>data[i].first;
    sort(data.begin(), data.end());
    int last = data[0].first;
    for(int i=1; i<N; i++){
        if(data[i].second>=last){
            count++;
            last = data[i].first;
        }
    }
    cout<<count<<"\n";
    return 0;
}
