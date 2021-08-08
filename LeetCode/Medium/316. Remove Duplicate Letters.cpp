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

Question : 316. Remove Duplicate Letters 
Topic : Monotone Stack
Problems : https://leetcode.com/problems/remove-duplicate-letters/
pattern : 1 
/*
==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================

1] if s[i] is already in stack we skip it. It does not add any value bcz former s[i] is
in stack and it is already in increasing sequence.


2] st.top() is going to pop if st.top() again occur in S. which we can check using 
occurance of st.top().

*/


class Solution {
public:
    string removeDuplicateLetters(string s) {

        int visited[26], count[26];

        memset(visited, 0, sizeof(visited));
        memset(count, 0, sizeof(count));

        for(int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;

        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            count[s[i]-'a']--;

            // abcbc for second b we can skip it because using former b(1) we make same 
            // sequence. And also we already in increasing order then why do we add 
            // this character b(3) and pop the c ?
            if(visited[s[i]-'a']) 
                continue; 

            // only allowed pop opreation if st.top() is again going to occur after s[i].
            // if not then we don't pop it and push s[i] after it.
            while(!st.empty() && count[st.top() - 'a'] != 0 && st.top() > s[i]) {
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i] - 'a'] = 1;
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