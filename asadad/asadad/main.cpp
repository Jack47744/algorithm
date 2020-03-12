//
//  main.cpp
//  awd
//
//  Created by Metis Sotangkur on 1/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<long long, long long> data;
//vector<pair<long long, long long>> data2;
long long p, k, A, B;
long long snap(int left, int right, long long data[]){
    
    if(left>right) return 0;
    long long avengerNumber = lower_bound(data, data+k, 1) - data;
    
    cout<<"left is "<<left<<" right is "<<right<<" there are "<<avengerNumber<<" avenger"<<endl;
    if(avengerNumber == 0) return A;
    int mid = (left+right)/2;
    return min(snap(left, mid, data) + snap(mid+1, right, data), B*avengerNumber*(right-left+1));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    long long data[k];
    vector<long long> v(k);
    cin>>p>>k>>A>>B;
    for(long long i=0; i<k; i++){
        long long number;
        cin>>number;
        data[number]+=1;
    }
    int l = 1<<p;
    sort(data, data+k);
    
    cout<<snap(1, l, data);
    
    
}
