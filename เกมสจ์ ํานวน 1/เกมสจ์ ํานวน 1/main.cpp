//
//  main.cpp
//  เกมสจ์ ํานวน 1
//
//  Created by Metis Sotangkur on 2/28/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
long long n, l, r;
std::map<long long, long long> mp;
long long getData(long long n){
    if(mp.find(n)!=mp.end()) return (*mp.find(n)).second;
    if(n>=0 && n<=1) return mp[n] = 1;
    return mp[n] = 2*getData(n/2) + 1;
}
long long getOne(long long l, long long r, long long n){
    if(l>r) return 0;
    if(n==1 or n==0) return n%2;
    long long nextLength = getData(n/2);
    if(r<=nextLength) return getOne(l, r, n/2);
    else if(l>nextLength+1) return getOne(l-1-nextLength, r-1-nextLength, n/2);
    else return getOne(l, nextLength, n/2) + n%2 + getOne(1, r-1-nextLength, n/2);
}
int main(int argc, const char * argv[]) {
    cin>>n>>l>>r;
    cout<<getOne(l, r, n)<<endl;
}
