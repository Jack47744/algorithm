//
//  main.cpp
//  awd
//
//  Created by Metis Sotangkur on 1/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int mod(int x, int n, int k){
    if(n==1) return x%k;
    if(n%2 == 1){
        int a = mod(x, n-1, k);
        int b = mod(x, 1, k);
        return mod(a*b, 1, k);
    }
    else{
        int a = mod(x, n/2, k);
        return mod(a*a, 1, k);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int X, N, K;
    cin>>X>>N>>K;
    cout<<mod(X,N,K);
   
    return 0;
}
