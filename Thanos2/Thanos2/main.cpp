//
//  main.cpp
//  Thanos2
//
//  Created by Metis Sotangkur on 2/27/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long long indexBinary(long long data[], long long left, long long right, long long x){
    if(left==right && data[left] == x) return left;
    long long mid = (left+right)/2;
    if(data[mid] == x) return mid;
    if(data[mid] > x) return indexBinary(data, left, mid-1, x);
    return indexBinary(data, mid+1, right, x);
}
long long avgNumber(long long data[], long long left, long long right){
    
}
long long snap(long long data[], long long left, long long right){
    
}
int main(int argc, const char * argv[]) {
    long long p, k, A, B;
    cin>>p>>k>>A>>B;
    long long data[k];
    for(int i=0; i<k; i++) cin>>data[i];
    sort(data, data + k);
    
    return 0;
}
