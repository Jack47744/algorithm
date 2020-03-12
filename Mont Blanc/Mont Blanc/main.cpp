//
//  main.cpp
//  Mont Blanc
//
//  Created by Metis Sotangkur on 3/10/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int N, D, ans;
bool day(int d[], int K){
    int day2 = 1;
    int cur = 0;
    for(int i=0; i<N; i++){
        if(d[i] - cur > K){
            day2++;
            cur = d[i-1];
        }
    }
    if(day2>D) return true;
    ans = day2;
    return false;
}
int main(int argc, const char * argv[]) {
    cin>>N>>D;
    int camp[N];
    int maxDiff = -1;
    for(int i=0; i<N; i++){
        cin>>camp[i];
        if(i>=1){
            maxDiff = max(maxDiff, camp[i] - camp[i-1]);
        }
    }
    int left = maxDiff;
    int right = camp[N-1]+1;
    while(left<right){
        int mid = (left+right)/2;
        if(day(camp, mid)) left = mid+1;
        else right = mid;
    }
    cout<<left<<" "<<ans<<endl;
    

}
