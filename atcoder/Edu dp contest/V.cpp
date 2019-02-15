#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long MAXN = 100100;
 
vector<long long> v1[MAXN];
    long long n,m;
    long long up[MAXN];
    long long down[MAXN];
    vector<long long> pref[MAXN];
    vector<long long> suff[MAXN];
int add(int x, int y){ x+=y;if(x>=m) x-=m;return x;}
 
int mul(int x, int y){ x=(long long)x*y%m;return x;}
void fix(long long x){
    for(auto& y:v1[x]){
        v1[y].erase(find(v1[y].begin(),v1[y].end(),(long long)x));
        fix(y);
    }
}
void dfs(int x){
    down[x]=1;
    for(auto&y:v1[x]){
        dfs(y);
        down[x]=mul(down[x],down[y]+1);
    }
    int sz=v1[x].size();
   // cout<<sz<<endl;
    pref[x].resize(sz+1);
    suff[x].resize(sz+1);
    pref[x][0]=suff[x][sz]=1;
    for(int i=0;i<sz;i++){
        pref[x][i+1]=mul(pref[x][i],1+down[v1[x][i]]);
        //cout<<x<<" "<<i+1<<" "<<pref[x][i+1]<<endl;
    }
    for(int i=sz-1;i>=0;i--){
        suff[x][i] = mul(suff[x][i+1],1+down[v1[x][i]]);
        //cout<<x<<" "<<i<<" "<<suff[x][i]<<endl;
    }
}
void dfs2(long long x){
    //cout<<1234<<endl;
    for(int i=0;i<v1[x].size();i++){
        int y=v1[x][i];
        up[y]=mul(up[x],mul(pref[x][i],suff[x][i+1]));
        up[y] = add(up[y],1);
        
        dfs2(y);
    }
}
int main(){
 
    cin>>n>>m;
    for(long long i=1;i<n;i++){
        long long x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    fix(1);
    
    dfs(1);
    up[1] = 1;
    dfs2(1);
    for(long long i=1;i<=n;i++){
        //cout<<up[i]<<" "<<down[i]<<" ";
        cout<<mul(up[i],down[i])<<endl;
    }
}
