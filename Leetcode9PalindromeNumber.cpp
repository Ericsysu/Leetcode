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
#include <tr1/unordered_set>
#include <stack>
#include <deque>
#include <queue>

using namespace std;
using namespace tr1;

class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        stringstream ss;
        ss<<x;
        s = ss.str();
        for(int i = 0, j = s.size()-1; i!=s.size()/2; i++, j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
};

bool isPalindrome(int x){
    int n = 0;
    while(x>0){
        n = x % 10 + n * 10;
        x /= 10;
    }
    return n == x;
}
