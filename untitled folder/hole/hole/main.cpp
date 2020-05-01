//
//  main.cpp
//  hole
//
//  Created by Metis Sotangkur on 4/17/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool hasHole[1001][1001];
int main(int argc, const char * argv[]) {
    int N, a, b;
    cin>>N>>a>>b;
    pair<int, int> startPoint = {b, a};
    for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        hasHole[b][a] = true;
    }
    bool isVisit[1001][1001];
    queue<pair<int, pair<int, int>>> q;   // (count, y, x)
    q.push({0, startPoint});
    vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //bool isFinish = false;
    isVisit[startPoint.first][startPoint.second] = true;
    int ans = 1000000;
    while(q.size()>0){
        pair<int, pair<int, int>> tmp = q.front();
        q.pop();
        int nowX = tmp.second.second, nowY = tmp.second.first, count = tmp.first;
        for(auto k:v){
            int x = nowX + k.first;
            int y = nowY + k.second;
            if(x==0 or y==0 or x>1000 or y>1000){
                ans = min(ans, count);
                break;
            }
            if(x>=1 and y>=1 and x<=1000 and y<=1000 and !isVisit[y][x]){
                isVisit[y][x] = true;
                if(hasHole[y][x]) q.push({count + 1, {y, x}});
                else q.push({count, {y, x}});
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
