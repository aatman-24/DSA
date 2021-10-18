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

Question: 935. Knight Dialer
Topic : Top-Down Pattern=DpOnPath
Problems : https://leetcode.com/problems/knight-dialer/

==============================> Explanation <=============================================
- Idea is that,

- DP or Matrix or find the number of way or reach to target int Matrix or not this question is variant of
that.

- Ideas is that, If at current (i, j) then we can reach to diffrent 8 position we use that all position
as subproblems. And also here the state is represented by the 3 variable N and (x, y).

N represent the layer, N = 1 -> 10 position, N = 2 -> 20 poisition,

- so [1][2][3]  and [2][2][3] is different subproblem actually subproblem of subproblems.

https://leetcode.com/problems/knight-dialer/discuss/190787/How-to-solve-this-problem-explained-for-noobs!!!


1) Choise Diagram: 8 position check on below.

2) Base Case: N == 1 -> return 1.

3) Recurrence Relation: 

    dp[i] = we take sum of all the 8 positions.


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=DpOnPath
Time: O(N^2)
Space: O(N^2)

*/

#define mod 1000000007

class Solution {
public:
    long knightDialer(int i, int j, int n, long t[][4][3]) {

        // base 
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1))
            return 0;

        if(n == 1) return 1;

        if(t[n][i][j] != -1)
            return t[n][i][j];

        long ans = 0;

        ans += knightDialer(i-1, j+2, n-1, t) % mod;
        ans += knightDialer(i-1, j-2, n-1, t) % mod;
        ans += knightDialer(i+1, j+2, n-1, t) % mod;
        ans += knightDialer(i+1, j-2, n-1, t) % mod;
        ans += knightDialer(i-2, j-1, n-1, t) % mod;
        ans += knightDialer(i-2, j+1, n-1, t) % mod;
        ans += knightDialer(i+2, j-1, n-1, t) % mod;
        ans += knightDialer(i+2, j+1, n-1, t) % mod;

        return t[n][i][j] = ans;
    }



    int knightDialer(int n) {

        long t[n+1][4][3];
        memset(t, -1, sizeof(t));

        long ans = 0;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                ans = (ans + knightDialer(i, j, n, t)) % mod;
            }
        }

        return (int)ans;
    }
};








