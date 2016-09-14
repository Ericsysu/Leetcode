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
#include <unordered_map>
#include <stack>
#include <cctype>
#include <ctime>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool help(string a, string b){
        unordered_set<char> myset;
        for(int i=0;i<a.size();i++){
            myset.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            if(myset.find(b[i]) != myset.end()) return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        sort(words.begin(), words.end(), [](const string a, const string b){return a.length() > b.length();});
        int l1 = 0, l2 = 0, res = 0;
        for(int i = 0; i<words.size()-1; i++){
            l1 = words[i].length();
            for(int j = i+1; j<words.size(); j++){
                l2 = words[j].length();
                if(l1 * l2 <= res)
                    continue;
                if(help(words[i], words[j]) && (l1 * l2 > res))
                    res = l1 * l2;
            }
        }
        return res;
    }
};

int maxProduct(vector<string>& words){
    unordered_map<int, int> maxlen;
    int res = 0;
    for(string word : words){
        int mask = 0;
        for(char c : word)
            mask |= 1 << (c - 'a');
        maxlen[mask] = max(maxlen[mask], (int)word.size());
        for(auto maskAndlen : maxlen){
            if(!(mask & maskAndlen.first))
                res = max(res, (int)word.size() * maskAndlen.second);
        }
    }
    return res;
}

int maxProduct1(vector<string>& words){
    vector<int> mask(words.size());
    int res = 0;
    for(int i = 0; i<words.size(); i++){
        for(char c : words[i])
            mask[i] |= 1 << (c - 'a');
        for(int j=0; j<i; j++){
            if(!(mask[i] & mask[j]))
                res = max(res, int(words[i].size()*words[j].size()));
        }
    }
    return res;
}
