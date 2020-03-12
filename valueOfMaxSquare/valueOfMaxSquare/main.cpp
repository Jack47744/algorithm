//
//  main.cpp
//  valueOfMaxSquare
//
//  Created by Metis Sotangkur on 3/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int sumInRow(int data[], int diff, int n){
    vector<int> sumArr;
    int initialSum = 0, endPointer = diff + 1, beginPointer = 0;
    for(int i=0; i<=diff; i++){
        initialSum += data[i];
    }
    sumArr.push_back(initialSum);
    while(endPointer<n){
        initialSum += data[endPointer++];
        initialSum -= data[beginPointer++];
        sumArr.push_back(initialSum);
    }
    int maxData = -1000000;
    for(int i=0; i<sumArr.size(); i++) {
        cout<<"diff is "<<diff<<" "<<sumArr[i]<<endl;
        maxData = max(maxData, sumArr[i]);
    }
    return maxData;
}
int maxSquareSum(const vector<vector<int>> data){
    cout<<"\n";
    size_t n = data.size();
    //int maxLeft, maxRight, maxUp, maxDown;
    int maxValue = -10000000;
    for(int left = 0; left<n; left++){
        int tmpArr[n];
        for(int i=0; i<n; i++) tmpArr[i] = 0;
        for(int right = left; right<n; right++){
            for(int row = 0; row<n; row++){
                tmpArr[row] += data[row][right];
            }
            for(int i=0; i<n; i++) cout<<tmpArr[i]<<" ";
            cout<<"\n";
            int diff = right - left;
            maxValue = max(sumInRow(tmpArr, diff, n), maxValue);
            
            cout<<"\n";
        }
    }
    return maxValue;
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<vector<int>> data;
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            int number;
            cin>>number;
            v.push_back(number);
        }
        data.push_back(v);
    }
    cout<<maxSquareSum(data)<<endl;
    
    
}

/*
 7
 0 0 0 1 1 2 1
 0 1 0 -1 0 -1 0
 1 -1 4 5 0 1 0
 1 -1 8 0 1 1 -1
 0 -5 -1 -1 9 3 -1
 -9 -7 5 0 0 5 0
 0 0 0 0 0 -5 0
 
 
 
 */
