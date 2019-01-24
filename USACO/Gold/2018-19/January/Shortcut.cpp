#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <queue>
using namespace std;
const long long MAXN = 10010;
vector<long long> v2[MAXN];
vector<pair<long long,long long>> v1[MAXN];
map<pair<long long,long long>,long long> m1;
long long n,m,t;
long long dp[MAXN];
long long dp2[MAXN];
long long dp3[MAXN];
long long dp4[MAXN];
long long c[MAXN];
long long par[MAXN];
void dijkstras(){
    priority_queue<pair<long long,long long>> q1;
    q1.push(make_pair(0,1));
    for(long long i=0;i<=n;i++){
        dp[i] = 1e18;
        
    }
    dp[1] = 0;

    par[1] = 1;
    while(!q1.empty()){
        
        auto hold = q1.top();
        long long dist = -1*hold.first;
        long long from = hold.second;
        
        q1.pop();
        for(auto x:v1[from]){
            if(dp[x.first]>dist + x.second){
                dp[x.first] = x.second+dist;
                par[x.first] = from;
                q1.push(make_pair(-1*dp[x.first],x.first));
            }else if(dp[x.first] == dist + x.second){
                par[x.first] = min(par[x.first],from);
                
            }
        }
    }
}

bool visited[MAXN];
long long dp5[MAXN];
long long val;
void dfs(long long curr,long long par){
    //fout<<curr<<endl;
    dp3[curr] = c[curr];
    for(auto x:v2[curr]){
        if(x== par){
            continue;
        }
        dfs(x,curr);
        dp3[curr]+=dp3[x];
        

    }
}
int main() {
    ifstream fin("shortcut.in");
    ofstream fout("shortcut.out");
    fin>>n>>m>>t;
    for(long long i=1;i<=n;i++){
        fin>>c[i];
    }
    for(long long i=1;i<=m;i++){
        long long x,y,w;
        fin>>x>>y>>w;
        v1[x].push_back(make_pair(y,w));
        v1[y].push_back(make_pair(x,w));
        m1[make_pair(x,y)] = w;
        m1[make_pair(y,x)] = w;
       
    }
    dijkstras();
    long long ans1 = 0;
    for(long long i=1;i<=n;i++){
        ans1+=(c[i]*dp[i]);
    }
    //fout<<ans1<<endl;
    int pointer = n;
    for(long long i=2;i<=n;i++){
        v2[par[i]].push_back(i);
        v2[i].push_back(par[i]);
    }
    long long ans = 0;
    dfs(1,1);
    for(long long i=1;i<=n;i++){
       // fout<<dp3[i]<<endl;
    }
    for(long long i=1;i<=n;i++){
        //fout<<dp3[i+1]<<endl;
        if(t<dp[i]){
            long long tempans = (dp3[i]*dp[i])-(t*dp3[i]);
           // fout<<((dp4[dp5[i]]))<<endl;
            ans = max(ans,tempans);
        }
    }
    fout<<ans<<endl;
}
