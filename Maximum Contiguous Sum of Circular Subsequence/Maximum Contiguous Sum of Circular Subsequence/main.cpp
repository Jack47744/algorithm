//
//  main.cpp
//  Maximum Contiguous Sum of Circular Subsequence
//
//  Created by Metis Sotangkur on 3/3/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int data[3*n], distance[3*n], ans[3*n];
    for(int i=0; i<n; i++){
        int number;
        cin>>number;
        data[i] = number;
        data[i+n] = number;
        data[i+2*n] = number;
    }
    ans[0] = data[0];
    distance[0] = 1;
    for(int i=1; i<3*n; i++){
        if(ans[i-1] + data[i] > data[i] && distance[i-1] < n){
            ans[i] = ans[i-1] + data[i];
            distance[i] = distance[i-1] + 1;
        }
        else{
            ans[i] = data[i];
            distance[i] = 1;
        }
    }
    int maxValue = ans[0];
    for(int i=1; i<3*n; i++) maxValue = max(maxValue, ans[i]);
    cout<<maxValue<<endl;
}
