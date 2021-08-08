#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 1541. Minimum Insertions to Balance a Parentheses String
Topic : Stack
Problems : https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
This is not solve using stock span technique.

Here given than if and only if two consecutive ')' then and only it
become valid. 


means if ()())) this is not valid (cost != 0) but
cost = 1 + 2 = 3.

*/



class Solution {
public:
    
   int minInsertions(string s) {

    int cost = 0;
    stack<char> st;


    for(int i = 0; i < s.size(); i++) {

        if(s[i] == '(') {
            // if stack top is '()' and encounter '(' that mean 
            // we don't make consecutive '))'.
            // so we add ')' which make '())' and remove everything.
            // then push '('
            if(!st.empty() && st.top() == 1) {
                cost += 1;
                st.pop();
            }
            st.push(2);
        }
        else {

            // stack is empty. So we add ( this and make it ().
            if(st.empty()) {
                cost += 1; // for adding '('
                st.push(1); // add () into stack.
            }
            // stack is () and encounter ) so we pop ().
            else if(st.top() == 1) {
                st.pop();
            }
            // stack is ( and encounter ) so we replace top of stack with 1.
            else if(st.top() == 2) {
                st.pop();
                st.push(1);
            }
        }
    }


    while(!st.empty()) {
        cost += st.top();
        st.pop();
    }

    return cost;
}


    int minInsertions(string s) {

        int cost = 0, right = 0;
        for(char &c : s) {
            if(c == '(') {
                if(right % 2 > 0) {
                    cost++; // odd number of right. Last sequence must be '()'.
                    right--; // remove single bracket bcz it make pair after adding one more ')'.     
                }
                right += 2; // encounter '(' this means need to add '))'.
            }
            else {
                right--;

                if(right < 0) {

                    // right < 0 when we have right = 0. first ')' this one encounter
                    // so right < 0. so we add right += 2 (one we encounter + one need to add)
                    // here we add right balance not into cost. bcz if we again encounter right
                    // then its going to become 0. which does not cost anything. but if we did not
                    // encounter again then we add last (cost + right) in which it automatically
                    // add into cost.

                    // cost += 1. (for '(') because we directly see ')' this so must have
                    // '(' before this.
                    right += 2; 
                    cost++;
                }
            }
        }
        return cost + right;

    }

};