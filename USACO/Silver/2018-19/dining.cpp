#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
const long long MAXN = 100010;
long long arr[MAXN];
long long n,m,c;
bool binsearch(long long x){
    bool last= true;
    //fout<<x<<endl;
    long long buses = 1;
    long long currmin = arr[0]+x;
    long long onthebus = 1;
    for(long long i=1;i<n;i++){
        if(onthebus == 0){
            last= true;
            buses++;
            currmin = arr[i]+x;
            onthebus++;
            continue;
        }
        if(arr[i]<=currmin){
            onthebus++;
        }else{
            onthebus = 1;
            buses++;
            currmin = arr[i]+x;
        }
        if(onthebus == c){
            onthebus = 0;
            
        }
    }

    return buses<=m;
}
int main() {
	ifstream fin("convention.in");
	ofstream fout("convention.out");
	fin>>n>>m>>c;
	
	for(long long i=0;i<n;i++){
	    fin>>arr[i];
	}
	sort(arr,arr+n);
	long long l=0;
	long long r=1000000000;
	long long ans =0 ;
	while(l<=r){
	    long long mid = (l+r)/2;

	    if(binsearch(mid)){
	        r=mid-1;
	        ans = mid;
	       // fout<<ans<<endl;
	    }else{
	        l = mid+1;
	    }
	}
	fout<<ans<<endl;
}
