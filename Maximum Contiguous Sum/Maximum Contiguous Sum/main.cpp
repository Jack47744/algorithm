//
//  main.cpp
//  Maximum Contiguous Sum
//
//  Created by Metis Sotangkur on 2/6/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
void quickSort(int data[], int left, int right){
    if(left >= right) return;
    int tmp = data[left];
    int i = left;
    int j = right + 1;
    while(i<j){
        while(data[--j] > tmp)
        while(data[++i] < tmp) if(i == right) break;
        if(i<j){
            int tmp2 = data[i];
            data[i] = data[j];
            data[j] = tmp2;
        }
    }
    int tmp2 = data[j];
    data[j] = data[left];
    data[left] = tmp2;
    quickSort(data, left, j-1);
    quickSort(data, j+1, right);
}
bool pairsum(int data[], int left, int right, int number){
    if(left >= right) return false;
    int tmp = data[left] + data[right];
    if(tmp == number) return true;
    if(tmp >= number){
        return pairsum(data, left, right-1, number);
    }
    else return pairsum(data, left+1, right, number);
}
int main(int argc, const char * argv[]) {
    int N, M;
    //vector<int> v;
    cin>>N>>M;
    int data[N];
    for(int i=0; i<N; i++){
        cin>>data[i];
    }
    quickSort(data, 0, N-1);
    for(int i=0; i<N; i++) cout<<data[i]<<endl;
    /*sort(v.begin(), v.end());
    for(int i=0; i<N; i++) data[i]=v[i];
    for(int i=0; i<M; i++){
        int number;
        cin>>number;
        if(pairsum(data, 0, N-1, number)) cout<<"YES\n";
        else cout<<"NO\n";
        
    }*/
    
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
