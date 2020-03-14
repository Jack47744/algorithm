//
//  main.cpp
//  drainage
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int N, L;
    cin>>N>>L;
    vector<int> data(N);
    map<int, bool> mp;
    for(int i=0; i<N; i++){
        int number;
        cin>>number;
        data[i] = number;
        mp[number] = true;
    }
    sort(data.begin(), data.end());
    int pointer = 1, indexPointer = 0;
    int count = 0;
    while(indexPointer<=N-1){
        //cout<<pointer<<endl;
        if(mp.find(pointer)!=mp.end()){
            pointer += L;
            count++;
        }
        else{
            while(data[indexPointer]<pointer) {
                if(indexPointer == N) break;
                indexPointer++;
            }
            pointer = data[indexPointer];
        }
    }
    cout<<count<<endl;
    return 0;
}
/*
 6 3
 2 1 3 12 7 8
 
 5 6
 2 4 9 11 14

 */
