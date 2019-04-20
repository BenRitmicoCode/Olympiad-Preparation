#include <iostream>
#include <map>
#include "cave.h"
using namespace std;
const int MAXN = 5010;
int m1[MAXN];
int s[MAXN];
int curr;
bool check(int l,int r){
    for(int i=l;i<=r;i++){
        if(m1[i]){
            continue;
        }
        s[i] = 1-s[i];
    }
    int hold = tryCombination(s);
    for(int i=l;i<=r;i++){
        if(m1[i]){
            continue;
        }
        s[i] = 1-s[i];
    }
    if(hold>curr||hold==-1){
        return true;
    }
    return false;
}
void exploreCave(int N){
    
    int d[N+1];

    for(int i=0;i<N;i++){
        curr = i;
        int hold = tryCombination(s);
        if(hold>i||hold == -1){
            for(int j=0;j<N;j++){
                if(m1[j]){
                    continue;
                }
                s[j] = 1-s[j];
            }
        }
        int l = 0;
        int r = N-1;
        int ans = N-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(check(l,mid)){
                ans = mid;
                r=mid-1;
            }else{
                l = mid+1;
            }
        }
        d[ans] = i;
        m1[ans]++;
        s[ans] = 1-s[ans];
    }
    answer(s,d);
}
