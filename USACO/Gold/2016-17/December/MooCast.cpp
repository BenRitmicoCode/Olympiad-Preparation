#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> cows;
vector<pair<int,pair<int,int>>> points;
int par[1010];
int n;
int dist(int i,int j){
    return ((cows[j].second-cows[i].second)*(cows[j].second-cows[i].second)) + ((cows[j].first-cows[i].first)*(cows[j].first-cows[i].first));
}
int findpar(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = findpar(par[x]);
    }
}
void unite(int a,int b){
    int first = findpar(a);
    int second = findpar(b);
   // fout<<first<<" "<<second<<endl;
    if(first==second){
        return;
    }
    if(first>second){
        swap(first,second);
    }
    par[second] = first;
    n--;
}
int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
	fin>>n;
	for(int i=0;i<n;i++){
	    int x,y;
	    fin>>x>>y;
	    cows.push_back(make_pair(x,y));
	    par[i] = i;
	}
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        points.push_back(make_pair(dist(i,j),make_pair(i,j)));
	    }
	}
	sort(points.begin(),points.end());
	for(int i=0;i<points.size();i++){
	   // fout<<points[i].first<<" "<<points[i].second.first<<" "<<points[i].second.second<<endl;
	    unite(points[i].second.first,points[i].second.second);
	 //   fout<<"parents "<<findpar(points[i].second.first)<<" "<<findpar(points[i].second.second)<<endl;
	    if(n==1){
	        fout<<points[i].first<<endl;
	        return 0;
	    }
	}
}
