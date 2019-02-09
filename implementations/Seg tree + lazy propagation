#include <iostream>
#include <fstream>
using namespace std;
const long long MAXN = 2e5+5;
long long n,q;
long long mintree[5*MAXN];
long long sumtree[5*MAXN];
long long lazy[5*MAXN];
long long arr[MAXN];
void push(long long v){
   
    lazy[v] = 0;
}
void build(long long pos,long long l,long long r){
    if(l == r){
        mintree[pos] = arr[l];
        sumtree[pos] = arr[l];
        return;
    }
    long long mid = (l+r)/2;
    build(2*pos,l,mid);
    build(2*pos+1,mid+1,r);
    mintree[pos] = min(mintree[2*pos],mintree[2*pos+1]);
    sumtree[pos] = sumtree[2*pos] + sumtree[2*pos+1];
}
void update(long long v,long long tl,long long tr,long long l,long long r,long long c){
    //fout<<v<<endl;
    //fout<<tl<<" "<<tr<<" "<<l<<" "<<r<<endl;
    if(tl == 1 && tr == 1){
       // fout<<l<<" "<<r<<endl;
    }
    if(lazy[v]){
        sumtree[v]+=(tr-tl+1)*lazy[v];
        if(tr!=tl){
            mintree[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            mintree[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            
        }
        lazy[v] = 0;

    }
    if(tr<l||tl>r){
        return;
    }
    if(tl >= l && tr <= r){
        lazy[v]+=c;
        mintree[v]+=c;
        sumtree[v]+=(tr-tl+1)*lazy[v];
        if(tr!=tl){
            mintree[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            mintree[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            
        }
        lazy[v] = 0;
       // fout<<tl<<" "<<tr<<" "<<sumtree[v]<<endl;
        //fout<<tl<<" "<<tr<<" "<<sumtree[v]<<endl;
    }else{
        
        long long mid = (tl+tr)/2;
        //fout<<tl<<" "<<tr<<" "<<l<<" "<<min(r,mid)<<" "<<lazy[2*v]<<endl;
        update(v*2,tl,mid,l,r,c);
        update(v*2+1,mid+1,tr,l,r,c);
        mintree[v] = min(mintree[v*2],mintree[v*2+1]);
        sumtree[v] = sumtree[v*2] + sumtree[v*2+1];
     //  fout<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<sumtree[v]<<endl;
    }
}
long long minquery(long long v, long long tl, long long tr, long long l, long long r) {
   // fout<<v<<endl;
    if (l > r){
        return 1e9;
    }
    if (l <= tl && tr <= r){
        return mintree[v];
    }
    if(lazy[v]){
        sumtree[v]+=(tr-tl+1)*lazy[v];
        if(tr!=tl){
            mintree[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            mintree[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            
        }
        lazy[v] = 0;
    }
    long long tm = (tl + tr) / 2;
    return min(minquery(v*2, tl, tm, l, min(r, tm)),minquery(v*2+1, tm+1, tr, max(l, tm+1), r));
}
long long sumquery(long long v, long long tl, long long tr, long long l, long long r) {
    //fout<<tl<<" "<<tr<<endl;
    if(tl>r||tr<l){
        return 0;
    }
    if(lazy[v]){
        sumtree[v]+=(tr-tl+1)*lazy[v];
        if(tr!=tl){
            mintree[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            mintree[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            
        }
        lazy[v] = 0;
    }
    
    if (l <= tl && tr <= r){
        
        return sumtree[v];
    }
    long long tm = (tl + tr) / 2;
    return sumquery(v*2, tl, tm, l, r)+sumquery(v*2+1, tm+1, tr, l, r);
}
int main(){
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    fin>>n>>q;
    for(long long i=1;i<=n;i++){
        fin>>arr[i];
    }
    build(1,1,n);
    
    while(q--){
        char x;
        fin>>x;
        if(x == 'M'){
            long long a,b;
            fin>>a>>b;
            fout<<minquery(1,1,n,a,b)<<endl;
        }
        if(x == 'S'){
            long long a,b;
            fin>>a>>b;
            fout<<sumquery(1,1,n,a,b)<<endl;
        }
        if(x == 'P'){
            long long a,b,c;
            fin>>a>>b>>c;
            update(1,1,n,a,b,c);
        }

    }
    
}
