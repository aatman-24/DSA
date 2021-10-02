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

Question: 1910. Remove All Occurrences of a Substring
Topic : Stack, String, KMP
Problems : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

==============================> Explanation <=============================================
Both Solution is Same...

1) Stack Solution: Here We store the visited characters into the stack. when the stack size is greater or equal
to pattern size we check that top of character is same with pattern or not if yes then we remove it.


2) KMP Algorithm: Remaining...



==============================> Apporach and Time Complexity <=============================================
1) Stack Solution:
Time: O(N^2)
Space:  O(N)
*/


class Solution {
public:
    
    bool check(stack<char> st, string part) {

       for(int j = part.size() - 1; j >= 0 && !st.empty(); j--) {
          if(st.top() != part[j])
             return false;
          st.pop();
       }
       return true;
    }


    string removeOccurrences(string s, string part) {

       stack<char> st;
       for(int i = 0; i < s.size(); i++) {
          st.push(s[i]);

          // check above part.size() elements in the stack is same as part.
          if(st.size() >= part.size()) {

             if(check(st, part)) {
                  // yes then remove that elements
                int count = part.size();
                while(count--)
                   st.pop();
             }
          }
       }

       string ans = "";
       while(!st.empty()) {
          ans += st.top(); st.pop();
       }

       reverse(ans.begin(), ans.end());

       return ans;
    }

};


class Solution {
public:
    

    string removeOccurrences(string s, string part) {

       string ans = s;
       int j = 0, m = part.size();
       for(int i = 0; i < s.size(); i++) {
          ans[j++] = s[i];
          if(j >= part.size() && ans.substr(j-m, m) == part) {
             j -= m;
          }  
       }
       return ans.substr(0, j);
    }

};