#include <iostream>
#include <vector>
using namespace std;
vector<pair<long long,long long>> v1;
long long n,m;

long long keepmin = 1e18;
bool check(long long x){
    long long start = v1[0].second;
    long long subtracted = 0;
    keepmin = min(keepmin,v1[0].second-v1[0].first);
    for(long long i=1;i<n;i++){
        if(start+x<v1[i].first){
            start = v1[i].first;
           
            keepmin = min(keepmin,v1[i].first-v1[i].first);
        }else if(start+x>=v1[i].first && start+x<=v1[i].second){
            start = start+x;
           
            keepmin = min(keepmin,start-v1[i].first);
        }else{
            long long tosubtract = start+x-v1[i].second;
            subtracted+=tosubtract;
            start = v1[i].second;
           
            if(keepmin-tosubtract<0){
                if(x==3){
                  //  std::cout<<keepmin<<" "<<i<<" "<<start<<endl;
                }
                return false;
            }else{
                keepmin-=tosubtract;
            }
            keepmin = min(keepmin,v1[i].second-v1[i].first);
        }
        
    }
    
    start+=x;
    if(start<m){
        return true;
    }
    start%=m;
    if(x==86){
     //   std::cout<<subtracted<<endl;
    }
    //start = 82
    //subtracted = 4
    //v1[0].second = 50
    //tosubtract = 38
    //keepmin = 33
    if(start>v1[0].second-subtracted){
        subtracted+=start-(v1[0].second-subtracted);
      
        start-=subtracted;
        if(start<v1[0].first){
            return false;
        }
    }
    long long tempstart= start;
    keepmin = min(keepmin,start-v1[0].first);
    for(long long i=1;i<n;i++){
        if(start+x<v1[i].first){
            start = v1[i].first;
           
            keepmin = min(keepmin,v1[i].first-v1[i].first);
        }else if(start+x>=v1[i].first && start+x<=v1[i].second){
            start = start+x;
           
            keepmin = min(keepmin,start-v1[i].first);
        }else{
            long long tosubtract = start+x-v1[i].second;
            subtracted+=tosubtract;
            start = v1[i].second;
           
            if(keepmin-tosubtract<0){
                if(x==3){
                  //  std::cout<<keepmin<<" "<<i<<" "<<start<<endl;
                }
                return false;
            }else{
                keepmin-=tosubtract;
            }
            keepmin = min(keepmin,v1[i].second-v1[i].first);
        }
        
    }
    start+=x;
    if(start<m){
        return true;
    }
    start%=m;
    if(start>tempstart){
        return false;
    }
    return true;
    
}
int main() {
    
    cin>>m>>n;
    for(long long i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    long long l = 1;
    long long r = 1e18;
    long long ans = 1;
    while(l<r){
        long long mid = (l+r+1)/2;
        keepmin = 1e18;
        if(check(mid)){
            l = mid;
            ans = mid;
        }else{
            r = mid-1;
        }
    }
    std::cout<<ans<<endl;
    
}
