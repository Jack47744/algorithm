//
//  main.cpp
//  hole
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int data[1001][1001];
int N, a, b;
int f(){
    int ans = 0;
    int up = b, down = b, left = a, right = a;
    while(up <= 1000 && down >= 1 && left>=1 && right <=1000){
        while(data[left][b]!=1){
            left--;
            if(left<1) return ans;
        }
        while(data[right][b]!=1 ){
            right++;
            if(right>1000) return ans;
        }
        while(data[a][up]!=1){
            up++;
            if(up>1000) return ans;
        }
        while(data[a][down]!=1 && down>=1){
            down--;
            if(down<1) return ans;
        }
        bool isThereAHoleSurroundHouse = true;
        for(int i = left+1; i<=right-1; i++){
            if(data[i][up] != 1 || data[i][down] != 1){
                isThereAHoleSurroundHouse = false;
                break;
            }
        }
        for(int i = down+1; i<= up-1; i++){
            if(data[left][i] != 1 || data[right][i] != 1){
                isThereAHoleSurroundHouse = false;
                break;
            }
        }
        if(isThereAHoleSurroundHouse){
            ans+=1;
            up+=2;
            down-=2;
            left-=2;
            right+=2;
        }
        
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    
    cin>>N>>a>>b;
    
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++) data[i][j] = 0;
    }
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        data[x][y] = 1;
        
    }
    
    
    cout<<f()<<endl;
    
    
    return 0;
}
