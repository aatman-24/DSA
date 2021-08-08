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

Question : 1047. Remove All Adjacent Duplicates In Stringl
Topic : Stack
Problems : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================

*/



class Solution {
public:

    // O(N) - O(N).
    string removeDuplicates(string s) {

        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(!st.empty() && st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};