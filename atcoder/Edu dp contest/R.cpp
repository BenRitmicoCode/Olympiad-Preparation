#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>> adjmatr;
const long long MOD = 1e9 + 7;
vector<vector<long long>> mult(vector<vector<long long>> a, vector<vector<long long>> b){
    vector<vector<long long>> c;
    for(long long i=0;i<=52;i++){
        vector<long long> temp;
        for(long long j=0;j<=52;j++){
            temp.push_back(0);
        }
        c.push_back(temp);
      
    }
    for(long long i=1;i<=50;i++){
        for(long long j=1;j<=50;j++){
            for(long long k=1;k<=50;k++){
               // cout<<i<<" "<<j<<" "<<k<<endl;
                c[i][j] = c[i][j] +((a[i][k]*b[k][j])+MOD)%MOD;
                c[i][j]%=MOD;
            }
        }
    }
    return c;
}
vector<vector<long long>> modpow(vector<vector<long long>> c,long long k){
    
    if(k==1){
        return c;
    }
    auto a = modpow(c,k/2);
    auto b = mult(a,a);
    
    if(k%2){
        b = mult(b,c);
    }
    return b;
}
int main(){
    long long n,k;
    cin>>n>>k;
    for(long long i=0;i<=52;i++){
        vector<long long> temp;
        for(long long j=0;j<=52;j++){
            temp.push_back(0);
        }
        adjmatr.push_back(temp);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            cin>>adjmatr[i][j];
        }
    }
    auto ans = modpow(adjmatr,k);
    long long res = 0;
    for(long long i=0;i<=50;i++){
        for(long long j=0;j<=50;j++){
            res+=ans[i][j];
            res%=MOD;
        }
    }
    cout<<res<<endl;
}
