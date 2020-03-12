//
//  main.cpp
//  Fibonacci
//
//  Created by Metis Sotangkur on 2/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int fibData[N+1];
    for(int i=0; i<=N; i++){
        if(i<2) fibData[i] = i;
        else fibData[i] = fibData[i-1] + fibData[i-2];
    }
    cout<<fibData[N];
}
