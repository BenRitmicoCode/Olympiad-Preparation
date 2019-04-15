#include <iostream>

using namespace std;
long long n;
long long a[20];
long long dp[20][11][11][2][2];
void fix(){
    for(long long i=0;i<=19;i++){
        for(long long j=0;j<=10;j++){
            for(long long k=0;k<=10;k++){
                for(long long l=0;l<=1;l++){
                    for(long long m=0;m<=1;m++){
                        dp[i][j][k][l][m] = -1;
                    }
                }
            }
        }
    }
}
long long first,second;
long long rec(long long curr,long long prev,long long prev2,long long flag,long long leading){
    if(curr == -1){
        return 1;
    }
    if(dp[curr][prev][prev2][flag][leading]!=-1){
        return dp[curr][prev][prev2][flag][leading];
    }
    long long ans = 0;
    long long hold = 9;
    if(flag == 1){
        hold = a[curr];
    }
    for(long long i=0;i<=hold;i++){
        if(i == prev||i==prev2){
            continue;
        }
        if(leading){
            if(i ==0){
                ans+=rec(curr-1,10,prev,flag && i==a[curr],1);
            }else{
                ans+=rec(curr-1,i,prev,flag && i==a[curr],0);
            }
        }else{
            ans+=rec(curr-1,i,prev,flag && i==a[curr],0);
        }
    }
    return dp[curr][prev][prev2][flag][leading] = ans;
}
int main(){
    long long x,y;
    cin>>x>>y;
    x--;
    fix();
    if(x == 0){
    
        first = 1;
    }else if(x == -1){
        first = 0;
    }else{
        long long counter = 0;
        while(x>0){
            a[counter] = x%10;
            x/=10;
            counter++;
        }
        
        first = rec(counter-1,10,10,1,1);
    }
    fix();
    if(y == 0){
    
        second = 1;
    }else{
        long long counter = 0;
        while(y>0){
            a[counter] = y%10;
            y/=10;
            counter++;
        }
        second = rec(counter-1,10,10,1,1);
    }
    cout<<second-first<<endl;
}
