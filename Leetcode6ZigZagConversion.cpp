#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <tr1/unordered_map>
#include <stack>

using namespace std;
using namespace tr1;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows>s.size()) return s;
        string res = "";
        int gap1 = 2*numRows-2;
        for(int i=0;i<numRows;i++){
            if(i == 0 || i==numRows-1){
                int tmp = i;
                while(tmp<s.size()){
                    res+=s[tmp];
                    tmp+=gap1;
                }
            }else{
                int gap2 = 2*(numRows - i - 1);
                int gap3 = 2*i;
                int tmp = i, cnt = 0;
                while(tmp<s.size()){
                    res+=s[tmp];
                    if(cnt%2==0) tmp+=gap2;
                    else tmp+=gap3;
                    cnt++;
                }
            }
        }
        return res;
    }
};
