//
//  main.cpp
//  Pacman and Ghost
//
//  Created by Metis Sotangkur on 3/14/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int R, C, n, T, r, c;
vector<pair<int, pair<int, int>>> ghosts(101);
int map[101][101];
int checked[101][101];
void rezero(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++) checked[i][j] = 0;
    }
}
vector<pair<int, int>> move2 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool dfs(int time, int destinationX, int destinationY, int currentX, int currentY){
    cout<<time<<" "<<currentX<<" "<<currentY<<" "<<destinationX<<" "<<destinationY<<endl;
    bool ans = false;
    if(time<0) return false;
    if(currentY == destinationY and currentX == destinationX) return time>=0;
    for(int i=0; i<4; i++){
        int x = currentX + move2[i].first;
        int y = currentY + move2[i].second;
        if(x>=0 && x<C && y>=0 && y<R && map[y][x] && !checked[y][x]){
            ans = ans or dfs(time-1, destinationX, destinationY, x, y);
            checked[y][x] = 1;
        }
    }
    return ans;
}
bool isSurvive(){
    bool ans = false;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<"pacman\n";
            rezero();
            checked[r][c] = 1;
            ans = ans or dfs(T, i, j, r, c);
            bool ghostWin = false;
            cout<<"ghost\n";
            for(int k=0; k<n; k++){
                rezero();
                checked[ghosts[k].second.first][ghosts[k].second.second] = 1;
                ghostWin = ghostWin or dfs(T-ghosts[k].first, i, j, ghosts[k].second.first, ghosts[k].second.second);
            }
            if(ans and !ghostWin) return true;
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int K;
    cin>>K;
    for(int u = 0; u<K; u++){
        cin>>R>>C>>n>>T>>r>>c;
        for(int i=0; i<n; i++){
            int ti, ri, ci;
            cin>>ti>>ri>>ci;
            ghosts.push_back({ti, {ri, ci}});
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                char p;
                cin>>p;
                if(p=='.') map[i][j] = 1;
                else map[i][j] = 0;
            }
        }
        if(isSurvive()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}
/*
 
 
 3
 2 5 1 1 0 2
 0 0 2
 .....
 .....
 
 
 
 */
