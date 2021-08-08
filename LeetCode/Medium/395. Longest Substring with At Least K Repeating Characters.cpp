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

Question : 395. Longest Substring with At Least K Repeating Characters
Topic : Sliding Window
Problems : https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

/*
==============================> Explanation <=============================================


*/

/*
==============================> Edge Case <=============================================

*/

// 

class Solution {
public:
    

    // Here we find longest Substring in which uniqueChar == targetUniqueChar and all uniquechar is 
    // repeated at least k times.
    int longestSubstringUtil(string s, int k, int targetUniqueChar) {

        int map[128] = {0};

        // curUniqueChar = In current window Total unique char.
        // numNolessThankChar = In current window all unique char which repeated atleast k times.
        int curUniqueChar = 0, numNolessThankChar = 0, begin = 0, end = 0, d = 0;


        while(end < s.size()) {

            // When Any character is first time enter into window that mean it is unique.
            if(map[s[end]]++ == 0) curUniqueChar++;

            // If current char is repeated k times so we update numNolessThank.
            if(map[s[end++]] == k) numNolessThankChar++;


            // If current unique char is greater than targetUniqueChar than we need to shrink the 
            // window. And we update the both numNolessThankChar and curUniqueChar.
            while(curUniqueChar > targetUniqueChar) {
                if(map[s[begin]]-- == k) numNolessThankChar--;
                if(map[s[begin++]] == 0) curUniqueChar--;
            }

            // when we found that current unique char == target unique char and current unique char
            // all have atleast k occurace that we update our length.
            if(curUniqueChar == targetUniqueChar && curUniqueChar == numNolessThankChar) {
                d = max(d, end-begin);
            }


            return d;

        }
    }


    int longestSubstring(string s, int k) {

        int length = 0;
        for(int targetUniqueChar = 1; targetUniqueChar <= 26; targetUniqueChar++)
            length = max(length, longestSubstringUtil(s, k, targetUniqueChar));

        return length;

    }


};