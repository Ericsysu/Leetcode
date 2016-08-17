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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB) return headA;
        ListNode *n1 = headA, *n2 = headB;
        int lena = 0, lenb = 0;
        while(n1){
            n1 = n1->next;
            lena ++;
        }
        while(n2){
            n2 = n2->next;
            lenb ++;
        }
        n1 = headA;
        n2 = headB;
        for(int i=0;i<lena-lenb;i++)
            n1 = n1->next;
        for(int i=0;i<lenb-lena;i++)
            n2 = n2->next;
        while(n1){
            if(n1 == n2) return n1;
            n1 = n1->next;
            n2 = n2->next;
        }
        return NULL;
    }
};
