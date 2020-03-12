//
//  main.cpp
//  Pareto Frontier
//
//  Created by Metis Sotangkur on 2/15/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    
    int f, w, n;
    cin>>f>>w>>n;
    int data[n+1];
    int ans[n+1];
    for(int i=1; i<=f; i++){
        int number;
        cin>>number;
        data[number] = 1;
    }
    int k=0;
    for(int i=1; i<=n; i++){
        if(data[i] == 1){
            ans[i] = 1;
            k=i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        ans[i] = 0;
        if(data[i] == 1){
            int minValue = 0;
            bool isFound = false;
            for(int j=i-w; j<=i+w && j<=n && j>=1 && ans[j] > 0; j++){
                if(j-w-1>=1) minValue + ans[j];
                else minValue = 0;
            }
            if(minValue==0){
                for(int j=i; j>=1; j--){
                    if(ans[j]>0){
                        minValue = ans[j];
                        break;
                    }
                }
            }
            ans[i] = minValue + 1;
            
        }
            
        
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\nAns is "<<ans[n]<<endl;
    
}
