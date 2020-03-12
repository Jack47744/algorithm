//
//  main.cpp
//  quicksort
//
//  Created by Metis Sotangkur on 2/4/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
void quicksort(int data[], int left, int right){
    if(left>=right) return;
    int tmp = data[left];
    int i = left;
    int j = right+1;
    while(i<j){
        while(data[--j]>tmp);
        while(data[++i]<tmp){
            if(i==right) break;
        }
        if(i<j){
            int tmp2 = data[i];
            data[i] = data[j];
            data[j] = tmp2;
        }
    }
    int tmp2 = data[j];
    data[j] = tmp;
    data[left] = tmp2;
    quicksort(data, left, j-1);
    quicksort(data, j+1, right);
    
}
int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int data[N];
    for(int i=0; i<N; i++) cin>>data[i];
    quicksort(data, 0, N-1);
    for(int i=0; i<N; i++) cout<<data[i]<<endl;
    return 0;
}
