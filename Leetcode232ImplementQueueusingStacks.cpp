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

class Queue {
public:
    stack<int> s1, s2;
    void moveStack(stack<int> &a, stack<int> &b){
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
    }
    // Push element x to the back of queue.
    void push(int x) {
        moveStack(s1, s2);
        s1.push(x);
        moveStack(s2, s1);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
    }

    // Get the front element.
    int peek(void) {
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
