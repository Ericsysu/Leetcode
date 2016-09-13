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
#include <cctype>
#include <ctime>

using namespace std;
using namespace tr1;

class Solution {
private:
    vector<int> backup;
public:
    Solution(vector<int> nums) {
        backup = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return backup;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(backup);
        for(int i=0;i<res.size();i++){
            int pos = rand()%(res.size()-i);
            swap(res[i+pos], res[i]);
        }
        return res;
    }
};
