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

Question: 746. Min Cost Climbing Stairs
Topic : DP, Pattern=Fibonacci
Problems : https://leetcode.com/problems/min-cost-climbing-stairs/

==============================> Explanation <=============================================

- Question Given that, Reach to the top floor indicate that after the last index of the cost. 
topFloor = cost.size() (Confusion clear)

Direct insight about the DP.... Because there are subproblems which needs to solved first based on then
the answer is calculated.

- Here, If we at the ith staircase we don't add its cost but if we used to go from that staircase to
other then we add the cost. Means on topFloor cost is zero. 

- In Short if we jump to the ith staircase from the (i-1) and (i-2) then we add the cost of its own(i-1 and i-2)
not ith staircase.

- In bottom up manner we always go from the N -> 0 so here also we go from topFloor -> (0, 1).


=>> Choice Diagram -> N = min(N-1, N-2)
    Explanation: To reach at Nth step we can come from (N-1) or (N-2) with addition of individual cost but we choose
                 whichever is minimum.

==> Base Case -> N == 0 Return 0.
              -> N == 1 Return 0.
    Explanation: Given that we can start from the 0th or 1st index. 

==> Recurrance Relation: F(N) = min(F(N-1) + cost[N-1], F(N-2) + cost[N-2])


3rd Solution: Idea from fibonaci, because here only last two state is valuable so we can store that state into
two different variable so we don't have to use entire table.
                
==============================> Apporach and Time Complexity <=============================================
1) Memo + TopDown DP, Pattern=Fibonacci:
Time: O(N)
Space: O(N)(Memorization)

2) DP, Pattern = Fibonacci Offline:
Time: O(N) 
Space: O(1)
*/

// Bottom - Up
class Solution {

public:

    int minCost(int n, vector<int> &cost, vector<int> &t) {

        // Base Condition
        if(n == 0 || n == 1)
            return 0;

        if(t[n] != -1)
            return t[n];

        return t[n] = min(minCost(n-1, cost, t) + cost[n-1],  minCost(n-2, cost, t) + cost[n-2]);
    }


    int minCostClimbingStairs(vector<int>& cost) {

        int topFloor = cost.size();

        vector<int> t(cost.size() + 1, -1);

        return minCost(topFloor, cost, t);
    }
};



// Top - Down
class Solution {

public:

    int minCostClimbingStairs(vector<int>& cost) {

        int N = cost.size();

        // make Dp Table.
        int dp[N+1];
        memset(dp, 0, sizeof(dp));
        
        // Base condition
        dp[0] = dp[1] = 0;


        for(int i = 2; i <= N; i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }

        // cost to reach N.
        return dp[N];
    }
};



// Top - Down With No Extra Space
class Solution {

public:

    int minCostClimbingStairs(vector<int>& cost) {

        int N = cost.size();

        // Base Condition  a->0th index, b->1st index
        int a = 0, b = 0;

        for(int i = 2; i <= N; i++) {

            int c = min(b+cost[i-1], a+cost[i-2]);
            a = b;
            b = c;
        }

        // at Last for N step calculated value of C is stored into the b at last.
        return b;
    }
};