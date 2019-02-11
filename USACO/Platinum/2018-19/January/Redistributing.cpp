#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
const long long MAXN = 3e5+5;
int dp[MAXN];
int pre[MAXN];
pair<int,int> tree[4*MAXN];

void build(int pos,int l, int r){
    if(l == r){
        tree[pos] = make_pair(dp[l],pre[l]);
        return;
    }
    int mid = (l+r)/2;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
    tree[pos] = min(tree[2*pos],tree[2*pos+1]);
    
}
void update(int node,int start,int end,int indx,int val){
    if(start == end){
     //   cout<<node<<" "<<end<<endl;
        tree[node] = make_pair(val,pre[indx]);
        
    }else{
        int mid = (start+end)/2;
        if(start<=indx && indx<=mid){
            update(2*node,start,mid,indx,val);
        }else{
            update(2*node+1,mid+1,end,indx,val);
        }
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
pair<int,int> query(int node,int start,int end,int l,int r){
    if(r<start ||end<l){
        return make_pair(1e9,1e9);
        
    }else{
        //std::cout<<start<<" "<<end<<endl;
        if(l<=start && end<=r){
            return tree[node];
        }
        int mid = (start+end)/2;
        auto p1 = query(2*node,start,mid,l,r);
        auto p2 = query(2*node+1,mid+1,end,l,r);
       
        return min(p1,p2);
    }
}
int main() {
   // ifstream cin("redistricting.in");
   // ofstream cout("redistricting.out");
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        dp[i+1] = 1e9;
        if(s[i] == 'H'){
            pre[i+1] = pre[i] + 1;
        }else{
            pre[i+1] = pre[i] - 1;
        }
    }
    build(1,0,n);
    if(s[0] == 'G'){
        dp[1] = 1;
        update(1,0,n,1,dp[1]);
    }else{
        dp[1] = 0;
        update(1,0,n,1,dp[1]);
        
    }
    
   // cout<<query(1,1,1,1,n).first<<endl;
    for(int i=2;i<=n;i++){
         auto hold = query(1,0,n,max(0,i-k),i-1);
         dp[i] = hold.first + (pre[i]<=hold.second);
         update(1,0,n,i,dp[i]);
         //cout<<hold.second<<endl;
         if(i == 9){
             //cout<<hold.second<<endl;
         }
         //cout<<i<<" "<<dp[i]<<" "<<pre[i]<<endl;
    }
    cout<<dp[n]<<endl;
    
}
