//
//  main.cpp
//  Subset Sum Problem
//
//  Created by Metis Sotangkur on 3/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int saveData[1000][1000];
bool isHaveSum(int currentSum, int index, int data[]){
    if(currentSum == 0) return true;
    else if(index <0 and currentSum!=0) return false;
    if(saveData[index][currentSum]>0) return saveData[index][currentSum];
    return saveData[index][currentSum] = isHaveSum(currentSum - data[index], index-1) || isHaveSum(currentSum, index-1);
}
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int data[N];
    for(int i=0; i<N; i++) cin>>data[i];
    sort(data, data+N);
    int sum;
    cin>>sum;
    int index;
    for(int i=0; i<N; i++){
        if(data[i]>sum) break;
        index++;
    }
    if(isHaveSum(sum, index)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
