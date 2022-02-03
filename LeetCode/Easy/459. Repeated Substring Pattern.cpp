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

Question : 459. Repeated Substring Pattern
Topic : String
Problems : https://leetcode.com/problems/repeated-substring-pattern/

==============================> Explanation <=============================================

- If we add string s + s, and after remove the first and last character from that string and if we found the
og string into that, means we can construct the string by repeating the substring.

==============================> Apporach and Time Complexity <=============================================

1) String
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};