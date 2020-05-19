//
//  main.cpp
//  random
//
//  Created by Metis Sotangkur on 4/24/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    /*
    vector<pair<int, int>> v;
    vector<int> v1;
    vector<int> v2;
    int count = 60;
    for(int i=0; i<60; i++){
        int p = rand()%9;
        v1.push_back(p);
    }
    for(int i=0; i<60; i++){
        int q = rand()%19;
        v2.push_back(q);
    }
    cout<<"{";
    for(int i=0; i<60; i++){
        cout<<"{"<<v1[i]<<", "<<v2[i]<<"}, ";
    }
    
    cout<<"}";*/
    vector<pair<int, int>> v1 = {{0, 5}, {0, 8}, {0, 10},{0, 16},{1, 2}, {1, 5}, {1, 8}, {2, 0}, {2, 16},{4, 7}, {4, 13}, {4, 17},{5, 5},  {5, 17}, {6, 6},  {6, 7}, {6, 10}, {6, 11}, {6, 14},{7, 0},  {7, 6}, {8, 1},{8, 3},{8, 15},{8, 18}};
    vector<pair<int, int>> v2 = {{4, 5}, {7, 7}, {5, 2}, {2, 5}, {4, 17},{8, 17},{6, 12},{8, 6}, {8, 12},{1, 1}, {0, 3},  {8, 6}, {6, 1},  {8, 5},  {2, 15}, {7, 1}, {7, 8},  {7, 10}, {1, 10}};
    vector<pair<int, int>> v3 = {{4, 9}, {7, 5}, {5, 13},{2, 2}, {4, 8}, {8, 0}, {6, 9}, {8, 16},{8, 2}, {1, 14},{0, 2},  {8, 3}, {6, 11}, {8, 14}, {0, 15}, {2, 2}, {7, 12}, {7, 6},  {7, 9}, {1, 13}, {6, 9}, {1, 15}};
    vector<pair<int, int>> v4 = {{0, 3}, {2, 7}, {4, 14},{6, 12},{6, 1}, {0, 14},{8, 13},{7, 15},{7, 5}, {2, 2}, {5, 11}, {1, 5}, {8, 5},  {0, 14}, {1, 10}, {1, 1}, {0, 1},  {3, 8}};
    vector<pair<int, int>> v5 = {{1, 7}, {2, 10},{1, 0}, {0, 17},{2, 7}, {2, 3}, {2, 9}, {4, 12},{6, 10},{4, 6}, {8, 13}, {2, 8}, {7, 16}, {1, 4},  {1, 10}, {5, 8}, {3, 18}, {8, 15}, {3, 7}, {4, 12}};
    set<pair<int, int>> s;
    for(auto x:v5){
        s.insert(x);
    }
    int k = 4504;
    cout<<k%13<<endl;
}
