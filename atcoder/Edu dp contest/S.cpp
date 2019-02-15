#include <iostream>
#include <algorithm>
using namespace std;
string s;
long long d;
long long dp[10012][112][2];
const long long MOD = 1e9+7;
long long rec(long long digit,long long m,long long flag){
    
    if(digit<0){
        if(m==0){
            return 1;
        }else{
            return 0;
        }
    }
    if(dp[digit][m][flag]!=-1){
        return dp[digit][m][flag];
    }
    dp[digit][m][flag] = 0;
    if(flag == 1){
        for(long long j=0;j<s[digit]-48;j++){
            dp[digit][m][flag] += rec(digit-1,(m+j)%d,0);
        }
        dp[digit][m][flag] += rec(digit-1,(m+(s[digit]-48))%d,1);
    }else{
        for(long long j=0;j<=9;j++){
            dp[digit][m][flag] += rec(digit-1,(m+j)%d,0);
        }
    }
    dp[digit][m][flag]%=MOD;
    
    return dp[digit][m][flag];
}
int main(){
    cin>>s>>d;
    for(long long i=0;i<=10010;i++){
        for(long long j=0;j<=110;j++){
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    reverse(s.begin(),s.end());
    cout<<(rec(s.size()-1,0,1)-1+MOD)%MOD<<endl;
}
