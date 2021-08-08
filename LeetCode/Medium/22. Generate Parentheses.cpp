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

Question : 22. Generate Parentheses
Topic : String, Backtracking
Problems : https://leetcode.com/problems/generate-parentheses/
*/


class Solution {
public:

        // METHOD - 1 generate all duplicate string also.
        set<string> st;

        void solve(int i, int n, string curString) {
            if(i == n) {
                st.insert(curString);
                return;
            }
            int m =  curString.size();
            for(int pos = 1; pos <= m; pos++) {
                string old_string = curString;
                curString.insert(pos, "()");
                solve(i+1, n, curString);
                curString = old_string;
            }
        }

        vector<string> generateParenthesis(int n) {
            string curString = "()";
            st.clear();
            solve(1, n, curString);

            vector<string> res;

            for(auto i : st) {
                res.push_back(i);
            }

            return res;
        }


        // METHOD - 2 Doesn't generate duplicate string.
        vector<string> ans;

        void backtrack(string str, int open, int close, int n) {
            if(str.size() == 2*n) {
                ans.push_back(str);
                return;
            }
            if(open < n) {
                backtrack(str + '(' , open+1, close, n);
            }
            if(close < open) {
                backtrack(str + ')', open , close+1, n);
            }
        }

        vector<string> generateParenthesis(int n) {
            ans.clear();
            backtrack("", 0, 0, n);
            return ans;
        }

};