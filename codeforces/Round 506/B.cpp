#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long arr[n+1];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	long long ans = 1;
	long long temp = 1;
	for(int i=1;i<n;i++){
	    if((2*arr[i-1])>=arr[i]){
	        temp++;
	        ans = max(ans,temp);
	    }else{
	        temp = 1;
	    }
	}
	std::cout<<ans<<endl;
}
