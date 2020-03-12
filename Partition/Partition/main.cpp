//
//  main.cpp
//  Partition
//
//  Created by Metis Sotangkur on 3/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minDiff(int data[], int nowSum, int allSum, int index){
    if(index == 0) return abs(nowSum - allSum);
    else{
        return min(minDiff(data, nowSum + data[index], allSum, index-1), minDiff(data, nowSum, allSum, index-1));
    }
}
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int data[N];
    for(int i=0; i<N; i++) cin>>data[i];
    int allSum = 0;
    for(int i=0; i<N; i++){
        allSum += data[i];
    }
    cout<<minDiff(data, 0, allSum, N-1);
    
}
