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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> v;
        ListNode* res = head;
        while(head){
            v.push_back(head);
            head = head->next;
        }
        if(v.size() == n) return res->next;
        ListNode* node = v[v.size()-n-1];
        if(node->next) node->next = node->next->next;
        else node->next = NULL;
        return res;
    }
};
