#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Description <=============================================

Question: 155. Min Stack
Topic : Design Question, Stack
Problems : https://leetcode.com/problems/min-stack/

==============================> Explanation <=============================================
Design Question:

Solution is Based on Cracking the Coding Interview.

1) Brute Force:
- Using single variable keep track of minValue. But when the minValue element is popped that time 
we have to visit all the stack and again find the next minValue. Which is costly and not O(1).

Valid Solution:

- We can keep track of minValue at every step so every time we call minValue() we can directly
return top of stack minValue.

1) Create a minStack using Node Structure.

2) Use Two stack.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(1)

*/


class Node {

public:
    
    int minValue, value;
    Node* next;

    Node(int val, int minVal, Node* nxt) {
        value = val;
        minValue = minVal;
        next = nxt;
    }
};


// Design Question, Create Node in which we keep track of MinValue at every Step.
class MinStack {

public:

    Node* top_;

    MinStack() {
        top_ = nullptr;  
    }
    
    void push(int val) {
       int curMin = getMin();
       Node* nwNode = new Node(val, min(val, curMin), top_);
       top_ = nwNode;
    }
    
    void pop() {
        if(top_ != nullptr)
            top_ = top_->next;
    }
    
    int top() {
        if(top_ == nullptr)
            return INT_MAX;
        return top_->value;
    }
    
    int getMin() {
        if(top_ == nullptr)
            return INT_MAX;
        return top_->minValue;
    }
};





// Using Two STL stack to keep track of element and minValue.
class MinStack {

public:

    stack<int> st;
    stack<int> minValueSt;

    MinStack() {
 
    }
    
    void push(int val) {
        int minValue = getMin();
        if(val <= minValue)
            minValueSt.push(val);
        st.push(val);

    }
    
    void pop() {
        int minValue = getMin();
        if(st.top() == minValue)
            minValueSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(minValueSt.empty())
            return INT_MAX;
        return minValueSt.top();
    }
};





// Using Two Vector as stack to keep track of element and minValue.
class MinStack {

public:

    vector<int> st;
    vector<int> minValueSt;

    MinStack() {
 
    }
    
    void push(int val) {
        int minValue = getMin();
        if(val <= minValue)
            minValueSt.push_back(val);
        st.push_back(val);

    }
    
    void pop() {
        int minValue = getMin();
        if(st.back() == minValue)
            minValueSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        if(minValueSt.empty())
            return INT_MAX;
        return minValueSt.back();
    }
};
