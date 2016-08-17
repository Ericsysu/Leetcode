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

class Solution {
public:
    int getdup(int low1, int high1, int low2, int high2){
        if(low2>high1 || low1>high2) return 0;
        return min(high1,high2) - max(low1, low2);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return abs(C-A)*abs(D-B)+abs(G-E)*abs(H-F)-getdup(A,C,E,G)*getdup(B,D,F,H);
    }
};
