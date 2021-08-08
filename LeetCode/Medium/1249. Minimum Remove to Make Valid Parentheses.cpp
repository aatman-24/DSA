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

Question : 1249. Minimum Remove to Make Valid Parentheses
Topic : Stack
Problems : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/g/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
Using stack we keep track of all parenthesis which is not valid and remove it from OG
string.
*/




class Solution {
public:
    // O(N) - O(N)
    string minRemoveToMakeValid(string s) {

        stack<pair<char,int>> st;
        string res;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ')') {
                st.push({s[i], i});
            }
            else {
                while(!st.empty() && st.top().first != '(') {
                    if(st.top().first == ')') {
                        break;     
                    }
                    st.pop();
                }
                if(!st.empty() && st.top().first == '(') { // when valid pair remove it from stack.
                    st.pop();
                } 
                else {
                    st.push({s[i], i}); // not valid pair add ')' into stack.
                }
            }
        }

        while(!st.empty()) {
            if(st.top().first == ')' || st.top().first == '(') {
                s[st.top().second] = '_'; // replace all non valid parenthesis with _ 
            }
            st.pop();
        }

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != '_')
                res += s[i];
        }

        return res;
    }

};