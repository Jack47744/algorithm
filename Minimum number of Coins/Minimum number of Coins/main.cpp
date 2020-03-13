//
//  main.cpp
//  Minimum number of Coins
//
//  Created by Metis Sotangkur on 3/13/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int money, coin = 0;
    cin>>money;
    vector<int> myBank = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    for(int i = myBank.size()-1; i>=0; i--){
        while(money - myBank[i]>=0){
            coin++;
            money -= myBank[i];
        }
    }
    cout<<coin<<endl;
    return 0;
}
