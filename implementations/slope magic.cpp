#include <iostream>
#include <queue>

using namespace std;
long long ans;
priority_queue<long long> pq;
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x;
        cin>>x;
        x-=i;
        pq.push(x);
        if(pq.top()>x){
            ans+=pq.top()-x;
            pq.pop();
            pq.push(x);
        }
    }
    cout<<ans<<endl;
}
