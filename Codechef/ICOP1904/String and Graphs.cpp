#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,x;
const int MAXN = 1010;
string s;
char val[MAXN];
int dp[MAXN][MAXN];
vector<pair<int,int>> v1[MAXN];
priority_queue<pair<int,pair<int,int>>> q1;
void dijkstras(){
    while(!q1.empty()){
        
        auto hold = q1.top();
        int dist = -1*hold.first;
        int len = hold.second.first;
        int node = hold.second.second;
        
        q1.pop();
        if(dist>dp[node][len]){
            continue;
        }
      //  cout<<node<<" "<<len<<endl;
        for(int i=0;i<v1[node].size();i++){
            int tempnode = v1[node][i].first;
            int tempw = v1[node][i].second;
         
            if(len<x && val[tempnode] == s[len] && dp[tempnode][len+1]>dp[node][len]+tempw){
                dp[tempnode][len+1]=dp[node][len]+tempw;
                q1.push(make_pair(-1*dp[tempnode][len+1],make_pair(len+1,tempnode)));
            }
            if(dp[tempnode][len]>dp[node][len]+tempw){
                dp[tempnode][len] = dp[node][len]+tempw;
                q1.push(make_pair(-1*dp[tempnode][len],make_pair(len,tempnode)));
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
        for(int i=0;i<MAXN;i++){
            v1[i].clear();
            for(int j=0;j<MAXN;j++){
                dp[i][j] = 1e9;
            }
        }
        cin>>n>>m>>x;
        cin>>s;
        for(int i=1;i<=n;i++){
            cin>>val[i];
            if(val[i] == s[0]){
                q1.push(make_pair(0,make_pair(1,i)));
                dp[i][1] = 0;
            }
            
        }
        for(int i=1;i<=m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            v1[x].push_back(make_pair(y,w));
            v1[y].push_back(make_pair(x,w));
            
            
        }
        
        dijkstras();
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            ans = min(ans,dp[i][x]);
            
        }
        if(ans == 1e9){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
        
    }
}
