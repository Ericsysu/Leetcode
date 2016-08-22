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

int maxProfit2(vector<int>& prices){//leetcode 122
    if(prices.size()==0) return 0;
    int profit = 0;
    for(int i=1;i<prices.size();i++){
        int tmp = prices[i]-prices[i-1];
        if(tmp>0) profit+=tmp;
    }
    return profit;
}
