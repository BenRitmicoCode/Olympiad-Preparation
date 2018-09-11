#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int arr[m+1];
	int freq[110];
	int types = 0;
	for(int i=0;i<101;i++){
	    freq[i] = 0;
	}
	for(int i=0;i<m;i++){
	    cin>>arr[i];
	    if(freq[arr[i]] == 0){
	        types++;
	    }
	    freq[arr[i]]++;
	}
	vector<int> v1;
    for(int i=0;i<101;i++){
	    if(freq[i]>0){
	        v1.push_back(freq[i]);
	    }
	}
	sort(v1.begin(),v1.end());
	int ans = 0;

	
	int arr2[types+1];
	int pointer = v1.size()-1;
	for(int i=1;i<=100;i++){
	    int left = n;
	    for(int j=v1.size()-1;j>=0;j--){
	        left-=v1[j]/i;
	        if(left<=0){
	            ans = i;
	            break;
	        }
	    }
	}

	std::cout<<ans<<endl;
	
}
