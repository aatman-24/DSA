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

Question: 509. Fibonacci Number
Topic : DP, Pattern=Fibonacci
Problems : https://leetcode.com/problems/fibonacci-number/

==============================> Explanation <=============================================

=>> Choice Diagram -> F(N) = F(N-1) + F(N-2)
Explanation: Current F(N) is depend on previous F(N-1) and F(N-2).

==> Base Case -> N == 0 Return 0.
              -> N == 1 Return 1.

==> Recurrance Relation:
    F(N) = F(N-1) + F(N-2).


==============================> Apporach and Time Complexity <=============================================
1) DP, Pattern=Fibonacci:
Time: O(N) (Because There are total N calls be made) * (In Each call O(1) work done) -> O(N)
Space: O(1) O(N)(Memorization)

*/

class Solution {
public:

    int fib(int n) {
        
        if(n <= 1)
            return n;
        
        // Declare Table.
        int dp[n+1];
        memset(dp, 0, sizeof(dp));

        // Base case
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }
};