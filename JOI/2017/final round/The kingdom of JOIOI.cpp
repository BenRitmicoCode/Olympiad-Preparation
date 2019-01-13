#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
const int MAXN = 2010;
int grid[2010][2010];
int n,m;
int mx;
int ans;
int mn = 1e9;
void revLin(int n, int m) {
	for (int i = 1; i <= n / 2; ++i) {
		for (int j = 1; j <= m; ++j) {
			swap(grid[i][j], grid[n - i + 1][j]); } } }
 
void revCol(int n, int m) {	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m / 2; ++j) {
			swap(grid[i][j], grid[i][m - j + 1]); } } }
bool find(int mid){
    int temp = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(grid[i][j]<mx-mid){
                temp = max(temp,j);
            }
        }
        for(int j=1;j<=temp;j++){
            if(grid[i][j]>mn+mid){
                return false;
            }
        }
    }
    return true;
}
int check(){
    int l = 0;
    int r = mx-mn;

    while(l<=r){
        int mid = (l+r)/2;
       // cout<<mid<<endl;
        if(find(mid)){
        
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return l;
}
int main() {
    cin>>n>>m;
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
            mx = max(mx,grid[i][j]);
            mn = min(mn,grid[i][j]);
        }
    }
    ans = mx-mn;
    ans = min(check(),ans);
    revLin(n,m);
    ans = min(check(),ans);
    
    revCol(n,m);
 ans = min(check(),ans);
    revLin(n,m);
 ans = min(check(),ans);
    cout<<ans<<endl;
}
