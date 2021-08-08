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

Question : 647. Palindromic Substrings
Topic : String
Problems : https://leetcode.com/problems/palindromic-substrings/
*/


class Solution {
public:

        int dp[1001][1001];

        bool isPalindrome(string x, int i, int j) {
            while(i <= j && x[i] == x[j]) {i++; j--;}
            return i > j;
        }

        void solve(string x, int i, int j, int &cnt) {

            if(dp[i][j] != -1) return;

            if(isPalindrome(x, i, j-1)) cnt++;

            if(i == j) {
                dp[i][j] = 1;
                return;
            }

            for(int k = i+1; k < j; k++) {
                if(dp[i][k] != -1) solve(x, i, k, cnt);
                dp[i][k] = 1;

                if(dp[k][j] != -1) solve(x, k, j, cnt);
                dp[k][j] = 1;
            }
        }


        // DP - TLE (Don't Try this)
        int countSubString(string x) {
            int cnt = 0;
            memset(dp, -1, sizeof(dp));
            solve(x, 0, x.size(), cnt);
            return cnt;
        }


        void extendFromMid(string s, int left, int right, int &cnt) {
            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                left--; right++; cnt++;
            }
        }

        // O(N^2) Extend from the every middle element for both even and odd length string.
        int countSubstrings(string s) {
            if(s.size() == 0) return 0;
            int cnt = 0;
            for(int mid = 0; mid < s.size(); mid++) {
                extendFromMid(s, mid, mid, cnt); // odd length
                extendFromMid(s, mid, mid+1, cnt); // even length
            }
            return cnt;

        }

};