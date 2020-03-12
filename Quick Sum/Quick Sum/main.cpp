//
//  main.cpp
//  Quick Sum
//
//  Created by Metis Sotangkur on 2/28/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M, K;
int A[1000][1000], P[1000][1000];
int getSum(int r1, int c1, int r2, int c2){
    int a, b, c, d;
    a = P[r2][c2];
    b = (r1-1<0)? 0:P[r1-1][c2];
    c = (c1-1<0)? 0:P[r2][c1-1];
    d = (r1-1<0 or c1-1<0)? 0:P[r1-1][c1-1];
    return a-b-c+d;
}
int main(int argc, const char * argv[]) {
    
    cin>>N>>M>>K;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) cin>>A[i][j];
    }
    P[0][0] = A[0][0];
    for(int i=1; i<M; i++){
        P[0][i] = P[0][i-1] + A[0][i];
    }
    for(int i=1; i<N; i++){
        P[i][0] = P[i-1][0] + A[i][0];
        for(int j=1; j<M; j++){
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + A[i][j];
        }
    }
    for(int i=0; i<K; i++){
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<getSum(r1, c1, r2, c2)<<"\n";
    }
    
    return 0;
}
