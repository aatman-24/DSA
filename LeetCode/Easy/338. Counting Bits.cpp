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

Question: 338. Counting Bits
Topic : Linear-DP 
Problems : https://leetcode.com/problems/counting-bits/

==============================> Explanation <=============================================

In Binary number representation we know pattern is occur so i take the idea from that,

0      0000
1      0001             -> parent = 0.
2      0010
3      0011
4      0100             -> parent = 0.
5      0101
6      0110
7      0111
8      1000             -> parent = 0.
9      1001
10     1010

Pattern is repeated, 0, 1, 4, 8, 16, 32......
And the count[i] = count[parent - offset] + 1.
offset is nothing but...2^K. First K = 1, 2, 3, 4.....   

But rathar than doing this we can simply keep track of one offset and multiply by 2 every time that hit
number like, 0, 1, 4, 8, 16, 32... like that.

=>> Choice Diagram -> count[i] = count[parent - offset] + 1.

==> Base Case -> count[0] = 0.

==> Recurrance Relation: count[i] = count[parent - offset] + 1.

==============================> Apporach and Time Complexity <=============================================
1) Top-Down + Bottom-UP Linear-DP:
Time: O(N)
Space: O(N)(Memorization)
*/


class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> dp(n+1, 0);
        dp[0] = 0;

        int offset = 1;
        for(int index = 1; index <= n; index++) {
            if(offset* 2 == index)
                offset *= 2;
            dp[index] = dp[index - offset] + 1;
        }

        return dp;
    }
};