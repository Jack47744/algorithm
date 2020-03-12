//
//  main.cpp
//  Tiling
//
//  Created by Metis Sotangkur on 1/22/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool pair_sum(int data[], int number, int left, int right){
    int mid = (left+right)/2;
    
    bool ans1 = pair_sum(data, number, left, mid);
    bool ans2 = pair_sum(data, number, mid+1, right);
    return ans1*ans2;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, M;
    cin>>N>>M;
    int data[N];
    for(int i=0; i<N; i++){
        int number;
        cin>>number;
        data[i] = number;
    }
    for(int i=0; i<M; i++){
        int number;
        cin>>number;
        if(pair_sum(data, number, 0, N-1)) cout<<"YES\n";
        else cout<<"end\n";
    }
    
    return 0;
}
