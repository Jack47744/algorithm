//
//  main.cpp
//  Binomial Coefficient
//
//  Created by Metis Sotangkur on 2/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
//int xy[50000][50000];
int minDistance(int left, int right, int x[], int y[]){
    if(left >= right) return 10000000;
    int xInArea[N];
    int yInArea[N];
    int mid = (left+right)/2;
    int min1 = minDistance(left, mid, x, y);
    int min2 = minDistance(mid+1, right, x, y);
    int min = (min1<min2)? min1:min2;
    int c=0;
    for(int i; i<N; i++){
        if(x[i]>mid - min && x[i]<mid+min){
            xInArea[c] = x[i];
            yInArea[c] = y[i];
            c++;
        }
    }
    for(int i=0; i<c; i++){
        for(int j=i+1; j<=i+6 && j<c && yInArea[j]-yInArea[i]<min; j++){
            int dis = (xInArea[i]-xInArea[j])*(xInArea[i]-xInArea[j]) + (yInArea[i]-yInArea[j])*(yInArea[i]-yInArea[j]);
            if(min>dis) min = dis;
        }
    }
    return min;
    
}




int main(int argc, const char * argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>N;
    int x[N], y[N];
    vector<pair<int, int>> data;
    for(int i=0; i<N; i++){
        int xc, yc;
        cin>>xc>>yc;
        data.push_back({xc,yc});
    }
    sort(data.begin(), data.end());
    for(int i=0; i<N; i++){
        x[i] = data[i].first;
        y[i] = data[i].second;
    }
    int minX = x[0];
    int maxX = x[0];
   
    cout<<minDistance(minX, maxX, 0, N-1);
    
    
}
/*
 6
 10 2
 10 4
 10 6
 12 3
 12 5
 12 7
 */
