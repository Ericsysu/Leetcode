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
#include <deque>

using namespace std;
using namespace tr1;

void swap(string &s, int n1, int n2){
    char tmp = ' ';
    tmp = s[n1];
    s[n1] = s[n2];
    s[n2] = tmp;
}
string reverseVowels(string s) {
    string vowels = "aeiouAEIOU";
    deque<int> q;
    for(int i=0; i<s.size(); i++){
        if(vowels.find(s[i])!=string::npos){
            q.push_front(i);
        }
    }
    deque<int>::iterator it = q.begin();
    for(it; it!=q.end(); it++){
        int n1 = -1, n2 = -1;
        if(!q.empty()) {
            n1 = q.front();
            q.pop_front();
        }
        if(!q.empty()) {
            n2 = q.back();
            q.pop_back();
        }
        if(n1!=-1 && n2!=-1) swap(s, n1, n2);
    }
    return s;
}
