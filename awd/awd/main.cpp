//
//  main.cpp
//  awd
//
//  Created by Metis Sotangkur on 2/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int data[31][31];
int main(int argc, const char * argv[]) {
    int N, con, flip;
    cin>>N>>con>>flip;
    for(int f=0; f<=flip; f++){
        for(int i=f+1; i<=N; i++){
            if(f == 0){
                if(i>con) data[f][i] = 0;
                else data[f][i] = 1;
                continue;
            }
            if(i==f+1) data[f][i] = 1;
            else{
                for(int c=1; c<=con && f-1>=0 && i-c>0; c++){
                    //cout<<data[f][i]<<endl;
                    data[f][i] += data[f-1][i-c];
                }
            }
            
        }
    }/*
    for(int i=0; i<=flip; i++){
        for(int j=1; j<=N; j++){
            cout<<data[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    cout<<data[flip][N]<<endl;
    return 0;
}
