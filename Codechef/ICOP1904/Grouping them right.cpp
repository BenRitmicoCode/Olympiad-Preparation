#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x,y;
        cin>>x>>y;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            a.push_back(c);
        }
        
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            b.push_back(c);
        }
       int cost[n][n][2];
       
        for(int i=0;i<n;i++){
            cost[i][i][0] = b[i]*(a[i] == 1);
            cost[i][i][1] = b[i]*(a[i] == 0);
            for(int j=i+1;j<n;j++){
                for(int k=0;k<=1;k++){
                    if(k==0){
                        cost[i][j][k] = cost[i][j-1][k] + (b[j]*(a[j] == 1));
                    }else{
                        cost[i][j][k] = cost[i][j-1][k] + (b[j]*(a[j] == 0));
                    }
                
                    //cout<<i<<" "<<j<<" "<<k<<" "<<cost[i][j][k]<<endl;
                }
            }
        }
        int dp[n][2];
        for(int i=0;i<n;i++){
            for(int j=x;j<=y;j++){
                for(int k=0;k<=1;k++){
                    dp[i][k] = 1e9;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=x;j<=y;j++){
                for(int k=0;k<=1;k++){
                    if(i-j>=0){
                        dp[i][k] = min(dp[i-j][1-k] + cost[i-j+1][i][k],dp[i][k]);
                    }else if(i-j+1 == 0){
                        dp[i][k] = min(dp[i][k],cost[0][i][k]);
                    }
                }
            }
        }
        if(dp[n-1][0] == 1e9||dp[n-1][1] == 1e9){
            cout<<-1<<endl;
            continue;
        }
        cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
    }
}
