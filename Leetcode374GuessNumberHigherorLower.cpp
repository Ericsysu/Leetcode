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

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;
        long long res = 0;
        while(left<=right){
            res = (left+right)/2;
            if(guess(res) == -1) right = res-1;
            else if(guess(res) == 1) left = res+1;
            else break;
        }
        return (int)res;
    }
};
