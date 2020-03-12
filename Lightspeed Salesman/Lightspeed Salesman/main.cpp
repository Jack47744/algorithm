//
//  main.cpp
//  Lightspeed Salesman
//
//  Created by Metis Sotangkur on 3/10/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, M;
    cin>>N>>M;
    int dis[M][M];
    int companySequence[M], timeTravel[M];
    for(int i=0; i<M; i++) cin>>companySequence[i];
    for(int i=0; i<M; i++) cin>>timeTravel[i];
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++){
            if(j-i==1) dis[i][j] = timeTravel[i];
            else{
                dis[i][j] = dis[i][j-1] + timeTravel[i];
            }
        }
    }
    for(int i=0; i<M; i++){
        for(int j=i+1; j<M; j++) cout<<dis[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        int now, next;
        now = companySequence[0];
        for(int j=1; j<M; j++){
            
        }
    }
    return 0;
}
