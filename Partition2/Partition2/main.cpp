//
//  main.cpp
//  Partition2
//
//  Created by Metis Sotangkur on 3/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int saveData[1000][1000];
bool isIn(int index, int currentSum,int correctSum, int data[]){
    if(currentSum == correctSum) return true;
    if(index<0) return false;
    if(saveData[index][currentSum] > 0) return saveData[index][currentSum];
    return saveData[index][currentSum] =  isIn(index-1, currentSum, correctSum, data) or isIn(index-1, currentSum + data[index], correctSum, data);
}
int main(int argc, const char * argv[]) {
    int n, allsum;
    cin>>n;
    int data[n];
    for(int i=0; i<n; i++){
        int number;
        cin>>number;
        allsum += number;
        data[i] = number;
    }
    if(allsum%2 == 1){
        cout<<"0\n";
        return 0;
    }
    else{
        allsum /= 2;
        cout<<isIn(n-1, 0, allsum, data)<<"\n";
        
    }
    
    
    return 0;
}
