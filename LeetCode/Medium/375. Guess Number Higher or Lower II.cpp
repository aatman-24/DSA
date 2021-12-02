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

Question: 375. Guess Number Higher or Lower II
Topic : Top-Down Bottom-up Pattern=MultidimesionalDP
Problems : https://leetcode.com/problems/guess-number-higher-or-lower-ii/

==============================> Explanation <=============================================

- Dp variant = IntervalDP.

- Problem Description is written wrong or confused way.

OG: minimum amount of money you need to guarantee a win regardless of what number I pick. 
- maxMoney = N * (N+1) / 2
- maxMoney is needed, when we pick any element which gives guarantee that we never lose.

Suppose, N = 3.. then {1, 2, 3} is option to pick and guess. We need to find minimum amount of money
such that if you pick any element from that then chosen element leads to target in maximum cost(worst case).
- And you have three option to pick up {1, 2, 3} so you pick up that element which gives the minimum worst
case.. minimum amount to lead target in worst case.

Example.... N=3,

{1, 2, 3} -> {target is 3} -> 1 -> 2 -> 3, cost = 1 + 2 = 3.
{1, 2, 3} -> {target is 1} -> 3 -> 2 -> 1, cost = 3 + 2 = 5.
{1, 2, 3} -> {target is 1} -> 2 -> 1, cost = 2
{1, 2, 3} -> {target is 3} -> 2 -> 3, cost = 2

So you choose the 2 element first because it will lead to the target in minimum cost in worst scenario.

- minimum amount(best case) of money you need to guarantee a win regardless of what number I pick(Worst case).
But it is very hard to decode this sentance, or what it means.




1) Choise Diagram: 

from [low, high] we can pick any element=xi,  and find the worst cost to reaching xi from both left and
right side and choose the maximum(worst) cost from that. And for the given range [low, high] we choose best
among all the xi(k).


dp[low][high] -> minimumCost. k = xi

minimumCost = min(minimumCost, max(dp[i][k-1](left), d[i][k+1](right)) + k(chosen so add cost for it));


2) Base Case: when, range is [1,1], [2,2] that time we directly guess the number so cost = 0.
              

3) Recurrance Relation: 

    dp[low][high] -> minimumCost. k = xi

    minimumCost = min(minimumCost, max(dp[i][k-1], d[i][k+1]) + k);  


Bottom-up is not easy, Remember this template for IntervalDP.... Because here left and right side of cost
must be calculated first...

It is MCM version filling the dp table.

for(int l = 1; l<n; l++) {
   for(int i = 0; i<n-l; i++) {
       int j = i+l;
       for(int k = i; k<j; k++) {
           dp[i][j] = max(dp[i][j], dp[i][k] + result[k] + dp[k+1][j]);
       }
   }
}
 
==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=MultidimesionalDP
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:
    int t[201][201];

    int helper(int low, int high) {

        if(low >= high)
            return 0;

        if(t[low][high] != -1)
            return t[low][high];
        

        // find the minimum cost to reach at the target while picking up the any element between [low, high]
        // which lead to the target in worst case.
        int minimalCost = INT_MAX;
        for(int k = low; k <= high; k++) {
            minimalCost = min(minimalCost, max(helper(low, k-1), helper(k+1, high)) + k);
        }

        return t[low][high] = minimalCost;
    }

    int getMoneyAmount(int n) {

        memset(t, -1, sizeof(t));

        return helper(1, n);

    }
};



class Solution {
public:

    int getMoneyAmount(int n) {

        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));

        // base case.
        for(int i = 1; i <= n; i++)
            dp[i][i] = 0;

        for(int len = 1; len <= n; len++) {                 // as per the template len -> i -> j -> k.
            
            for(int i = 1; i + len <= n ; i++) {

                int j = i + len;

                dp[i][j] = INT_MAX;

                for(int k = i; k <= j; k++) {

                    int temp = k + max(k - 1 >= i ? dp[i][k-1] : 0, k + 1 <= j ? dp[k+1][j]: 0);

                    dp[i][j] = min(dp[i][j], temp);
                }
            }
        }

        return dp[1][n];
    }
};