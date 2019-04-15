#include <iostream>
 
using namespace std;
const long long MAXN = 1e5+5;
long long tree[4*MAXN];
long long x[MAXN];
long long g[MAXN];
long long d[MAXN];
long long s[MAXN];
long long tog[MAXN];
void build(long long curr,long long l,long long r){
    if(l==r){
        tree[curr] = s[l-1]-x[l];
    }else{
        long long mid = (l+r)/2;
        build(2*curr,l,mid);
        build(2*curr+1,mid+1,r);
        tree[curr] = min(tree[2*curr],tree[2*curr+1]);
    }
    
}
long long query(long long curr,long long l,long long r,long long val){
    if(l == r){
        if(tree[curr] <=val){
            return l;
        }else{
            return 1e9;
        }
    }else{
        long long mid = (l+r)/2;
        if(tree[2*curr]<=val){
            return query(2*curr,l,mid,val);
        }else{
            return query(2*curr+1,mid+1,r,val);
        }
    }
}
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>x[i]>>g[i]>>d[i];
        s[i] = s[i-1]+d[i];
        tog[i] = tog[i-1]+g[i];
    }
    build(1,1,n);
    long long ans = tog[1];
    for(long long i=1;i<=n;i++){
        long long pos = query(1,1,n,s[i]-x[i]);
        if(pos!=1e9){
            ans = max(ans,tog[i]-tog[pos-1]);
        }
    }
    cout<<ans<<endl;
}
