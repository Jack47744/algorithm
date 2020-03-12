//
//  main.cpp
//  max_3d ver2.0
//
//  Created by Metis Sotangkur on 3/5/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
int calc(int data[], int begin, int end){
    int ans=0, t=1;
    for(int i=end; i>=begin; i--){
        ans+=data[i]*t;
        t*=10;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int n, sum;
    cin>>n;
    int data[n], beginArr[n], endArr[n], tmpArr[n], tmpArr2[n];
    for(int i=0; i<n; i++) cin>>data[i];
    tmpArr[0] = data[0]%3;
    tmpArr2[n-1] = data[n-1]%3;
    for(int i=1; i<n; i++){
        tmpArr[i] = (tmpArr[i-1] + data[i])%3;
        tmpArr2[n-i-1] = (data[n-i-1] + tmpArr2[n-i])%3;
    }
    for(int i=0; i<n; i++) cout<<tmpArr[i]<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++) cout<<tmpArr2[i]<<" ";
    cout<<endl;
    int allMod = tmpArr[n-1];
    if(allMod%3==0) cout<<calc(data, 0, n-1)<<endl;
    else{
        int beginPointer = 0, endPointer = n-1;
        int beginPointer1 = 0, endPointer1 = n-1;
        int leftValue, rightValue, middleValue;
        for(int i=0; i<n; ++i){
            if(tmpArr[i] == allMod){
                beginPointer = ++i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(tmpArr2[i] == allMod){
                endPointer = --i;
                break;
            }
        }
        if(allMod == 2){
            for(int i=0; i<n; i++){
                if(tmpArr[i] == 1){
                    beginPointer1 = ++i;
                    break;
                }
            }
            for(int i=n-1; i>=0; i--){
                if(tmpArr2[i] == 1){
                    endPointer1 = --i;
                    break;
                }
            }
        }
        else{ //allMod == 1
           for(int i=0; i<n; i++){
                if(tmpArr[i] == 2){
                    beginPointer1 = ++i;
                    break;
                }
            }
            for(int i=n-1; i>=0; i--){
                if(tmpArr2[i] == 2){
                    endPointer1 = --i;
                    break;
                }
            }
        }
        int dis1 = n - beginPointer;
        int dis2 = endPointer + 1;
        int dis3 = n - beginPointer1 - endPointer1;
        cout<<"beginPointer is  "<<beginPointer<<endl;
        cout<<"endPointer is    "<<endPointer<<endl;
        cout<<"beginPointer1 is "<<beginPointer1<<endl;
        cout<<"endPointer1 is   "<<endPointer1<<endl;
        if(min(dis1, min(dis2, dis3)) == n) cout<<"Not Found"<<endl;
        
        
        
        
        else cout<< max(calc(data, beginPointer, n-1), max(calc(data, 0, endPointer), calc(data, beginPointer1, endPointer1)))<<endl;
        
    }
    return 0;
}
