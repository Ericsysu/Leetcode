#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include<stack>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* tmp = head;
        while(head->next){
            if(head->next->val == head->val){
                if(head->next->next) head->next = head->next->next;
                else head->next = NULL;
            } else {
                head = head->next;
            }
        }
        return tmp;
    }
};
