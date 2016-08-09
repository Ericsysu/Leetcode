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

using namespace std;
using namespace tr1;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1&&!l2) return NULL;
    ListNode newhead(0), *res;
    res = &newhead;
    while(l1 || l2){
        if(!l1){
            res->next = l2;
            break;
        }else if(!l2){
            res->next = l1;
            break;
        }else if(l1->val >= l2->val){
            res->next = l2;
            l2 = l2->next;
        }else{
            res->next = l1;
            l1 = l1->next;
        }
        res = res->next;
    }
    return newhead.next;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode newHead(0), *res;
        res = &newHead;
        while(l1 && l2){
        	if(l1->val >= l2->val){
        		res->next = l2;
        		l2 = l2->next;
        	}else{
        		res->next = l1;
        		l1 = l1->next;
        	}
        	res = res->next;
        }
        while(l1){
        	res->next = l1;
        	l1 = l1->next;
        	res = res->next;
        }
        while(l2){
        	res->next = l2;
        	l2 = l2->next;
        	res = res->next;
        }
        return newHead.next;
    }
};

int main(){
    ListNode* l1 = new ListNode(3);
    ListNode* l2 = new ListNode(2);
    if(l1->next) cout<<"con"<<endl;
    ListNode* res = mergeTwoLists(l1, l2);
    while(res){
        cout<<res->val<<endl;
        res = res->next;
    }
}
