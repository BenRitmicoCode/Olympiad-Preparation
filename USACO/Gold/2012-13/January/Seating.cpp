#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 300100;
struct node{
    int lft,rht,mx;
    node(){
        lft =rht = mx = 0;
    }
};
node tree[4*MAXN];

void build(int nod,int l,int r){
    if(l == r){
        tree[nod].lft = tree[nod].rht = tree[nod].mx = 1;
        return;
    }
    int mid = (l+r)/2;
    build(2*nod,l,mid);
    build(2*nod+1,mid+1,r);
    tree[nod].lft = tree[nod].rht = tree[nod].mx =  r-l+1;
}
int query(int nod,int l,int r,int k){
    
    if(tree[nod].mx<k){
        return -1;
    }
    if(tree[nod].lft>=k){
        return l;
    }
    int mid = (l+r)/2;
    int temp = query(2*nod,l,mid,k);
    if(temp>0){
        return temp;
    }
    if(tree[nod*2].rht + tree[nod*2+1].lft >= k){
        return mid - tree[nod*2].rht+1;
    }
    return query(2*nod+1,mid+1,r,k);
}
void update(int nod,int l,int r,int tl,int tr,int ori,int curr){
    
    if(curr<0){
        if(tree[nod].mx == 0){
            curr = 0;
        }else if(tree[nod].mx == r-l+1){
            curr = 1;
        }
    }
    
    if(l>r||tl>r||tr<l){
        
        if(curr>-1){
            tree[nod].lft = tree[nod].rht = tree[nod].mx = curr*(r-l+1);
        }
        return;
    }
    
    if(l>=tl && r<=tr){
        tree[nod].lft = tree[nod].rht = tree[nod].mx = ori*(r-l+1);
        
       // fout<<l<<" "<<r<<" "<<tl<<" "<<tr<<" "<<tree[nod].mx<<endl;
        return;
    }
    int mid = (l+r)/2;
    update(nod*2,l,mid,tl,tr,ori,curr);
    update(nod*2+1,mid+1,r,tl,tr,ori,curr);
    tree[nod].lft = tree[2*nod].lft;
    if(tree[nod].lft == mid -l+1){
        tree[nod].lft += tree[2*nod+1].lft;
    }
    tree[nod].rht = tree[2*nod+1].rht;
    if(tree[nod].rht == r-mid){
        tree[nod].rht += tree[2*nod].rht;
    }
    tree[nod].mx = max(max(tree[2*nod].mx,tree[2*nod+1].mx),tree[2*nod].rht+tree[2*nod+1].lft);
    
   // fout<<l<<" "<<r<<" "<<tl<<" "<<tr<<" "<<tree[nod].mx<<endl;
    
}
int main() {
    ifstream fin("seating.in");
    ofstream fout("seating.out");
    int n,q;
    fin>>n>>q;
    int ans = 0;
    build(1,1,n);
    for(int i=0;i<q;i++){
        char x;
        fin>>x;
        if(x == 'A'){
            
            int val;
            fin>>val;
            int hold = query(1,1,n,val);
            
            if(hold == -1){
                ans++;
               
                continue;
            }
            //fout<<val<<" "<<hold<<" "<<hold+val-1<<endl;
            update(1,1,n,hold,hold+val-1,0,-1);
        }else{
            int l,r;
            fin>>l>>r;
            update(1,1,n,l,r,1,-1);
        }
    }
    fout<<ans<<endl;
}
