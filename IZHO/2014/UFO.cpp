#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e6 + 5;
int n,m,r,k,p;
vector<vector<int>> a;
vector<int> temp;
int remain;
struct segtree{
    
    vector<int> v1;
    int n;
    
    void reset(int n) {
        this -> n = n;
        v1.resize((n * 6) + 10);
        
    }
    void update(int curr,int l,int r,int u,int val){
       // cout<<l<<" "<<r<<endl;
        if(l == r){
            v1[curr] = val;
            return;
        }
        int mid = (l+r)/2;
        if(u<=mid){
            update(2*curr,l,mid,u,val);
        }else{
            update(2*curr+1,mid+1,r,u,val);
        }
        v1[curr] = max(v1[2*curr],v1[2*curr+1]);
    }
    void findfirst(int curr,int l,int r,int x){
        if(remain == 0||v1[curr]<x){
           //cout<<l<<" "<<r<<" "<<v1[curr]<<endl;
            return;
        }
        if(l == r){
            remain--;
            temp.push_back(l);
        }else{
            int mid = (l+r)/2;
            findfirst(2*curr,l,mid,x);
            findfirst(2*curr+1,mid+1,r,x);
        }
    }
    void findlast(int curr,int l,int r,int x){
        if(remain == 0||v1[curr]<x){
           
            return;
        }
        if(l == r){
            remain--;
            temp.push_back(l);
        }else{
            int mid = (l+r)/2;
            findlast(2*curr+1,mid+1,r,x);
            findlast(2*curr,l,mid,x);
        }
    }
};
segtree row[MAXN],col[MAXN];
int main(){
    
    cin>>m>>n>>r>>k>>p;
    
    a.resize(m+1);
    for(int i=1;i<=n;i++){
        col[i].reset(m+1);
    }
    a[0].resize(n+1);
    for(int i=1;i<=m;i++){
        
        row[i].reset(n+1);
        a[i].resize(n+1);
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
           
            row[i].update(1,1,n,j,a[i][j]);
            col[j].update(1,1,m,i,a[i][j]);
        }
    }
    for(int i=0;i<k;i++){
        temp.clear();
        remain = r;
        char z;
        cin>>z;
        int id,h;
        cin>>id>>h;
        if(z == 'W'){
            row[id].findfirst(1,1,n,h);
            for(int x:temp){
                //cout<<x<<endl;1,
                a[id][x]--;
               
                row[id].update(1,1,n,x,a[id][x]);
                col[x].update(1,1,m,id,a[id][x]);
            }
        }else if(z == 'E'){
            row[id].findlast(1,1,n,h);
            for(int x:temp){
                
                a[id][x]--;
                row[id].update(1,1,n,x,a[id][x]);
                col[x].update(1,1,m,id,a[id][x]);
            }
        }else if(z == 'N'){
            col[id].findfirst(1,1,m,h);
            
            for(int x:temp){
                
                a[x][id]--;
                
                row[x].update(1,1,n,id,a[x][id]);
                col[id].update(1,1,m,x,a[x][id]);
            }
        }else{
            col[id].findlast(1,1,m,h);
            for(int x:temp){
                a[x][id]--;
                
                //cout<<x<<endl;
                row[x].update(1,1,n,id,a[x][id]);
                col[id].update(1,1,m,x,a[x][id]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
           
        }
    }
    int ans = 0;
    
   for(int i=1;i<=m-p+1;i++){
        for(int j=1;j<=n-p+1;j++){
            if(i+p-1>m||j+p-1>n){
                continue;
            }
            int temp = a[i+p-1][j+p-1] - a[i+p-1][j-1] - a[i-1][j+p-1] + a[i-1][j-1];
            
            ans = max(ans,temp);
        }
    }
    cout<<ans<<endl;
}
