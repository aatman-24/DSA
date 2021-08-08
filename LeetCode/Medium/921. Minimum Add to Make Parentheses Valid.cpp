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

Question : 921. Minimum Add to Make Parentheses Valid
Topic : Stack
Problems : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

*/


class Solution {
public:

    // O(N) + O(N) (stack)
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(s[i]);
            else {
                if(!st.empty() && st.top() == '(') 
                    st.pop();
                else 
                    st.push(s[i]);
            }
        }    
        return st.size();
    }

    // O(N) - O(1)
    int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        for (char c : S)
            if (c == '(')
                right++;
            else if (right > 0)
                right--;
            else
                left++;
        return left + right;
    }
};