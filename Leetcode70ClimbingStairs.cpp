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
    int climbStairs(int n) {//Fibonacci approach
        int cnt = 2;
        int first = 1, second = 2;
        int sum;
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else{
        	while(cnt < n){
        		sum = first + second;
        		first = second;
        		second = sum;
        		cnt++;
        	}
        }
        return sum;
    }
};

class Solution1 {
public:
    int climbStairs(int n) {//DP approach
        int steps[n];
        memset(steps, 0, n);
        steps[0] = 1;
        steps[1] = 2;
        for(int i = 2; i < n; i++){
        	steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n-1];
    }
};