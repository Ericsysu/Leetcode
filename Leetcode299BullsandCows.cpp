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
    string getHint(string secret, string guess) {
        map<char, int> mymap;
        string res;
        int bulls = 0, cows = 0;
        for(int i=0;i<secret.size();i++){
            if(mymap.find(secret[i]) == mymap.end()) mymap[secret[i]] = 1;
            else mymap[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i] == guess[i]){
                bulls++;
                mymap[secret[i]]--;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i] != guess[i] && mymap.find(guess[i]) != mymap.end()){
                if(mymap[guess[i]] > 0){
                    mymap[guess[i]]--;
                    cows++;
                }
            }
        }
        res += to_string(bulls);
        res += 'A';
        res += to_string(cows);
        res += 'B';
        return res;
    }
};
