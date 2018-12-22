#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
vector<pair<long long,long long>> v1;
int main() {
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
	long long l,n,f,b;
	fin>>l>>n>>f>>b;
	for(long long i=0;i<n;i++){
	    long long x,y;
	    fin>>x>>y;
	    v1.push_back(make_pair(y,x));
	}
	sort(v1.begin(),v1.end());
	reverse(v1.begin(),v1.end());
	long long farmer = 0;
	long long bessie = 0;
	long long last = 0;
	long long ans = 0;
	for(long long i=0;i<n;i++){
	    long long arrive = v1[i].second;
	    long long taste = v1[i].first;
	   
	    if(arrive<last){
	        continue;
	    }
	    farmer = (arrive-last)*f;
	    bessie=(arrive-last)*b;
	     //fout<<arrive-last<<" "<<bessie<<endl;
	    last = arrive;
	    long long timer = farmer-bessie;
	   
	    if(timer>0){
	        ans+=(timer*taste);
	    }
	}
	fout<<ans<<endl;
}
