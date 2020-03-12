//
//  main.cpp
//  ConsecutiveYear
//
//  Created by Metis Sotangkur on 3/5/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int maxConsecuticeYear(int y[], int targetYear, int left, int right){
    if(left>right) return right;
    int mid = (left+right)/2;
    if(y[mid] == targetYear) return mid;
    if(y[mid] > targetYear) return maxConsecuticeYear(y, targetYear, left, mid-1);
    return maxConsecuticeYear(y, targetYear, mid+1, right);
}
int main(int argc, const char * argv[]) {
    int n, x;
    cin>>n>>x;
    int data[n];
    for(int i=0; i<n; i++) cin>>data[i];
    //cout<<maxConsecuticeYear(data, 2503, 0, n-1);
    int maxValue = 0;
    for(int i=0; i<n; i++){
        int k = maxConsecuticeYear(data, data[i] + x - 1, 0, n-1) - i + 1;
        maxValue = max(maxValue, k);
    }
    cout<<maxValue<<endl;
    
    
    return 0;
}
/*
 8 4
 2500 2502 2508 2510 2511 2512 2516 2519
 */
