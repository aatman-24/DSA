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

Question : 5. Longest Palindromic Substring
Topic : DP, both side traversal
Problems : https://leetcode.com/problems/longest-palindromic-substring/
*/


class Solution {
public:
        
    void extendSubstring(string s, int &left, int &right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++; 
        }
    }

    string makeStringFromIndex(string s, int lft, int rht) {
        string ans = "";
        for(int i = lft; i <= rht; i++) ans += s[i];
        return ans;
    }

    // O(N^2)
    string longestPalindrome(string s) {

        int lft, rht;
        string ans;
        int maxL = 0;
        for(int mid = 0; mid < s.size(); mid++) {
            
            lft = mid, rht = mid;
            extendSubstring(s, lft, rht); // odd length
            lft++; rht--;
            if(rht - lft >= maxL) {
                maxL = rht - lft;
                ans = makeStringFromIndex(s, lft, rht);

            }


            lft = mid, rht = mid + 1;
            extendSubstring(s, lft, rht); // even length
            lft++; rht--;
            if(rht - lft >= maxL) {
                maxL = rht - lft;
                ans = makeStringFromIndex(s, lft, rht);
            }
        }

        return ans;

    }

    // DP - O(N^2)    
    string longestPalindrome(string s) {
        int n = s.length();
        int start=0, end=0;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int i=n-1;i>=0;i--) {
            for(int j=i; j<n; j++) {

                // if len(str) == 1 return true
                // if len(str) == 2 then return str[0] == str[1] (both are equal)
                // if len(str) > 2 then check the dp table if dp[i+1][j-1] is palindrome or not.

                dp[i][j]= s[i]==s[j] && (j-i<2||dp[i+1][j-1]);  
                if(dp[i][j]==true && j-i>end-start) {
                    start=i;
                    end=j;
                }

            }
        }
        string ans = "";
        for(int i = start; i <= end; i++) {
            ans += s[i];
        }

        return ans;
        
    }
};