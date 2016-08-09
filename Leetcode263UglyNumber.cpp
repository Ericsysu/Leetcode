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

using namespace std;
using namespace tr1;

class Solution {
public:
    bool isUgly(int num) {
        if(num == 1) return true;
        if(num <= 0) return false;
        bool res = true;
        while(num > 1){
        	if(num % 2 == 0){
        		num /= 2;
        	}else if (num % 3 == 0){
        		num /= 3;
        	}else if(num % 5 == 0){
        		num /= 5;
        	}else {
        		res = false;
        		break;
        	}
        }
        return res;
    }
};