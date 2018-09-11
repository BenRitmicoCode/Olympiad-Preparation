#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	int arr[27];
	for(int i=0;i<27;i++){
	    arr[i] = 0;
	}
	for(int i=0;i<n;i++){
	    char x;
	    cin>>x;
	    arr[int(x)-96]++;
	}
	int ans = 0;
	bool breaking = false;
	for(int i=1;i<=26;i++){
	   if(breaking == false){
    	   if(arr[i]>0){
    	       ans+=i;
    	       //std::cout<<ans<<endl;
    	       breaking = true;
    	       k--;
    	       if(k==0){
    	           break;
    	       }
    	   }
	   }else{
	       breaking = false;
	   }
	}
	if(k == 0){
	    std::cout<<ans<<endl;
	}else{
	    std::cout<<-1<<endl;
	}
}
