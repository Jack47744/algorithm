//
//  main.cpp
//  quiz_2_2
//
//  Created by Metis Sotangkur on 4/19/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int r, c, T;
int data[501][501];
int main(int argc, const char * argv[]) {
    cin>>r>>c>>T;
    int count = 0;
    queue<pair<int, int>> covid;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int a;
            cin>>a;
            data[i][j] = a;
            if(a == 1){
                covid.push({i, j});
                count++;
            }
        }
    }
    
    vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int t=0; t<T; t++){
        vector<pair<int, int>> tmp;
        while(covid.size()>0){
            tmp.push_back({covid.front()});
            covid.pop();
        }
        for(auto myPair : tmp){
            for(auto m : move){
                int x = myPair.second + m.second;
                int y = myPair.first + m.first;
                if(x >= 0 and x<c and y>=0 and y<r and data[y][x] == 0){
                    data[y][x] = 1;
                    covid.push({y, x});
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
