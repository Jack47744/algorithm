//
//  main.cpp
//  Class Selection
//
//  Created by Metis Sotangkur on 2/24/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<pair<int, int>> data(N);
    for(int i=0; i<N; i++){
        int s;
        cin>>s;
        data[i].second = s;
    }
    for(int i=0; i<N; i++){
        int f;
        cin>>f;
        data[i].first = f;
    }
    sort(data.begin(), data.end());
    set<pair<int, int>> ans;
    ans.insert(data[0]);
    int lastEnd = data[0].first;
    for(int i=1; i<N; i++){
        if(data[i].second>=lastEnd){
            ans.insert(data[i]);
            lastEnd = data[i].first;
        }
    }
    cout<<ans.size()<<endl;
    
    return 0;
}
