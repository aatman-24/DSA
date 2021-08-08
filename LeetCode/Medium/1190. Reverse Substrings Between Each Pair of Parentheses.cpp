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

Question : 1190. Reverse Substrings Between Each Pair of Parentheses
Topic : Stack
Problems : https://leetcode.com/problems/validate-stack-sequences/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

*/


class Solution {
public:

    //O(N^2) - O(1)
    string reverseParentheses(string s) {
        vector<int> bracket_index;
        string res;
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') 
                bracket_index.push_back(i);
            else if(s[i] == ')') {
                int j = bracket_index.back();
                bracket_index.pop_back();
                reverse(res.begin() + j, res.end());
            }
            else
                res += s[i];
        }
        return res;
    }

    // O(N) - O(N)
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> bracket_index, index(n);
        
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') 
                bracket_index.push_back(i);
            else if(s[i] == ')') {
                int j = bracket_index.back();
                bracket_index.pop_back();
                index[i] = j;
                index[j] = i;
            }
        }

        string res;
        for(int i = 0, d = 1; i < n; i += d) {
            if(s[i] == ')' || s[i] == '(')
            {
                i = index[i], d = -d;
            }
            else {
                res += s[i];
            }
        }
        return res;

    }
};
