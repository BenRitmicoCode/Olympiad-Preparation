#include <iostream>
#include "gap.h"
using namespace std;
const long long MAXN = 1e6+5;
long long arr[MAXN];
long long findGap(int T,int N){
    if(T == 1){
        long long a = 1;
        long long b = 1e18;
        long long l = 0;
        long long r = N-1;
        long long mn,mx;
        long long total = 0;
        while(total<N){
            MinMax(a, b, &mn, &mx);
            arr[l] = mn;
            arr[r] = mx;
            l++;
            r--;
            total+=2;
            a = mn+1;
            b = mx-1;
        }
        long long diff = 0;
        for(long long i=0;i<N-1;i++){
            diff = max(diff,arr[i+1]-arr[i]);
        }
        return diff;
    }else{
        long long a = 1;
        long long b = 1e18;
        long long mn,mx;
        MinMax(a, b, &mn, &mx);
        arr[0] = mn;
        arr[N-1] = mx;
        long long diff = ((mx-mn-1)/(N-1))+1;
        long long l = mn+1;
        long long r = mn+diff;
        long long ans = 0;
        long long prv = mn;
        for(long long i=0;i<N-1;i++){
            MinMax(l, l+diff-1, &mn, &mx);
            if(mn>=0){
                ans = max(ans,mn-prv);
                prv = mx;
            }
            l+=diff;
            r+=diff;
            
        }
        return max(ans,mx-r);
    }
}
