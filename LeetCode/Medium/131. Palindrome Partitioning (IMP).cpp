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

Question : 131. Palindrome Partitioning (IMP)
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
public:
    vector<vector<string>> ans;

    bool _isPalindrome(string s, int l, int r) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(string s, int start, vector<string> &tmp) {

        if(s.size() == start) {
            ans.push_back(tmp);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(_isPalindrome(s, start, i)) {
                tmp.push_back(s.substr(start, i+1-start));
                backtrack(s, i+1, tmp);
                tmp.pop_back();
            }   
        }
        
    }

    vector<vector<string>> partition(string s) {
        ans.clear();
        vector<string> tmp;
        backtrack(s, 0, tmp);   
        return ans;  
    }

};

/*
s = 'aabaa'

a a b a a
a a b aa
a aba a
aa b a a
aa b aa
aabaa

*/