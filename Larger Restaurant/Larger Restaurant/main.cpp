//
//  main.cpp
//  Larger Restaurant
//
//  Created by Metis Sotangkur on 2/3/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
void mergesort(int data[], int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    mergesort(data, left, mid);
    mergesort(data, mid+1, right);
    int i = left;
    int j = mid+1;
    int k = 0;
    int data2[right-left+1];
    while(i<= mid || j<=right){
        if(i>mid) data2[k++] = data[j++];
        else if(j>right) data2[k++] = data[i++];
        else{
            if(data[i]<=data[j]){
                data2[k++] = data[i++];
            }
            else{
                data2[k++] = data[j++];
            }
        }
    }
    for(int i=0; i<right-left+1; i++){
        data[left+i] = data2[i];
    }
}

bool mysearch(int data[], int left, int right, int number){
    if(left==right && data[left] == number) return true;
    else if(left>=right) return false;
    int mid = (left+right)/2;
    if(data[mid] == number) return true;
    if(data[mid]>number) return mysearch(data, left, mid, number);
    return mysearch(data, mid+1, right, number);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, M;
    cin>>N>>M;
    int data[N];
    for(int i=0; i<N; i++){
        cin>>data[i];
    }
    mergesort(data, 0, N-1);
    int allsum[N][N];
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            allsum[i][j] = data[i]+data[j];
            cout<<allsum[i][j]<<"\n";
        }
    }
    cout<<"end\n";
    int sum[N*N];
    int k=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            sum[k++] = allsum[i][j];
        }
    }
    for(int i=0; i<N*N; i++){
        cout<<sum[i]<<"\n";
    }
    mergesort(sum, 0, k-1);
   // for(int i=0; i<N; i++) cout<<data[i]<<endl;
    for(int i=0; i<M; i++){
        int number;
        cin>>number;
        if(mysearch(sum, 0, k-1, number)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    
    return 0;
}
