//
//  main.cpp
//  Count number of ways to cover a distance
//
//  Created by Metis Sotangkur on 3/2/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>

using namespace std;
int allStep(int n, int data[]){
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    else{
        return data[n] = allStep(n-1, data) + allStep(n-2, data) + allStep(n-3, data);
    }
}
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int data[N];
    cout<<allStep(N, data);
    
    return 0;
}
