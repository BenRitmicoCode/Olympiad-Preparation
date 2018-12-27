#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
int n,m;
const int MAXN = 100010;
vector< pair<int,int > > arr[MAXN];
vector<int> successor[MAXN];
int predecessor[MAXN];
int ans[MAXN];
bool check(int x){
    for(int i=0;i<=n;i++){
        successor[i].clear();
        predecessor[i] = 0;
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<arr[i].size();j++){
            pair<int,int> y= arr[i][j];
            successor[y.first].push_back(y.second);
            predecessor[y.second]++;
        }
    }
    priority_queue<int> q1;
    for(int i=1;i<=n;i++){
        if(predecessor[i] == 0){
            q1.push(-i);
        }
    }
    for(int i=0;i<n;i++){
        if(q1.empty()){
            return false;
        }
        ans[i] = -q1.top();
        q1.pop();
        for(int y:successor[ans[i]]){
            predecessor[y]--;
            if(predecessor[y] == 0){
                q1.push(-y);
            }
        }
    }
    return true;

}
int main(){
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    fin>>n>>m;
    for(int i=0;i<m;i++){
        int x;
        fin>>x;
        int last;
        for(int j=0;j<x;j++){
            if(j == 0){
                int y;
                fin>>y;
                last = y;
                continue;
            }
            int y;
            fin>>y;
            arr[i].push_back(make_pair(last,y));
            last= y;
        }
    }
    int l=0;
    int r = n-1;
    int tempans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            tempans = mid;
            l = mid+1;
        }else{
            r= mid-1;
        }
    }
    check(tempans);
    for(int i=0;i<n;i++){
        fout<<ans[i];
        if(i!=n-1){
            fout<<" ";
        }
    }
}
