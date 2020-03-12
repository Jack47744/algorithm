//
//  main.cpp
//  max_3d
//
//  Created by Metis Sotangkur on 3/3/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int count = 0;
int saveData[1000][1000];
int calculate(int data[], int begin, int end){
    cout<<"time"<<endl;
    int ten = 1, ans = 0;
    for(int i=end; i>=begin; i--){
        ans += data[i]*ten;
        ten*=10;
        //cout<<ten<<endl;
    }
    return ans;
}
int maxValue(int data[], int begin, int end, int mod){
    cout<<"count"<<endl;
    //cout<<begin<<" "<<end<<" "<<mod<<endl;
    if(begin == end && data[begin]%3 != 0) return -1;
    if(mod == 0) return calculate(data, begin, end);
    if(saveData[begin][end] > 0) return saveData[begin][end];
    if(data[begin]%3 == mod && data[end]%3 == mod){
        return saveData[begin][end] = max(maxValue(data, begin, end-1, 0), maxValue(data, begin+1, end, 0));
    }
    else if(data[begin]%3 == mod && data[end]%3 != mod){
        return saveData[begin][end] = maxValue(data, begin+1, end, 0);
    }
    else if(data[begin]%3 != mod && data[end]%3 == mod){
        return saveData[begin][end] = maxValue(data, begin, end-1, 0);
    }
    else return saveData[begin][end] = max(maxValue(data, begin, end-1, (mod-data[end]%3 + 3)%3), maxValue(data, begin+1, end, (mod-data[begin]%3 +3)%3));
    
}
int main(int argc, const char * argv[]) {
    int n, overAllMod;
    cin>>n;
    int data[n], dataMod[n];
    for(int i=0; i<n; i++){
        cin>>data[i];
        dataMod[i] = data[i]%3;
    }
    for(int i=0; i<n; i++) overAllMod += dataMod[i];
    overAllMod = overAllMod%3;
    cout<<maxValue(data, 0, n-1, overAllMod)<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<saveData[i][j]<<" ";
        cout<<"\n";
    }
    
}
