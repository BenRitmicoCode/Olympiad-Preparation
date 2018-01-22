#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("partyin.txt");
    ofstream fout("partyout.txt");
//61 points
	int n,m,a,b;
	fin>>n>>m>>a>>b;
	b= n-b-1;
	vector<int> arr[n+1];
	int size[n+1];
	for(int i=0;i<=n;i++){
	    size[i] = 0;
	}
	for(int i=0;i<m;i++){
	    int x,y;
	    fin>>x>>y;
	    arr[y].push_back(x);
	    arr[x].push_back(y);
	    size[y]++;
	    size[x]++;
	}

	int invited = n;
	bool visited[n+1] = {false};
	for(int k=0;k<n;k++){
	    for(int i=1;i<=n;i++){
	    //std::cout<<i<<" "<<size[i]<<endl;
	    if((size[i]<a || size[i]>b) && visited[i] == false){
	        visited[i] = true;
	        b--;
	        invited--;
	        for(int j=0;j<size[i];j++){
	            
	            size[arr[i][j]]--;
	        }
	    }
	    
	}
	}
	fout<<invited<<endl;
}
