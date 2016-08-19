#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <stack>
#include <deque>
#include <queue>

using namespace std;
using namespace tr1;

string addBinary(string a, string b) {
    if(a=="" || b=="") return (a=="")?b:a;
    string longer = a.size()>b.size()?a:b;
    string shorter = a.size()>b.size()?b:a;
    string tmp = "",res = "";
    for(int i=0; i<longer.size()-shorter.size(); i++){
        tmp+="0";
    }
    shorter = tmp+shorter;
    bool flag = 0;
    for(int i = shorter.size()-1; i>=0; i--){
        if(longer[i]=='1' && shorter[i]=='1'){
            if(flag) res = "1"+res;
            else {
                res="0"+res;
                flag = 1;
            }
        }else if(longer[i]=='0' && shorter[i]=='0'){
            if(flag){
                res="1"+res;
                flag = 0;
            }else res="0"+res;
        }else{
            if(flag) res="0"+res;
            else res="1"+res;
        }
    }
    if(flag) res = "1"+res;
    return res;
}
//tips: Reverse both string will be a lot easier
