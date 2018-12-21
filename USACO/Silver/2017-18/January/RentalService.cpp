#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
long long prerent[100100];
long long precows[100100];
long long precost[100100];
set<pair<pair<long long,long long>,long long>> s1;
int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");
	long long n,m,r;
	fin>>n>>m>>r;
	vector<long long> cows;
	vector<pair<long long,long long>> milk;
	vector<long long> rent;
	for(long long i=0;i<n;i++){
	    long long x;
	    fin>>x;
	    cows.push_back(x);
	}
	for(long long i=0;i<m;i++){
	    long long x,y;
	    fin>>x>>y;
	    milk.push_back(make_pair(y,x));
	}
	for(long long i=0;i<r;i++){
	    long long x;
	    fin>>x;
	    rent.push_back(x);
	}
	sort(cows.begin(),cows.end());
	sort(milk.begin(),milk.end());
	sort(rent.begin(),rent.end());
	reverse(milk.begin(),milk.end());
	long long ans = 0;
	prerent[0] = rent[0];
	for(long long i=1;i<r;i++){
	    prerent[i] = prerent[i-1] + rent[i];
	}
	long long litersused = 0;
	long long price = 0;
	for(long long i=0;i<m;i++){
	    litersused+=milk[i].second;
	    price+=(milk[i].first*milk[i].second);
	    s1.insert(make_pair(make_pair(litersused,price),i));
	   // fout<<litersused<<" "<<price<<endl;
	}
    precows[0] = cows[0];
	for(long long i=1;i<n;i++){
	    precows[i] = precows[i-1]+cows[i];
	}
	long long milkleft = precows[n-1];
	long long j = 0;
	    while(milkleft>0 && j<m){
	        ans+=(milk[j].first*milk[j].second);
	        milkleft -= (milk[j].second);
	        if(milkleft<0){
	            ans-=(-(milkleft) * milk[j].first);
	        }
	        j++;
	    }
	 //  fout<<ans<<endl;
	for(long long i=r-1;i>=0;i--){
	    if(r-i>n){
	        continue;
	    }
	    long long currcost = prerent[r-1] - prerent[i-1];
	    
	    long long milkleft = precows[n-1]-precows[r-1-i];
	 //   fout<<"left: "<<precows[n-1]<<endl;
	    if(milkleft<0){
	        continue;
	    }
	   // fout<<currcost<<endl;
	   // fout<<milkleft<<endl;
	    auto it = s1.lower_bound(make_pair(make_pair(milkleft,0),0));
	     if(it ==s1.end()){
	       it--;
	   }
        auto holding = *it;
        
        long long holdings = holding.first.first;
        long long holdings2 = holding.first.second;
        long long holdings3 = holding.second;
        //fout<<holdings<<" "<<holdings2<<" "<<holdings3<<endl;
        milkleft-=holdings;
	    currcost+=(holdings2);
	    if(milkleft<0){
	        currcost-=((-milkleft)*milk[holdings3].first);
	    }
	    
	  //  fout<<currcost<<endl;
	    ans = max(ans,currcost);
	    
	}
	fout<<ans<<endl;
	
}
