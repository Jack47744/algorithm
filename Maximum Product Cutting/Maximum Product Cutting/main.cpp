#include <iostream>
using namespace std;
int ans[2000];
int maxProduct(int n){
    if(n==1 or n==0) return 0;
    if(ans[n]>0) return ans[n];
    int maxValue = 0;
    for(int i=1; i<n; i++){
        maxValue = max(maxValue, max(i*(n-i), i*(maxProduct(n-i))));
    }
    return ans[n] = maxValue;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<maxProduct(n);
    return 0;
}
