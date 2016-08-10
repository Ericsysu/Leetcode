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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode newHead(0), *res;
        res = &newHead;
        res->next = head;
        ListNode* prev = res;
        while(head && head->next){
            ListNode* tmp = head->next->next;
            prev->next = head->next;
            head->next->next = head;
            head->next = tmp;
            prev = head;
            head = tmp;
        }
        return newHead.next;
    }
};
