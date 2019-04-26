/**
    Solution: For each l,r go from l to r, whenever Cap has less votes than Iron Man, flip a vote. Go from r to l ignoring flipped votes, do the same
    
    To do this in nlogn, go backwards from n to 1, and consider the forward sweep: If i is currently iron man's vote add it to a stack, else if the stack isn't empty, we can pop the topmost element(ie closest iron man vote)
    Then for each query we can binary search on the number of extra ironman votes that exist in the stack. This sorts out the forward sweep. The backwards sweep is basically finding the minimum suffix sum in a segment, which can easily be done using a segtree 
    
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN =5e5+5;
struct node{
    int sum,suffsum;
    node(int sum = 0,int suffsum = 0){
        this->sum = sum;
        this->suffsum = suffsum;
    }
    node join(node &other){
        return node(sum+other.sum,min(other.suffsum,other.sum+suffsum));
    }
};
node a[4*MAXN + 5];
void update(int curr,int l,int r,int pos,int val){
    
    if(pos>r||pos<l){
        return;
    }
   // cout<<pos<<" "<<l<<" "<<r<<endl;
    if(l == r){
        a[curr].sum+=val;
        a[curr].suffsum+=val;
        return;
    }
    int mid = (l+r)/2;
    update(2*curr,l,mid,pos,val);
    update(2*curr+1,mid+1,r,pos,val);
    a[curr] = a[2*curr].join(a[2*curr+1]);
}
node query(int curr,int l, int r,int tl,int tr){
    if(tl>r||tr<l){
        node temp;
        temp.sum = 0;
        temp.suffsum = 0;
        return temp;
    }
    if(tl<=l && r<=tr){
        return a[curr];
    }
    int mid = (l+r)/2;
    node a = query(2*curr,l,mid,tl,tr);
    node b = query(2*curr+1,mid+1,r,tl,tr);
    return a.join(b);
}
int n,q;
int rem[MAXN];
int len;
int holdans[MAXN];
vector<pair<int,int>> queries[MAXN];
int main(){

    cin>>n;
    string s;
    cin>>s;
 
    cin>>q;
    
    s = '#' + s;
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        queries[l].push_back(make_pair(r,i));
    }
    for(int i=n;i>=1;i--){
        if(s[i] == 'T'){
            rem[len++] = i;
            
        }else{
            update(1,1,n,i,1);
           //cout<<query(1,1,n,i,n).suffsum<<endl;
            if(len){
                update(1,1,n,rem[len-1],-1);
                
                //cout<<rem[len-1]<<endl;
                len--;
            }
        }
        for(auto it:queries[i]){
            //cout<<len<<" "<<it.first<<endl;
            int l=0;
            int r = len-1;
            int ans = -1;
            while(l<=r){
                int mid = (l+r)/2;
               // cout<<rem[mid]<<endl;
                if(rem[mid]>it.first){
                    ans = mid;
                    //cout<<123<<" "<<mid<<" "<<rem[mid]<<" "<<it.first<<endl;
                    l=mid+1;
                }else{
                   
                    //ans = mid;
                    r=mid-1;
                }
            }
            //cout<<len<<" "<<len-ans-1<<endl;
            //cout<<len<<" "<<ans+1<<endl;
          //  cout<<-1*query(1,1,n,i,it.first).suffsum<<endl;
         //cout<<ans+1<<endl;
            holdans[it.second] = max(0,-1*query(1,1,n,i,it.first).suffsum) + len-ans-1;
            
        }
        
    }
    for(int i=1;i<=q;i++){
        cout<<holdans[i]<<endl;
    }
}
