//
//  main.cpp
//  n-Queen
//
//  Created by Metis Sotangkur on 3/23/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//


#include <iostream>
#include <vector>
using namespace std;
int n;
int ans = 0;
vector<pair<int, int>> myMove = {{1, 1}, {1, -1}};
void f(vector<vector<int>> v, int row, int lastCol){
    if(row>n){
        /*for(int i=1; i<=n; i++){
            for(int j=1; j<=n ;j++) cout<<v[i][j]<<" ";
            cout<<"\n";
        }*/
        ans+=1;
        return;
    }
    else{
        for(int i=1; i<=n; i++){
            bool skip = false;
            for(int j=row-1; j>=1; j--){
                if(v[j][i] == 1){
                    skip = true;
                    break;
                }
            }
            if(skip) continue;
            if(v[row][i] == 2) continue;
            vector<vector<int>> k = v;
            k[row][i] = 1;
            for(auto x : myMove){
                int tmpY = row;
                int tmpX = i;
                while(true){
                    tmpX+=x.second;
                    tmpY+=x.first;
                    if(tmpX>n or tmpY>n or tmpX<1 or tmpY<1) break;
                    //cout<<tmpX<<" "<<tmpY<<endl;
                    k[tmpY][tmpX] = 2;
                }
                //cout<<"\n";
            }
            //cout<<"\n";
            f(k, row+1, i);
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>n;
    vector<int> p(n+1);
    vector<vector<int>> pp;
    for(int i=0; i<=n; i++) pp.push_back(p);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            pp[i][j] = 0;
            //cout<<pp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    f(pp, 1, -1);
    cout<<ans<<endl;
    return 0;
}
