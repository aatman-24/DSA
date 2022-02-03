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

Question :  409. Longest Palindrome
Topic : String, Mapping
Problems : https://leetcode.com/problems/longest-palindrome/

==============================> Explanation <=============================================

- In, Palindrome. One odd, Rest is Even... So we directly add maximum even number of characters and one odd number character
if found.

- Same concept is used.

==============================> Apporach and Time Complexity <=============================================

1) String, Mapping
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    int longestPalindrome(string s) {
        
        int count[128] = {0};

        for(auto ch: s)
            count[int(ch)]++;
        
        bool oddFound = false;
        int ans = 0;
        
        for(int i = 0; i < 128; i++) {

            if(count[i] % 2 == 1) {
                oddFound = true;
            }

            // Take multiple of 2. ex... (3/2)*2 = 2.
            ans += (count[i]/2)*2;

        }

        return ans + int(oddFound);
    }
};