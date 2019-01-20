#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
const int MAXN = 3010;
int a[MAXN];
int dp[MAXN][110][110][3];
vector<int> b;
int rec(int i,int j,int k,int l){
   // cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
    if(dp[i][j][k][l]!=-1){
        return dp[i][j][k][l];
    }
    if(i>=n && j>k){
        return 0;
    }
    else if(i<n && j<=k && m!=0){
        dp[i][j][k][l] = 0;
        if(l){
            dp[i][j][k][l] = max(rec(i+1,j,k,1-l),rec(i,j,k-1,1-l));
        }else{
            dp[i][j][k][l] = max(rec(i+1,j,k,l),max(a[i]+rec(i+1,j,k,1-l),b[j]+rec(i,j+1,k,1-l)));
        }
        return dp[i][j][k][l];
    }
    else if(i<n ||m==0){
        dp[i][j][k][l] = 0;
        if(l){
            dp[i][j][k][l] = rec(i+1,j,k,1-l);
        }else{
            dp[i][j][k][l] = max(rec(i+1,j,k,l),a[i]+rec(i+1,j,k,1-l));
        }
        return dp[i][j][k][l];
    }else{
        dp[i][j][k][l] = 0;
        if(l){
            dp[i][j][k][l] = rec(i,j,k-1,1-l);
        }else{
            dp[i][j][k][l] = b[j]+rec(i,j+1,k,1-l);;
        }
        return dp[i][j][k][l];
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=101;j++){
            for(int k=0;k<=101;k++){
                for(int l=0;l<=2;l++){
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    cin>>m;
    b.resize(m+2);
    for(int j=1;j<=m;j++){
        cin>>b[j];
    }
    sort(b.begin(),b.end());
    reverse(b.begin()+1,b.end());
    if(m == 0){
        cout<<rec(0,0,0,0)<<endl;
        return 0;
    }
    cout<<rec(0,1,m,0)<<endl;
}
