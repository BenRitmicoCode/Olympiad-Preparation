#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 100101;
priority_queue<int> q1;
int timer[MAXN];


int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    cin>>timer[i];
	    if(i>1){
	        q1.push(-1*(timer[i]-timer[i-1]-1));
	    }
	}
	int x = n;
	while(!q1.empty() && q1.size()>=k){
	   
	    x+=(-1*q1.top());
	    
	    q1.pop();
	}
	cout<<x<<endl;
}
