#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int DeleteChartobePalindrome(string s){
    if(s == "" || s.length()<2) return 0;
    int len = s.length();
    int dp[len][len];
    for(int i = 2; i < len; i++){
        for(int j = 0; j < len - i; j++){
            if(s[j] == s[j+i])
                dp[i][j+i] = dp[i-2][j+i-1];
            else
                dp[i][j+i] = min(dp[i-1][j+i-1], dp[i-1][j+i]) + 1;
        }
    }
    return dp[len-1][len-1];
}

int DeleteChartobePalindrome1(string s){
    if(s == "" || s.length()<2) return 0;
    int len = s.length();
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<len-1;i++){
        dp[i][i] = 0;
        if(s[i] == s[i+1])
            dp[i][i+1] = 0;
        else
            dp[i][i+1] = 1;
    }
    dp[len-1][len-1] = 0;
    for(int i = 2; i < len; i++){
        for(int j = i-2; j >= 0; j--){
            if(s[j] == s[i])
                dp[j][i] = dp[j+1][i-1];
            else
                dp[j][i] = min(dp[j+1][i], dp[j][i-1]) + 1;
        }
    }
    return dp[0][len-1];
}

int main(){
    string s = "abeba";
    int res = DeleteChartobePalindrome1(s);
    cout<<res<<endl;
}
