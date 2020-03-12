//
//  main.cpp
//  barcode
//
//  Created by Metis Sotangkur on 2/12/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int value[n+1], weight[n+1];
    for(int i=1; i<=n; i++) cin>>value[i];
    for(int i=1; i<=n; i++) cin>>weight[i];
    int data[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            cin>>data[i][j];
        }
    }
    int i = n;
    int j = m;
    int ans[n];
    int c;
    while(i>=0 && j>=0){
       // cout<<"i is "<<i<<" j is "<<j<<endl;
        if(data[i][j] == data[i-1][j]) i--;
        else {
           // cout<<"lllllll  i is "<<i<<" j is "<<j<<endl;
            ans[c++] = i;
            j-=weight[i];
            i--;
            
        }
        
    }
    for(int i=0; i<c; i++) cout<<ans[i]<<" ";
    
    
    
}
