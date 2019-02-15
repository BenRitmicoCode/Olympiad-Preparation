#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
const long long MAXN = 200100;
const long long MOD = 1e9 + 7;
vector<long long> v1[MAXN];
 
long long fenwick[MAXN + 2];
long long arr[MAXN];
long long h[MAXN];
long long n;
void update(long long pos, long long val){
    for(; pos <= n; pos += (pos & (-pos))){
        fenwick[pos] = max(val,fenwick[pos]);
    }
}
long long query(long long pos){
    long long ans = 0;
    for(; pos; pos -= (pos & (-pos))){
        ans = max(ans,fenwick[pos]);
    }
    return ans;
}
long long ans;
int main() {
  
   cin>>n;
   for(long long i=0;i<n;i++){
       cin>>arr[i];
   }
   for(long long i=0;i<n;i++){
       cin>>h[i];
   }
   for(long long i=0;i<n;i++){
       long long temp = query(arr[i])+h[i];
       ans = max(ans,temp);
       update(arr[i],temp);
   }
   cout<<ans<<endl;
}
