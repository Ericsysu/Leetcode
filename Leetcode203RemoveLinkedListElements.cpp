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
#include <set>

using namespace std;
using namespace tr1;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* node = prev;
        while(node->next){
            if(node->next->val == val){
                ListNode* next = node->next->next;
                delete node->next;
                node->next = next;
            }else node = node->next;
        }
        return prev->next;
    }
};
