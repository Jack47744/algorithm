//
//  main.cpp
//  Square Subarea
//
//  Created by Metis Sotangkur on 2/28/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int R,C;
    cin>>R>>C;
    int data[R][C];
    int s[R][C];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>data[i][j];
        }
    }
    for(int i=0; i<R; i++) s[i][0] = data[i][0];
    for(int i=0; i<C; i++) s[0][i] = data[0][i];
    int ans = 0;
    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            s[i][j] = (data[i][j])? min(s[i-1][j-1], min(s[i][j-1], s[i-1][j])) + 1 : 0;
            ans = max(ans, s[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
