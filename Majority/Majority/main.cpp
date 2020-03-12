//
//  main.cpp
//  Majority
//
//  Created by Metis Sotangkur on 3/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;

bool VSCount(int data[], int left, int right, int x, int y){
    int countX, countY;
    for(int i = left; i<=right; i++){
        if(data[i] == x) countX++;
        else if(data[i] == y) countY++;
    }
    return countX>countY;
}
int majority(int data[], int left, int right, bool &isMoreThanHalf){
    if(left == right) return data[left];
    int mid = (left+right)/2;
    int leftMajor = majority(data, left, mid, isMoreThanHalf);
    int rightMajor = majority(data, mid+1, right, isMoreThanHalf);
    if(leftMajor == rightMajor) return leftMajor;
    int countLeft, countRight;
    for(int i = left; i<=right; i++){
        if(data[i] == leftMajor) countLeft++;
        if(data[i] == rightMajor) countRight++;
    }
    
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int data[n];
    for(int i=0; i<n; i++){
        cin>>data[i];
    }
    cout<<majority(data, 0, n-1)<<endl;
    return 0;
}
