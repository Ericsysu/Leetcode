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

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        int cnt = 1;
        bool* isprime = new bool[n];
        for(int i=0;i<n;i++){
            isprime[i] = true;
        }
        for(int i=3; i*i<=n; i+=2){
            if(isprime[i]){
                for(int j=i*i; j<n; j+=2*i)
                    isprime[j] = false;
            }
        }
        for(int i=3; i<n; i+=2){
            if(isprime[i]) cnt++;
        }
        delete isprime;
        return cnt;
    }
};
