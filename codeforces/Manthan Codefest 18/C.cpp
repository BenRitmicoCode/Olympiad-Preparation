#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int ans = 0;
	for(int i=0;i<n-1;i++){
	    
	    if(a[i] == b[i+1] && a[i+1] == b[i] && a[i]!=a[i+1]){
	        ans++;
	        a[i] = b[i];
	        a[i+1] = b[i+1];
	    }
	}
	for(int i=0;i<n;i++){
	   if(a[i] != b[i]){
	       ans++;
	   }
	}
	std::cout<<ans<<endl;
}
