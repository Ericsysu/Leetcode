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

bool isPalindrome(ListNode* head) {
    vector<int> v;
    while(head){
        v.push_back(head->val);
        head = head->next;
    }
    for(int i = 0;i<v.size()/2;i++){
        if(v[i]!=v[v.size()-i-1]) return false;
    }
    return true;
}

//O(n)time&O(1)space Solution:
ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL;
    ListNode* node=head;
    while(head!=NULL){
        ListNode* next=node->next;
        node->next=prev;
        prev=node;
        node=next;
    }
    return prev;
}

bool isPalindrome(ListNode* head){
    if(!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while(slow){
        if(head->val!=slow->val) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
