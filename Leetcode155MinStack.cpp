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
#include <stack>

using namespace std;
using namespace tr1;

class MinStack {//Brilliant Idea!
public:
    stack<pair<int, int> > st;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(st.empty()) st.push(make_pair(x,x));
        else st.push(make_pair(x, min(x,st.top().second)));
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

//Other ways(Using another stack to store min value)
class MinStack1{
private:
    stack<int> data;
    stack<int> mindata;
public:
    MinStack1(){}

    void push(int x){
        data.push(x);
        if(mindata.empty())
            mindata.push(x);
        else mindata.push(min(x,mindata.top()));
    }

    void pop(){
        if(!data.empty()){
            data.pop();
            mindata.pop();
        }
    }

    int top(){
        return data.top();
    }

    int getMin(){
        return mindata.top();
    }
};

int main(){
    return 0;
}
