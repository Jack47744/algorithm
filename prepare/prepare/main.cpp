//
//  main.cpp
//  prepare
//
//  Created by Metis Sotangkur on 3/15/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<int> s1, s2, s3;
    vector<int> tmp1, tmp2, tmp3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int a, b, c;
    cin>>a>>b>>c;
    for(int i=0; i<a; i++){
        int n;
        cin>>n;
        sum1+=n;
        tmp1.push_back(n);
    }
    for(int i=0; i<b; i++){
        int n;
        cin>>n;
        sum2+=n;
        tmp2.push_back(n);
    }
    for(int i=0; i<c; i++){
        int n;
        cin>>n;
        sum3+=n;
        tmp3.push_back(n);
    }
    for(int i = tmp1.size()-1; i>=0; i--){
        s1.push(tmp1[i]);
    }
    for(int i = tmp2.size()-1; i>=0; i--){
        s2.push(tmp2[i]);
    }
    for(int i = tmp3.size()-1; i>=0; i--){
        s3.push(tmp3[i]);
    }
    while(s1.size()>0 and s2.size()>0 and s3.size()>0){
        if(sum1 == sum2 and sum2 == sum3){
            cout<<sum1<<endl;
            exit(0);
        }
        int tmp = max(sum1, max(sum2, sum3));
        if(tmp == sum1){
            sum1 -= s1.top();
            s1.pop();
        }
        else if(tmp == sum2){
            sum2 -= s2.top();
            s2.pop();
        }
        else{
            sum3 -= s3.top();
            s3.pop();
        }
        
    }
    cout<<0<<endl;
    
}
