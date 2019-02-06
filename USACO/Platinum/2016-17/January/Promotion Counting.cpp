#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
const int MAXN = 100100;
vector<int> v1[MAXN];
int in[MAXN];
int out[MAXN];
int pos[2*MAXN];
int p[MAXN];
int timer = 0;
vector<int> tree[10*MAXN];
void build(int curr,int l,int r){
    
    if(l == r){
        tree[curr].push_back(p[pos[l]]);
        return;
    }
    int mid = (l+r)/2;
    build(2*curr,l,mid);
    build(2*curr+1,mid+1,r);
   //fout<<curr<<" "<<l<<" "<<r<<endl;
    merge(tree[2*curr].begin(),tree[2*curr].end(),tree[2*curr+1].begin(),tree[2*curr+1].end(),back_inserter(tree[curr]));
    
}
int query(int curr,int l,int r,int x,int y,int val){
    if(r<x||l>y){
        return 0;
    }
    if(x<=l && r<=y){
        return (r-l+1) - (upper_bound(tree[curr].begin(),tree[curr].end(),val)-tree[curr].begin());
    }
    int mid = (r+l)/2;
    return query(2*curr,l,mid,x,y,val) + query(2*curr+1,mid+1,r,x,y,val);
}
void dfs(int curr){
    timer++;
    in[curr] = timer;
    pos[timer] = curr;
    for(auto x:v1[curr]){
        dfs(x);
    }
    timer++;
    out[curr] = timer;
    pos[timer] = curr;
}
int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int n;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>p[i];
    }
    for(int i=2;i<=n;i++){
        int x;
        fin>>x;
        v1[x].push_back(i);
    }
    dfs(1);
    build(1,1,2*n);
    for(int i=1;i<=n;i++){
        fout<<query(1,1,2*n,in[i],out[i],p[i])/2<<endl;
    }
}
