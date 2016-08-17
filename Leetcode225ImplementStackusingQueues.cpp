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

class Stack {
public:
    queue<int> q1, q2;
    void movequeue(queue<int> &s, queue<int> &q){
        while(!s.empty()){
            q.push(s.front());
            s.pop();
        }
    }
    // Push element x onto stack.
    void push(int x) {
        movequeue(q1, q2);
        q1.push(x);
        movequeue(q2, q1);
    }

    // Removes the element on top of the stack.
    void pop() {
        q1.pop();
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
