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

Question: 1137. N-th Tribonacci Number
Topic : DP, Pattern=Fibonacci
Problems : https://leetcode.com/problems/n-th-tribonacci-number/

==============================> Explanation <=============================================

=>> Choice Diagram -> F(N) = F(N-1) + F(N-2) + F(N-3)
Explanation: Current F(N) is depend on previous F(N-1) and F(N-2).

==> Base Case -> N == 0 Return 0.
              -> N == 1 Return 1.
              -> N == 2 Return 1.

==> Recurrance Relation:
    F(N) = F(N-1) + F(N-2) + F(N-3)


==============================> Apporach and Time Complexity <=============================================
1) DP, Pattern=Fibonacci:
Time: O(N)
Space: O(N)(Memorization)

1) DP, Pattern=Fibonacci Offline:
Time: O(N) 
Space: O(1)

*/

// Top-Down Apporach
class Solution {
public:
    int tribonacci(int n) {
        
        // Base
        if(n <= 1)
            return n;

        // Table Entry with Base
        int dp[n+1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};

// Dp but Online Apporach(Not Store all the state.)
class Solution {
public:

    int tribonacci(int n) {

        if(n <= 1)
            return n;

        int a = 0, b = 1, c = 1;
    
        while(n-- > 2) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;        
        }

        return c;
    }
};