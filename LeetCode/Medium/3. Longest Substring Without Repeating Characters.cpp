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

Question : 3. Longest Substring Without Repeating Characters
Topic : Sliding Window
Problems : https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
==============================> Explanation <=============================================


*/

/*
==============================> Edge Case <=============================================

*/

// 


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int begin = 0, end = 0, d = 0;
        int map[128] = {0};

        while(end < s.size()) {
           if(map[s[end]] == 0) {
                map[s[end++]]++;  // works s[end] -> map[s[end]]++ -> end++
           }
           else {
                while(map[s[end]] != 0) {
                    map[s[begin++]]--; // works s[begin] -> map[s[begin]]-- -> begin++
                }
           }
           d = max(d, end-begin);
        }

        return d;
    }

};