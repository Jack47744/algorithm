//
//  main.cpp
//  Tile
//
//  Created by Metis Sotangkur on 2/28/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, V;
    cin>>N>>V;
    int ans[N+1], P[N+1];
    for(int i=1; i<=N; i++) cin>>P[i];
    ans[1] = 0;
    for(int i=2; i<=N; i++){
        int minValue = 10000000;
        for(int j = i-1; j>=1 && j>=i-V; j--){
            minValue = min(minValue, P[j]);
        }
        ans[i] = ans[i-1] + minValue;
    }
    cout<<ans[N];
    
    
    return 0;
}
