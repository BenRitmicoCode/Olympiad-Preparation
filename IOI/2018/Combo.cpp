#include <iostream>
#include <vector>
#include "combo.h"
using namespace std;
string guess_sequence(int n){
    string s;
    s = "AB";
    if(press(s)){
        if(press("A")){
            s = "A";
        }else{
            s = "B";
        }
    }else{
        if(press("X")){
            s = "X";
        }else{
            s = "Y";
        }
    }
    vector<string> choices;
    if(s!="X"){
        choices.push_back("X");
    }
    if(s!="Y"){
        choices.push_back("Y");
    }
    if(s!="A"){
        choices.push_back("A");
    }
    if(s!="B"){
        choices.push_back("B");
    }
    while(s.length()<n){
        if(s.length() == n-1){
            if(press(s+choices[0]) == n){
                s+=choices[0];
                break;
            }else if(press(s+choices[1]) == n){
                s+=choices[1];
                break;
            }else{
                s+=choices[2];
                break;
            }
        }
        string q;
        q+= (s+choices[0]+choices[0]);
        q+= (s+choices[0]+choices[1]);
        q+=(s+choices[1]+choices[0]);
        int pressed = press(q);
        if(pressed == s.length()+2){
            string p = s+choices[0]+choices[0];
            int hold = press(p);
            if(hold == s.length()+2){
                s+=choices[0]+choices[0];
                continue;
            }else if(hold == s.length()+1){
                s+=choices[0]+choices[1];
                continue;
            }else{
                s+=choices[1]+choices[0];
                continue;
            }
        }else if(pressed == s.length() + 1){
            string p = s+choices[1]+choices[1];
            int hold = press(p);
            if(hold == s.length() + 2){
                s+=choices[1]+choices[1];
                continue;
            }else if(hold == s.length() + 1){
                s+=choices[1]+choices[2];
                continue;
            }else{
                s+=choices[0]+choices[2];
            }
        }else{
            s+=choices[2];
        }
    }
    return s;
    
}
