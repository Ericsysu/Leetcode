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

 bool isAnagram(string s, string t) {//leetcode 242
    unordered_map<char,int> mymap1,mymap2;
    for(int i=0;i<s.length();i++){
        if(mymap1.find(s[i])==mymap1.end()) mymap1[s[i]]=1;
        else mymap1[s[i]]++;
    }
    for(int i=0;i<t.length();i++){
        if(mymap2.find(t[i])==mymap2.end()) mymap2[t[i]]=1;
        else mymap2[t[i]]++;
    }
    unordered_map<char,int>::iterator it = mymap1.begin();
    for(it;it!=mymap1.end();it++){
        if(mymap2[it->first]!=it->second || (mymap2.find(it->first)==mymap2.end()) ) return false;
    }
    unordered_map<char,int>::iterator it1 = mymap2.begin();
    for(it1;it1!=mymap2.end();it1++){
        if(mymap1[it1->first]!=it1->second || (mymap1.find(it1->first)==mymap1.end()) ) return false;
    }
    return true;
}

bool isAnagram1(string s, string t){//leetcode 242 better solution
    if(s.length()!=t.length()) return false;
    int n = s.length();
    int counts[26] = {0};
    for(int i=0;i<n;i++){
        counts[s[i]-'a']++;
        counts[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
        if(counts[i]) return false;
    return true;
}
