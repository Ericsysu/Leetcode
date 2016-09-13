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

vector<int> twoSum(vector<int>& numbers, int target){//leetcode 167
    int tmp = target,tmp1 = 0,tmp2 = 0;
    bool found = false;
    int maxsize = numbers.size();
    int m = 0;
     for(int i=0; i<numbers.size();i++){
        if(numbers[i]<0){
            if(numbers[i]<m) m = numbers[i];
        }
        else if(numbers[i]>=0){
            tmp-=m;
            break;
        }
    }
    for(int i=0; i<numbers.size();i++){
        if(numbers[i]>tmp){
            cout<<maxsize<<endl;
            maxsize = i;
            break;
        }
    }
    cout<<maxsize<<endl;
    for(int i=0; i<maxsize-1; i++){
        tmp1 = i;
        for(int j=maxsize-1; j>i; j--){
            if(numbers[j]+numbers[i]!=target) continue;
            else{
                tmp2 = j;
                found = true;
                break;
            }
        }
        if(!found) continue;
        else break;
    }
    vector<int> res;
    res.push_back(tmp1+1);
    res.push_back(tmp2+1);
    return res;
}
