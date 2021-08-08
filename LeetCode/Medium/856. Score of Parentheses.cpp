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

Question : 856. Score of Parentheses
Topic : Stack
Problems : https://leetcode.com/problems/score-of-parentheses/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
With the 2nd method, by knowing the depth of the core, 
we are actually performing this calculation ( ( ) ) + ( ( ( ) ) )

for ( () (()) ) and only count when first time core occurs.
*/


class Solution {
public:

    // O(N) + O(N) (stack)
    int scoreOfParentheses(string s) {
        
        stack<int> st;
        int i = 0, score = 0;
        
        while(i < s.size()) {
            if(s[i] == '(') {
                st.push(0);
            }
            else {
                int currScore = st.top();
                st.pop();
                
                if(st.empty()) {
                    score += (currScore == 0) ? currScore+1 : currScore*2;
                }
                else {
                    st.top() += (currScore == 0) ? currScore+1 : currScore*2;
                }
            }
            i++;
        }
        return score;
    }

    // O(N) + O(1)
    int scoreOfParentheses(string s) {
        int ans = 0, total_bracket = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                total_bracket++;
            else {
                total_bracket--;
                if(s[i-1] == '(')
                    ans += (1 << total_bracket);
            }
        }
        return ans;
    }
};