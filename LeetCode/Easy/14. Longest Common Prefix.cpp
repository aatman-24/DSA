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

Question: 14. Longest Common Prefix
Topic : Prefix, String
Problems : https://leetcode.com/problems/longest-common-prefix/

==============================> Explanation <=============================================

- Need to find prefix of all the array, so we just match first string characters with others.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(N)
Space: O(1)

*/

class Solution {
public:
    
    
    string longestCommonPrefix(vector<string>& strs) {
    
        // Find minimum string size.
        int n = INT_MAX;
        for(auto str: strs) {
            n = min(n, (int)str.size());
        }
        
        string ans="";
        if(n == 0)
            return ans;
                
        
        bool flag = true;

        for(int i = 0; i < n && flag; i++) {

            char needToMatch = strs[0][i];
            
            for(auto str: strs) {

                // Don't match with any string then break it.. No need to check further.
                if(needToMatch != str[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                ans += needToMatch;
        }

        return ans;
    }
};