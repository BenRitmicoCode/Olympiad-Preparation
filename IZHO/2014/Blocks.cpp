#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN];
int dp[110][MAXN];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[j][i] = 1e9;
        }
    }
    dp[1][0] = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        
        dp[1][i] = 0;
        dp[1][i] =max(dp[1][i-1],arr[i]);
        
    }
    dp[1][0] = 1e9;
    for(int i=2;i<=k;i++){
        stack<int> s1,s2;
        for(int j=1;j<=n;j++){
            int tempdp = dp[i-1][j-1];
           
            while(s1.size() && s1.top()<arr[j]){
                tempdp = min(tempdp,s2.top());
                s1.pop();
                s2.pop();
            }
            if(s1.empty()||tempdp+arr[j]<s1.top()+s2.top()){
                s1.push(arr[j]);
                s2.push(tempdp);
               // cout<<arr[j]<<" "<<tempdp<<endl;
            }
            if(j>=i){
                dp[i][j] = s1.top()+s2.top();
                
                //cout<<dp[i][j]<<endl;
            }
        }
    }
    cout<<dp[k][n]<<endl;
}
