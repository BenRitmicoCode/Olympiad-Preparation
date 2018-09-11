#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long n,s;
	long long arr[n+1];
	cin>>n>>s;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	bool start = false;
	long long storesum = 0;
	long long storeind = 0;
	for(int i=0;i<n;i++){
	 
	    if(arr[i]>=s){
	        storeind = i;
	      
	    }
	    if(storeind == i && arr[i]>=s){
	        break;
	    }
	    if(i == (((n+1)/2)-1)){
	        start = true;
	    }
	    if(start == true && arr[i]<s){
	        storesum+=abs(arr[i]-s);
	    }
	}
	if(storesum == 0){
	    bool begin = false;
	    for(int i=storeind;i<(n+1)/2;i++){
	        storesum+=abs(arr[i]-s);
	    }
	}
	std::cout<<storesum<<endl;
}
