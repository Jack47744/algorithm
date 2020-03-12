#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int ans1[256][256];
void recur(int a, int b,int top,int bottom,int left,int right){
    //cout<<left<<" "<<right<<" "<<top<<" "<<bottom<<" "<<b<<endl;
    if(a==0){
        ans1[bottom-1][right-1] = b;
        return;
    }
    
    int midY = (top+bottom)/2;
    int midX = (left+right)/2;
    recur(a-1, b, top, midY, left, midX);
    recur( a-1, b-1, top, midY, midX+1, right);
    recur( a-1, b+1, midY+1, bottom, left, midX);
    recur( a-1, b, midY+1, bottom, midX+1, right);
    return;
    
}
int main()
{
    int a, b;
    cin>>a>>b;
    
    int  k = 1<<a;
    recur(a ,b ,0 ,k ,0 ,k);
    for(int i=0; i<k; i++){
        
        for(int j=0; j<k; j++) cout<<ans1[i][j]<<" ";
        cout<<"\n";
    }
    
    return 0;
}
