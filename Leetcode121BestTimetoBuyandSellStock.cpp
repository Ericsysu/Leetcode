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

int maxProfit1(vector<int>& prices){//leetcode 121
    if(prices.size()==0)
        return 0;
    int small = prices[0];
    int profit = 0;
    int i=0;
    int j=i+1;
    for(i;i<prices.size()-1;i++){
        j=i+1;
        if(prices[i]<small)
            small = prices[i];
        if(prices[j]-small>profit)
            profit = prices[j]-small;
    }
    if(profit<0) return 0;
    return profit;
}
