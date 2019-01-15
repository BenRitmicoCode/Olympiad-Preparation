#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;
const int MAXN = 1010;
vector<int> v1[MAXN];
vector<int> temp;
int val[MAXN];
int dp[MAXN];
int ans;
int main() {
    ifstream fin("buffet.in");
    ofstream fout("buffet.out");
   int n,e;
   fin>>n>>e;
   for(int i=1;i<=n;i++){
       fin>>val[i];
       int t;
       fin>>t;
       while(t--){
           int x;
           fin>>x;
           v1[i].push_back(x);
       }
   }
   temp.push_back(0);
   for(int i=1;i<=n;i++){
       temp.push_back(i);
   }
   sort(temp.begin(),temp.end(),[](int x,int y){
      return val[x]<val[y]; 
   });
   for(int i=n;i>=1;i--){
       int d[n+1];
       for(int i=0;i<=n;i++){
           d[i] = -1;
       }
       int source = temp[i];
       d[source] = 0;
       queue<int> q1;
       q1.push(source);
       while(!q1.empty()){
           int hold = q1.front();
           q1.pop();
           for(auto x:v1[hold]){
               if(d[x]==-1){
                   d[x] = d[hold]+1;
                   q1.push(x);
               }
           }
       }
       int res = val[source];
      // fout<<res<<endl;
       for(int j=1;j<=n;j++){
            if(d[j]!=-1){
                
                res = max(res,val[source]+dp[j] - (e*d[j]));
            }
       }
       ans = max(ans,res);
       dp[source] = res;
     //  fout<<dp[source]<<endl;
   }
   fout<<ans<<endl;
}
