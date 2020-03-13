//
//  main.cpp
//  Bus Station
//
//  Created by Metis Sotangkur on 3/13/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    vector<pair<int, int>> data;
    vector<pair<int, bool>> timeTable;
    for(int i=0; i<N; i++){
        int arr, dep;
        cin>>arr>>dep;
        data.push_back({arr, dep});
        timeTable.push_back({arr, true});
        timeTable.push_back({dep, false});
    }
    sort(data.begin(), data.end());
    sort(timeTable.begin(), timeTable.end());
    int count = 0;
    int minValue = 0;
    for(int i=0; i<timeTable.size(); i++){
        if(timeTable[i].second){
            count++;
            minValue = max(count, minValue);
        }
        else{
            count--;
        }
    }
    cout<<minValue<<endl;
    return 0;
}
/*
 6
 540 550
 580 720
 590 680
 660 690
 900 1140
 1080 1200
 */
