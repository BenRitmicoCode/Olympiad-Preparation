#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 1e5+5;
int arr[MAXN];
int temp[MAXN];
  int n;
bool check(int x){
    
    for(int i=0;i<=n;i++){
        temp[i] = 0;
    }
    for(int i=0;i<=x;i++){
        temp[arr[i]]++;
    }
    for(int i=n-1;i>=0;i--){
        if(i+temp[i]>=n){
            
            return false;
        }
        if(i){
            temp[i-1]+=temp[i];
        }
    }
    
    return true;
}
int main(){
   ifstream fin("greedy.in");
   ofstream fout("greedy.out");
    fin>>n;
    for(int i=0;i<n;i++){
        fin>>arr[i];
    }
    int l = 0;
    int r = n;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    fout<<n-ans-2<<endl;
}
