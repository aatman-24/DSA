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

Question: 150. Evaluate Reverse Polish Notation
Topic : Stack, Expression Evalution
Problems : https://leetcode.com/problems/evaluate-reverse-polish-notation/

==============================> Explanation <=============================================
- Idea is very simple,

Use Stack, When the Opreator found perform the mathematic opreation of stack top most
two elements and add the result back to the stack. Last element in the stack is result.

==============================> Apporach and Time Complexity <=============================================
1) Stack:
Time: O(M*N) Consider the longest number in string has length M.
Space: O(N)

*/

class Solution {
public:
    int getNumber(string token) {

        bool negative = token[0] == '-';
        int i = 0, n = token.size(), num = 0;
        if(negative) i++;

        while(i < n) {
            num = num * 10 + int(token[i]-'0');
            i++;
        }

        if(negative)
            return -num;

        return num;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        
        for(string token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                
                if(token == "+") {
                    st.push(num2 + num1);
                }
                else if(token == "-") {
                    st.push(num2 - num1);
                }
                else if(token == "*") {
                    st.push(num2 * num1);
                }
                else {
                    st.push(num2 / num1);
                }
            }
            else {
                int num = getNumber(token); // stoi(token);
                st.push(num);
            }
        }

        return st.top();
    }
};