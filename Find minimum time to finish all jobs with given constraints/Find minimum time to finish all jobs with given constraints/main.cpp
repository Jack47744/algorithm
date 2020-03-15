//
//  main.cpp
//  Find minimum time to finish all jobs with given constraints
//
//  Created by Metis Sotangkur on 3/15/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isPossible(int data[], int time, int K, int n){
    int numberOfEmployer = 1;
    int currentTime = 0;
    for(int i=0; i<n;){
        if(data[i] + currentTime > time){
            currentTime = 0;
            numberOfEmployer+=1;
        }
        else{
            currentTime += data[i];
            i++;
            
        }
    }
    return numberOfEmployer<=K;
}
int main(int argc, const char * argv[]) {
    int K, T, N;
    cin>>K>>T>>N;
    int job[K];
    int maxTimeOfJob = 0, overAllTime = 0;
    for(int i=0; i<N; i++){
        cin>>job[i];
        maxTimeOfJob = max(maxTimeOfJob, job[i]);
        overAllTime += maxTimeOfJob;
    }
    int left = maxTimeOfJob;
    int right = overAllTime;
    int ans = right;
    while(left<=right){
        int mid = (left+right)/2;
        if(mid>=maxTimeOfJob and isPossible(job, mid, K, N)){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else{
            left = mid + 1;
        }
    }
    
    cout<<ans*T<<endl;
    
    return 0;
}
