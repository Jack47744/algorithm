//
//  main.cpp
//  Midterm Prepare
//
//  Created by Metis Sotangkur on 3/3/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int peak(int x[], int left, int right){
    if(right - left == 2) return x[left+1];
    int mid = (left+right)/2;
    if(x[mid-1]<x[mid] && x[mid]>x[mid+1]) return x[mid];
    if(x[mid]<x[mid+1]) return peak(x, mid, right);
    else return peak(x, left, mid);
}
int main(int argc, const char * argv[]) {
    int n;
    
    cin>>n;
    int data[n];
    for(int i=0; i<n; i++) cin>>data[i];
    cout<<peak(data, 0, n-1)<<endl;
    return 0;
}
