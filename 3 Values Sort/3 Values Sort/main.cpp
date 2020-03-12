//
//  main.cpp
//  3 Values Sort
//
//  Created by Metis Sotangkur on 2/25/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int N,ab=0,ba=0;
    cin>>N;
    int data[N], sortedData[N];
    for(int i=0; i<N; i++){
        cin>>data[i];
        sortedData[i] = data[i];
    }
    sort(sortedData, sortedData+N);
    for(int i=0;i<N; i++){
        if(data[i]<sortedData[i]) ab++;
        if(data[i]>sortedData[i]) ba++;
    }
    cout<<max(ab, ba);
    
    
    
    return 0;
}
