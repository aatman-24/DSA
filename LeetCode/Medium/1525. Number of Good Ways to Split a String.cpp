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

Question : 1525. Number of Good Ways to Split a String
Topic : String
Problems : https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

*/

// total way is n-1.

// keep track of left side distinct element and also right side of element.

// check left[i] == right[i+1] then that is one way to split.


#define A 97

// O(N) - O(N)
class Solution {
public:
    
    int mark[30];

    int numSplits(string s) {
        int n = s.size();
        int lft[n], rht[n];

        memset(mark, 0, sizeof(mark));
        
        lft[0] = 1;
        mark[s[0] - A] = 1;
        for(int i = 1; i < n; i++) {
            if(mark[s[i] - A] == 1) {
                lft[i] = lft[i-1];
            } 
            else {
                mark[s[i] - A] = 1;
                lft[i] = lft[i-1] + 1;
            }
        }

        memset(mark, 0, sizeof(mark));
        rht[n-1] = 1;
        mark[s[n-1] - A] = 1;
        for(int i = n-2; i >= 0; i--) {
            if(mark[s[i] - A] == 1) {
                rht[i] = rht[i+1];
            } 
            else {
                mark[s[i] - A] = 1;
                rht[i] = rht[i+1] + 1;
            }
        }
        
        int cnt = 0;

        REP(i, n-1) {
            if(lft[i] == rht[i+1]) cnt++;
        }

        return cnt;
    }
};