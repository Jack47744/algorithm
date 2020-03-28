//
//  main.cpp
//  Increasing Sequence Sum
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int ans = 0;
int n;
void f(int lastDigit, int sum){
    if(sum == n){
        ans+=1;
        return;
    }
    if(sum>n) return;
    for(int i = lastDigit; i<=n; i++){
        f(i, sum+i);
    }
}

int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1; i<=n; i++){
        f(i, i);
    }
    cout<<ans<<endl;
}
