#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v1(n),v2(n),v3(n),v4(n);
    for(int i=0;i<n;i++){
        cin>>v1[i]>>v2[i]>>v3[i]>>v4[i];
    }
    multiset<int> x1,x2,y1,y2;
    for(int i=0;i<n;i++){
        x1.insert(v1[i]);
        y1.insert(v2[i]);
        x2.insert(v3[i]);
        y2.insert(v4[i]);
        
    }
    for(int i=0;i<n;i++){
        x1.erase(x1.find(v1[i]));
        y1.erase(y1.find(v2[i]));
        x2.erase(x2.find(v3[i]));
        y2.erase(y2.find(v4[i]));
        //std::cout<<*y2.begin()<<" "<<*y1.rbegin();
        if(*x1.rbegin()<=*x2.begin() && *y1.rbegin()<=*y2.begin()){
            std::cout<<*x1.rbegin()<<" "<<*y1.rbegin();
            return 0;
        }
        x1.insert(v1[i]);
        y1.insert(v2[i]);
        x2.insert(v3[i]);
        y2.insert(v4[i]);
        
    }
    
}
