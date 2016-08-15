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
#include <queue>
#include <set>

using namespace std;
using namespace tr1;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(int i = 0;i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) != s.end()) return false;
                    else s.insert(board[i][j]);
                }
            }
            s.clear();
        }
        for(int i = 0;i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(s.find(board[j][i]) != s.end()) return false;
                    else s.insert(board[j][i]);
                }
            }
            s.clear();
        }
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                for(int m=0; m<3; m++){
                    for(int n=0; n<3; n++){
                        if(board[i+m][j+n] != '.'){
                            if(s.find(board[i+m][j+n])!=s.end()) return false;
                            else s.insert(board[i+m][j+n]);
                        }
                    }
                }
                s.clear();
            }
        }
        return true;
    }
};
