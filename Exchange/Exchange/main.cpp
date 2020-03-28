//
//  main.cpp
//  Exchange
//
//  Created by Metis Sotangkur on 3/27/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int R;
    cin>>R;
    for(int r = 0; r<R; r++){
        int N;
        cin>>N;
        double data[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) cin>>data[i][j];
        }
        for(int k=0; k<N; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    data[i][j] = max(data[i][j], data[i][k]*data[k][j]);
                }
            }
        }
        bool ans = true;
        for(int i=0; i<N; i++){
            if(data[i][i]!=1){
                ans = false;
                break;
            }
        }
        if(!ans) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}
