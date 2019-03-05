#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int MAXN = 100010;
int calc(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
vector<pair<int,int>> v1;
int sumtree[10*MAXN];
int maxtree[10*MAXN];
int dist[MAXN];
int diff[MAXN];
void buildsumtree(int node,int l,int r){
    if(l == r){
        sumtree[node] = dist[l];
        return;
    }
    int mid = (l+r)/2;
    buildsumtree(2*node,l,mid);
    buildsumtree(2*node+1,mid+1,r);
    sumtree[node] = sumtree[2*node]+sumtree[2*node+1];
}

void buildmaxtree(int node,int l,int r){
    if(l == r){
        maxtree[node] = diff[l];
        return;
    }
    int mid = (l+r)/2;
    buildmaxtree(2*node,l,mid);
    buildmaxtree(2*node+1,mid+1,r);
    maxtree[node] = max(maxtree[2*node],maxtree[2*node+1]);
}
int querysumtree(int node,int l,int r,int tl,int tr){
    if(r<tl||l>tr||l>r){
        return 0;
    }
    if(l>=tl && r<=tr){
        return sumtree[node];
    }
    int mid = (l+r)/2;
    return querysumtree(node*2,l,mid,tl,tr)+querysumtree(node*2+1,mid+1,r,tl,tr);
}
int querymaxtree(int node,int l,int r,int tl,int tr){
    if(r<tl||l>tr||l>r){
        return -1e9;
    }
    if(l>=tl && r<=tr){
        return maxtree[node];
    }
    int mid = (l+r)/2;
    return max(querymaxtree(node*2,l,mid,tl,tr),querymaxtree(node*2+1,mid+1,r,tl,tr));
}
void updatesum(int node,int l,int r,int ind,int val){
    if(l == r){
        sumtree[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(ind<=mid){
        updatesum(2*node,l,mid,ind,val);
    }else{
        updatesum(2*node+1,mid+1,r,ind,val);
    }
    sumtree[node] = sumtree[2*node]+sumtree[2*node+1];
}
void updatemax(int node,int l,int r,int ind,int val){
    if(l == r){
        maxtree[node] = val;
        return;
    }
    
    int mid = (l+r)/2;
    if(ind<=mid){
        updatemax(2*node,l,mid,ind,val);
    }else{
        updatemax(2*node+1,mid+1,r,ind,val);
    }
    maxtree[node] = max(maxtree[2*node],maxtree[2*node+1]);
}

int main(){
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
    int n,q;
    fin>>n>>q;
    v1.push_back(make_pair(0,0));
    for(int i=1;i<=n;i++){
        int x,y;
        fin>>x>>y;
        v1.push_back(make_pair(x,y));
        
    }
    for(int i=2;i<=n;i++){
        dist[i] = calc(v1[i].first,v1[i].second,v1[i-1].first,v1[i-1].second);
        
    }
    for(int i=2;i<n;i++){
        diff[i] = dist[i]+dist[i+1]-calc(v1[i+1].first,v1[i+1].second,v1[i-1].first,v1[i-1].second);
        
    }
    buildsumtree(1,1,n);
    buildmaxtree(1,1,n);
    for(int i=0;i<q;i++){
        char x;
        fin>>x;
        if(x == 'Q'){
            int l,r;
            fin>>l>>r;
            int hold = querysumtree(1,1,n,l+1,r);
            int hold2 = querymaxtree(1,1,n,l+1,r-1);
           // fout<<hold2<<endl;
            if(hold2<0){
                hold2 = 0;
            }
            fout<<hold-hold2<<endl;
        }else{
            int ind,x,y;
            fin>>ind>>x>>y;
            v1[ind].first = x;
            v1[ind].second = y;
            dist[ind] = calc(v1[ind].first,v1[ind].second,v1[ind-1].first,v1[ind-1].second);
            updatesum(1,1,n,ind,dist[ind]);
            if(ind!=100000){
                dist[ind+1] = calc(v1[ind+1].first,v1[ind+1].second,v1[ind].first,v1[ind].second);
                updatesum(1,1,n,ind+1,dist[ind+1]);
            }
            
            for(int j=max(1,ind-1);j<=min(n-1,ind+1);j++){
                diff[j] = dist[j]+dist[j+1]-calc(v1[j+1].first,v1[j+1].second,v1[j-1].first,v1[j-1].second);
                updatemax(1,1,n,j,diff[j]);
            }
            
        }
    }
}
