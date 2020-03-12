//
//  main.cpp
//  Closest Pair
//
//  Created by Metis Sotangkur on 2/26/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int closestPair(int x[], int y[], int left, int right){
    if(left>=right) return 200000000;
    int mid = (left + right)/2;
    int minLeft = closestPair(x, y, left, mid-1);
    int minRight = closestPair(x, y, mid+1, right);
    int allMin = min(minLeft, minRight);
    int xInArea[N], yInArea[N];
    int p = 0;
    for(int i=left; i<=right; i++){
        if(x[i]>x[mid]-allMin && x[i]<x[mid]+allMin){
            xInArea[p] = x[i];
            yInArea[p] = y[i];
            p++;
        }
    }
    
    for(int i=0; i<p; i++){
        for(int j=i+1; j<p && abs(yInArea[i]-yInArea[j])<allMin && j!=i; j++){
            int tmpMinDis = (xInArea[i]-xInArea[j])*(xInArea[i]-xInArea[j]) + (yInArea[i]-yInArea[j])*(yInArea[i]-yInArea[j]);
            allMin = min(tmpMinDis, allMin);
        }
    }
    return allMin;
}
int main(int argc, const char * argv[]) {
    
    cin>>N;
    vector<pair<int, int>> data;
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        data.push_back({x, y});
    }
    sort(data.begin(), data.end());
    int x[N], y[N];
    for(int i=0; i<N; i++){
        x[i] = data[i].first;
        y[i] = data[i].second;
    }
    cout<<closestPair(x, y, 0, N-1)<<endl;
    return 0;
}
