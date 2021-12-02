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

Question: 20. Valid Parentheses
Topic : Stack
Problems : https://leetcode.com/problems/valid-parentheses/

==============================> Explanation <=============================================

- Simple Stack Application... Push the open bracket and pop the open bracket if it match with closed bracket. 

==============================> Apporach and Time Complexity <=============================================

1) Stack
Time: O(N)
Space: O(N)

*/

class Solution {
public:
	
    map<char, char> mp;

    bool isValid(string s) {

        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';


        stack<char> st;
        for(auto ch: s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
            else {
                if(!st.empty() && st.top() == mp[ch]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};