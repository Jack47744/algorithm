//
//  main.cpp
//  drainage
//
//  Created by Metis Sotangkur on 4/8/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, L;
    cin>>N>>L;
    int p[N];
    for(int i=0; i<N; i++) cin>>p[i];
    sort(p, p+N);
    int last = p[0];
    int count = 1;
    for(int i=1; i<N; i++){
        if(p[i] - last + 1 > L){
            count++;
            last = p[i];
        }
        
    }
    cout<<count<<endl;
    return 0;
}
