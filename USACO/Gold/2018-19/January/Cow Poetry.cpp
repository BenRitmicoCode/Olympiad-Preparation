#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
long long currsum,lastsum;
const long long MAXN = 5010;
 long long n,m,k;
 vector<pair<long long,long long>> v1;
 long long dpend[MAXN];
 const long long MOD = 1e9+7;
 long long dp[MAXN];
     vector<long long> syl;
    vector<long long> ways;
    long long dp2[MAXN][MAXN];
    map<char,int> m1;
long long modpow(long long x, unsigned long long y) 
{ 
    long long res = 1;      // Initialize result 
  
    x = x % MOD;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 
int main(){
   ifstream fin("poetry.in");
   ofstream fout("poetry.out");
    fin>>n>>m>>k;
    for(long long i=0;i<n;i++){
        long long x,y;
        fin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    dp[0] = 1;
    for(long long i=1;i<=k;i++){
        for(long long j=0;j<v1.size();j++){
            if(i-v1[j].first>=0){
                if(i==k){
                    dpend[v1[j].second] += dp[i-v1[j].first];
                    dpend[v1[j].second]%=MOD;
                  
                }
                dp[i] += dp[i-v1[j].first];
                dp[i]%=MOD;
               // fout<<i<<" "<<v1[i].first<<endl;
            }
        }
    }
    for(long long i=0;i<m;i++){
        char x;
        fin>>x;
        m1[x]++;
    }

    for(auto it = m1.begin();it!=m1.end();it++){
        syl.push_back(it->second);
    }
    for(auto x:dpend){
        if(x>0){
            
            ways.push_back(x);
        }
    }
    
    for(long long i=0;i<syl.size();i++){
        currsum = 0;
        for(long long j=0;j<ways.size();j++){
            if(i == 0){
                dp2[i][j] = modpow(ways[j],syl[i]);
                dp2[i][j]%=MOD;
                currsum += dp2[i][j];
                currsum%=MOD;
            }else{
                dp2[i][j] += lastsum * modpow(ways[j],syl[i]);
                dp2[i][j]%=MOD;
                currsum += dp2[i][j];
                currsum%=MOD;
            }
            
        //    fout<<currsum<<endl;
            
        }
        lastsum = currsum;
    }
    fout<<currsum<<endl;
}
