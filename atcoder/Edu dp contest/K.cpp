#include <iostream>
#include <iomanip>
using namespace std;
 
const long long MAXN = 100010;
 
int dp[MAXN];
int arr[MAXN];
 
int main() {
    int n,k;
    cin>>n>>k;
    int mine = 1000000000;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mine = min(arr[i],mine);
    }
    for(int i=mine;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0){
                if(!dp[i-arr[j]]){
                    dp[i] = 1;
                }
            }
        }
    }
    if(dp[k]){
        cout<<"First";
    }else{
        cout<<"Second";
    }
}
