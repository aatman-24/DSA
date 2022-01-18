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

Question: 225. Implement Stack using Queues
Topic : Stack, Queue, Design
Problems : https://leetcode.com/problems/implement-stack-using-queues/

==============================> Explanation <=============================================

Two Queue: q1 and q2

1) push -> O(1), pop/top -> O(2N).
Brute Force: push: add elements into the q1. 
             pop/top: retrive the last element of q1 using q2 as temporary storage.
                     - first pop elements from the q1 and add into the q2. Retrive the last element here.
                     - Again pop elements from the q2 and add into the q1.


2) push -> O(1), pop/top -> O(N).
Optimized version: 
         - Same as above but don't add back element into the q1 again into the pop and top operation.


3) push -> O(N), pop/top -> O(1)
we maintain reverse order into the queue for O(1) operation for pop and top.
push: if q1 empty add the current element into the q1 and then all elements of q2 into the q1. vice versa.
pop/top: Whichever queue is filled return that q.front() and q.pop();



==============================> Apporach and Time Complexity <=============================================

1) Stack, Queue, Design
Time: push: O(1), pop/top: O(2N)
Space: O(N)


2) Optimized: Stack, Queue, Design
Time: push: O(1), pop/top: O(2N)
Space: O(N)

*/



class MyStack {
public:
    MyStack() {
        queue<int> q1, q2;
    }
    
    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }
    
    int pop() {
      int last = -1;
      if(q1.empty()) {
        while(!q2.empty()) {
            last = q2.front(); q2.pop();
            if(!q2.empty())
                q1.push(last);
        }
      }
      else {
        while(!q1.empty()) {
            last = q1.front(); q1.pop();
            if(!q2.empty())
                q2.push(last);
        }
      }
      return last;  
    }
    
    int top() {
      int last = -1;
      if(q1.empty()) {
        while(!q2.empty()) {
            last = q2.front(); q2.pop();
            q1.push(last);
        }
      }
      else {
        while(!q1.empty()) {
            last = q1.front(); q1.pop();
            q2.push(last);
        }
      }
      return last; 
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */




class MyStack {

public:
    
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()) {
            q1.push(x);
            while(q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while(q1.empty()) {
                q2.push(q1.front());
                q1.pop():
            }
        }
    }
    
    int pop() {
        int popped_element = -1;
        if(!q1.empty()) {
            popped_element = q1.front();
            q1.pop();
            return popped_element;
        }
        if(!q2.empty()) {
            popped_element = q2.front();
            q2.pop();
            return popped_element;
        }
        return popped_element;
    }
    
    int top() {
        if(!q1.empty()) { 
            return q1.front();
        }
        if(!q2.empty()) {
            return q2.front();
        }
        return -1
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */