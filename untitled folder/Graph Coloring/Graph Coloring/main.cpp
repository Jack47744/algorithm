#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int N, E, ans = 100;
vector<int> G[55];
bool isChecked[55];
int d(vector<int> v){
    set<int> s;
    for(auto x : v){
        if(x!=-1) s.insert(x);
    }
    return s.size();
}
void f(int now, vector<int> v){
    if(d(v) >= ans) return;
    if(now == N){
        ans = min(ans, d(v));
        return;
    }
    else{
        isChecked[now] = true;
        for(int i=1; i<=now+1; i++){
            bool a = true;
            for(int x : G[now]){
                if(v.size()>x and v[x] == i) a = false;
            }
            vector<int> tmp = v;
            if(a){
                tmp.push_back(i);
                f(now+1, tmp);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> v;
    set<int> s;
    f(0, v);
    cout<<ans<<endl;
    return 0;
}

