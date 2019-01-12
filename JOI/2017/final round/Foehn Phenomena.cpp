#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
const long long MAXN = 200100;
long long arr[MAXN];
long long n,q,s1,s2;
long long diff[MAXN];
long long get(long long x){
    if(x<0){
        return -s2*x;
    }else{
        return -s1*x;
    }
}
int main() {
    
    cin>>n>>q>>s1>>s2;
    for(long long i=0;i<=n;i++){
        cin>>arr[i];
    }
    long long ans = 0;
    for(long long i=0;i<n;i++){
        diff[i] = arr[i+1]-arr[i];
        ans+=get(diff[i]);
    }
  //  cout<<ans<<endl;
    while(q--){
        long long l,r,x;
        cin>>l>>r>>x;
        ans-=get(diff[l-1]);
        diff[l-1]+=x;
        ans+=get(diff[l-1]);
        if(r!=n){
            ans-=get(diff[r]);
            diff[r]-=x;
            ans+=get(diff[r]);
        }
        cout<<ans<<endl;
    }
    
}
