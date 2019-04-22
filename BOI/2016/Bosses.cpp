#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 5010;
vector<int> v1[MAXN];
vector<int> g[MAXN];
int n;
bool visited[MAXN];
int dp[MAXN];
bool rootat(int root){
    queue<int> q1;
    q1.push(root);
    visited[root] = true;
    dp[root] = true;
    while(!q1.empty()){
        int curr = q1.front();
        
        q1.pop();
        for(int x:v1[curr]){
            if(!visited[x]){
                visited[x] = true;
                //cout<<x<<" "<<curr<<endl;
                dp[x] = dp[curr] + 1;
                q1.push(x);
            }
        }
    }
    //cout<<1234<<endl;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            
            return false;
        }
    }
    return true;
}
void rm(){
    for(int i=1;i<=n;i++){
       
        visited[i] = false;
        dp[i] = 0;
    }
}
/*void dfs(int curr,int par){
    dp[curr] = 1;
    for(int x:g[curr]){
        if(x!=par){
            dfs(x,curr);
            dp[curr]+=dp[x];
        }
    }

  //  cout<<curr<<" "<<dp[curr]<<endl;
}*/
int main(){

    cin>>n;
    
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=1;j<=num;j++){
            int x;
            cin>>x;
            v1[x].push_back(i);
        }
    }
    int ans = 1e9;
    for(int i=1;i<=n;i++){
        rm();
        if(!rootat(i)){
            continue;
        }
        //dfs(i,i);
        int tempans = 0;
        for(int j=1;j<=n;j++){
            tempans += dp[j];
        }
        ans = min(tempans,ans);
    }
    cout<<ans<<endl;
}
