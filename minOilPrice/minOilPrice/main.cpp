//
//  main.cpp
//  minOilPrice
//
//  Created by Metis Sotangkur on 3/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, v;
    cin>>n>>v;
    int ans[n+1], data[n+1];
    for(int i=1; i<=n; i++) cin>>data[i];
    for(int i=2; i<=n; i++){
        int minValue = 2000000;
        for(int j = i-1; j>=i-v; j--){
            minValue = min(minValue, data[j]);
        }
        cout<<minValue<<endl;
        ans[i] = ans[i-1] + minValue;
        
    }
    cout<<"\n";
    for(int i=2; i<=n; i++) cout<<ans[i]<<endl;
    cout<<ans[n]<<endl;;
    return 0;
}
