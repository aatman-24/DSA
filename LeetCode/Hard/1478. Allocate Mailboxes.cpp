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

Question: 1478. Allocate Mailboxes
Topic : Top-Down Bottom-up Pattern=MultiDimesionalDP + IntervalDP
Problems : https://leetcode.com/problems/allocate-mailboxes/

==============================> Explanation <=============================================
Dp variant = MultiDimesionalDP + IntervalDP.

So, First Idea is that, When we given K mailBox then we can divide it between all the houses such that
There are total K house group created and every house group is near to the one of the mailBox.

It leads to us, Creating the K group Houses With Minimum Cost.

So It is MultiDimesionalDP Reason is K = 1. [1, 4] -> Cost will be = 3.
                                     K = 2. [1, 4] -> Cost will be = 0.

So based on K and index [i, j] the cost will be different.


1) Choise Diagram: 

- So Now We have Choise, To create a one group on left and (k-1) group on right(Same as Cutting Rod) between
[i, j]. Single Left group is -> [i, k] + (n-1) groups in [k+1, j]. We add both cost to get total cost and
choose minimum cost.

- In simple parititon the array into k groups which give you the minimum cost.


2) Base Case: N = 1 We calculate the cost for [i, j] houses.

How cost is calculated ?

- When N = 1.
[1, 3] -> We can put MailBox on middle corrdination = 2 -> Cost = (2-1) + (3-2) = 2.
          But we can also put the MailBox on Middle of the house X = house[(0+1)/2] = house[0] = 1.
          Which also give the same cost.

[1, 5, 9] -> Here, we put the MailBox on 5. On Middle House Corrdination.

Why ?
https://leetcode.com/problems/allocate-mailboxes/discuss/685620/JavaC%2B%2BPython-Top-down-DP-Prove-median-mailbox-O(n3)

In short, Remember this.... Putting on middle house coordination gives the minimum cost.

3) Recurrance Relation:

dp[n][i][j] = min(dp[n][i][j], dp[1][i][k] + dp[n-1][k+1][j]);
             
dp[n][i][j] -> Given the minimum cost by grouping the [i, j] houses in N groups. 



==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern = MultiDimesionalDP+IntervalDP
Time: O(N^2*K)
Space: O(N^2*K)

*/


class Solution {
public:

    int t[101][101][101];

    int minDistance(int n, int i, int j, vector<int> &houses) {

        // If i == j, putting mailBox on it result into the zero cost same as i > j then no need to put
        // mailBox on such invalid condition.
        if(i >= j)
            return 0;
        
        // I put this before base condition reason is simple, in Base condition It will calculate the cost
        // which will take O(N). So to avoid repeating calculation of cost I put this above. 
        if(t[n][i][j] != -1)
            return t[n][i][j];
            


        // Base Condition. Calculate the cost for [i, j] houses while putting the singleMailBox for all.
        if(n == 1) {
            
            int midPos = houses[(i+j)>>1];
            
            int cost = 0;

            for(int index = i; index <= j; index++) {

                cost += abs(midPos - houses[index]);
            
            }

            return t[n][i][j] = cost;
        }



        int cost = INT_MAX;

        for(int k = i; k < j; k++) {

            cost = min(cost, minDistance(1, i, k, houses) + minDistance(n-1, k+1, j, houses));        
        
        }

        return t[n][i][j] = cost;
    }
        


    int minDistance(vector<int>& houses, int k) {

        memset(t, -1, sizeof(t));

        sort(houses.begin(), houses.end());


        return minDistance(k, 0, houses.size() - 1, houses);
    }

};

class Solution {
public:

        int minDistance(vector<int>& houses, int k) {

        int N = houses.size();
        sort(houses.begin(), houses.end());

        int dp[k+1][N+1][N+1];
        memset(dp, 0, sizeof(dp));


        // base case, When K = 1. Find the cost for all the [i, j].
        for(int i = 0; i < N; i++) {
            
            for(int j = 0; j < N; j++) {

                int midPos = houses[(i+j)>>1];

                for(int k = i; k <= j; k++) {

                    dp[1][i][j] += abs(midPos - houses[k]);
                
                }

            }
        }

        // Added MultiDimesionalDP Covers on IntervalDP.
        for(int n = 2; n <= k; n++) {

            // Same as IntervalDP.
            for(int len = 1; len < N; len++) {              // len = 1. Because [i==j] then cost is zero to put mailbox on it.

                for(int i = 0; i + len < N; i++) {          // i start with 0, so end at N-1.

                    int j = i + len;

                    dp[n][i][j] = INT_MAX;

                    for(int k = i; k < j; k++) {            // ensure this boundary.

                        dp[n][i][j] = min(dp[n][i][j], dp[1][i][k] + dp[n-1][k+1][j]);

                    }

                }

            }

        }

        // using k mail box return minCost of given array[0, arr.size()-1].
        return dp[k][0][N-1];
        
    }
};
