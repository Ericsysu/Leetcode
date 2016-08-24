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

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(right>left){
            int mid = ((long)right + left)/2;
            if(isBadVersion(mid)) right = mid-1;
            else left = mid+1;
        }
        if(!isBadVersion(left)) return left+1;
        else return left;
    }
};

//Before this problem, I have always use
//
//  mid = (start+end)) / 2;
//To get the middle value, but this can caused OVERFLOW !
//
//when start and end are all about INT_MAX , then (start+end) of course will be overflow !
//
//To avoid the problem we can use
//
//  mid =  start+(end-start)/2;
//Here is the AC implementation:
int firstBadVersion(int n) {
        int start=0, end=n;
        while(end-start>1){
            int mid=start+(end-start)/2;
            /** mid = (start+end)) / 2; **/
            if(isBadVersion(mid))  end=mid;
            else  start=mid;
        }
        return end;
    }
