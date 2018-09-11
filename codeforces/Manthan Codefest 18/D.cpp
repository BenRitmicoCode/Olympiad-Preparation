#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int realorder[200007];
bool comp(int a,int b){
    return realorder[a]<realorder[b];
}
int main() {
	int n;
	cin>>n;
	vector<int> arr[n+1];
	int order[n+1];
	bool visited[n+1]={false};
	int level[n+1];
	queue<int> q1;
	for(int i=0;i<n-1;i++){
	    level[i] = 0;
	    visited[i] = false;
	    int a,b;
	    cin>>a>>b;
	    
	    arr[a].push_back(b);
	    arr[b].push_back(a);
	}
	for(int i=0;i<n;i++){
	    cin>>order[i];
	    realorder[order[i]] = i;
	}
	
	
	
	for(int i=0;i<=n;i++){
	    sort(arr[i].begin(),arr[i].end(),comp);
	}
	level[n-1] = 0;
	visited[n-1] = false;
	vector<int> v1;
	v1.push_back(1);
	level[1] = 1;
	visited[1] = true;
	q1.push(1);
	while(!q1.empty()){
	    int f = q1.front();
	    q1.pop();
	    
	    for (auto i = arr[f].begin(); i != arr[f].end(); i++) {
	        if(visited[*i] == false){
	            q1.push(*i);
	            visited[*i] = true;
                v1.push_back(*i);
	           
	        }
	    }
	}
	
	
	for(int i=0;i<n;i++){
	   //  std::cout<<i<<" "<<level[i]<<" ";
	    if(order[i] != v1[i]){
	        std::cout<<"No";
	        return 0;
	    }
	}
	std::cout<<"Yes";
}
