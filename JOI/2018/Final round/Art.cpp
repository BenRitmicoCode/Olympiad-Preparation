#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const long long N = 200010;

vector<pair<long long,long long>> v1;

int main() {
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    sort(v1.begin(),v1.end());
    long long tempmin = -1*v1[0].first;
    long long tempmax = v1[0].second-tempmin-v1[0].first;
    
    for(long long i=1;i<n;i++){
        v1[i].second+=v1[i-1].second;
        tempmin = min(tempmin, v1[i-1].second-v1[i].first);
        tempmax = max(tempmax,v1[i].second-v1[i].first -tempmin);
    }
    cout<<tempmax<<endl;
}
