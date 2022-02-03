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

Question : 32. Longest Valid Parentheses
Topic : Stack
Problems : https://leetcode.com/problems/longest-valid-parentheses/

==============================> Explanation <=============================================

Idea is that,

- In stack we match all valid Parentheses so whatever is left is the invalid Parentheses. We store the index of the character.
So whatever difference between them valid Parentheses range. we find the longest of them.


Algorithm:

- Scan the string from beginning to end.

- If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.

- After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.

- If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.


2nd Apporach:

- We perform in single pass. To avoid edge case we add -1 into the stack which never popped from the stack.


3rd Approach(I coded):
- Same approach is used. 
- But, ( -> 0 and for ) -> (merget all the point until got 0[match '(']) + add 1(for match), and again put into stack.
- For unmatch ) -> put 0.
- at the end find the longest streak, take sum of it. keep track of max.
- return max * 2.


==============================> Apporach and Time Complexity <=============================================

1) Stack
Time: O(N)
Space: O(N)

*/


// Two pass.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), longest = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            
            if (s[i] == '(') st.push(i);
            
            else {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                }
                else 
                    st.push(i);
            }
        }

        // base case. Nothing left in stack means all string is valid.
        if (st.empty()) longest = n;


        else {
            
            int currInvalid = n, prevInvalid = 0;

            while (!st.empty()) {

                prevInvalid = st.top(); st.pop();
                
                longest = max(longest, currInvalid-prevInvalid-1);
                
                currInvalid = prevInvalid;
            }

            // when nothing left in stack..last character is 0.
            longest = max(longest, currInvalid);
        }

        return longest;
    }
};




// single pass.
class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        
        // handle base case.
        st.push(-1);
        
        int longest = 0;
        
        for(int i=0; i < s.size(); i++) {

            int t = st.top();

            if(t!=-1 && s[i]==')' && s[t]=='(') {
                
                st.pop();

                // difference between two invalid.
                longest=max(longest,i-st.top());
            }
            else
                st.push(i);
        }

        return longest;
    }
};


// My Solution....
class Solution {

    public:
    
    int longestValidParentheses(string s) {
    
    stack<char> st;
    stack<int> point;

    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '(') {
            st.push(s[i]);
            point.push(0);
        }
        else {
            
            if(!st.empty() && st.top() == '(') {
                
                // merge all the score upto the last zero. which indicate... '('.
                int mergeScore = 0;
                while(!point.empty() && point.top() != 0) {
                    mergeScore += point.top();
                    point.pop();
                }

                // pop -> '(', 0 for match.
                if(!point.empty()) {
                    point.pop();
                    st.pop();
                }

                // increment score and push it again.
                point.push(mergeScore + 1);
            }
            else {

                // mismatch... disturb the streak by adding 0.
                point.push(0);
            }
        }
    }



    int maxPoint = 0, longest;
    
    // find longest streak. 
    while(!point.empty()) {

        longest=0;
        
        while(!point.empty() && point.top() == 0)
            point.pop();

        while(!point.empty() && point.top() != 0) {
            longest += point.top();
            point.pop();
        }

        maxPoint = max(maxPoint, longest);
    }
        
    return maxPoint * 2;
        
    }
};
