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

Question : 232. Implement Queue using Stacks
Topic : Stack
Problems : https://leetcode.com/problems/implement-queue-using-stacks/

==============================> Explanation <=============================================
Two Stack:
    - push: O(N)
    - pop: O(N) -> O(1)
    - top: O(N) -> O(1)

Single Stack:
    - push: O(N) + O(N)(Aux Space)
    - pop: O(1)
    - top: O(1)

==============================> Apporach and Time Complexity <=============================================

1) Stack
Time: O(N)
Space: O(1)

*/


// using double stack.
class MyQueue {
public:

    stack<int> st, rev_st;

    MyQueue() {
        
    }
    
    void push(int x) {

        // first empty rev_st to maintain the order.
        while(!rev_st.empty()) {
            st.push(rev_st.top());
            rev_st.pop();
        }
        st.push(x);
    }
    

    int peek() {
        
        // fill the rev_st with st elements. 
        if(rev_st.empty()) {
            while(!st.empty()) {
                rev_st.push(st.top());
                st.pop();
            }
        }
            
        // top of rev_st is first element for the queue.
        return rev_st.top();
    }
    
    int pop() {

        int peek_ele = -1;

        if(rev_st.empty()) {
            while(!st.empty()) {
                rev_st.push(st.top());
                st.pop();
            }
        }

        // top of rev_st is first element for the queue.
        peek_ele = rev_st.top();
        rev_st.pop();
        return peek_ele;
    }
    
    bool empty() {
        return st.empty() && rev_st.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



// using single stack.
class MyQueue {

public:
    
    stack<int> st;

    MyQueue() {
        
    }
    
    // push the element in reverse order. Every time all elements in
    // stack are popped and pushed again.
    void push(int x) {
        
        if(st.empty()) {
            st.push(x);
            return;
        }

        int popped = st.top(); st.pop();
        push(x);
        st.push(popped);
    }
    

    int pop() {
       int popped = st.top(); st.pop();
       return popped; 
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty():
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */