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

Question: 174. Dungeon Game
Topic : Top-Down Bottom-up Pattern=dpOnPath
Problems : https://leetcode.com/problems/dungeon-game/
==============================> Explanation <=============================================

- You don't get clear idea in first sight,

We go from [m-1][n-1] -> [0][0] (backward).... forward is much harder than this one.
- we ensure that knightblood never goes <= 0. If it goes then we add the blood into the knight
and take the added blood into considertation.

- What we stored into the dp table or memo ?
--> We store the minimum blood required still now to reach current (i, j) to (m-1, n-1).


Base Case:

1) grid[m-1][n-1] <= 0
- Then to be alive on that cell, we need atleast 1 amount of blood.
So, dp[m-1][n-1] = 1 + -(grid[m-1][n-1]) 
-(grid[m-1][n-1]) make the blood 0. and +1 will give the gurantee knight is alive. 


2) grid[m-1][n-1] > 0
-That means we > 0 amount of blood. But to be alive we need only 1
amount of blood. We are counting minimum blood.
dp[m-1][n-1] = grid[m-1][n-1] <= 0 ? 1 + -(grid[i][j]) : 1;



General Case (Recurrance relation):

1) grid[i][j] < 0:

requiredHp = min(dp[i+1][j], dp[i][j+1]) - grid[i][j];

- grid[i][j] < 0 which increase the requiredHp.... That's we need atleast that amount. 
because the both neighbor state already give minimum knight blood that required from them.
(already we saw if blood is greater than even we return 1 which is minimum required blood).

- so we just need to add what is required for the current cell(i, j). And grid[i][j] < 0
then blood is simple required not anything else.

2) grid[i][j] > 0:

We first calculate,

requiredHp = min(dp[i+1][j], dp[i][j+1]) - grid[i][j];

A) requiredHp < 0:
- It indicate that whatever blood is required still from [(m-1,n-1)...(x,y)],(i,j).
(m-1,n-1) -> (x, y) path is neutralize by current cell (i, j) that's why requiredHp is become
negative. And what ever abs(requiredHp) is the extra(spare) blood we have right now.

- so again we don't calculate the remaining blood, but minimum blood required is 1 to alive.
that time we return 1.

2) requiredHp > 0:
- Indicate that, after adding the +blood there is still some requirement from
(m-1,n-1) -> (i, j) path such that knight must be alive. so we return that requiredHP.



Forwared (0,0) -> (m-1, n-1) is hard 
because we need to keep track of remaining power and minimum power at the same time and based
on that we need to take the decision.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=dpOnPath
Time: O(N*M)
Space: O(N*M)

*/



class Solution {
public:

    int t[201][201];

    int calculateMinimumHP(int i, int j, vector<vector<int>> &dungeon) {

        if(i >= dungeon.size() || j >= dungeon[0].size())
            return INT_MAX;

        // base case.
        if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            return dungeon[i][j] <= 0 ? 1 + (-(dungeon[i][j])): 1;
        }

        if(t[i][j] != -1)
            return t[i][j];

        int requiredHp = min(calculateMinimumHP(i+1, j, dungeon), calculateMinimumHP(i, j+1, dungeon)) - dungeon[i][j];

        // requiredHp <= 0 -> We have abs(requiredHp) blood but we need only 1 amount to live.
        // requiredHp <  0 -> Indicate that, still requiredHp is needed to be alive.
        return t[i][j] = (requiredHp <= 0 ? 1: requiredHp);

    }


    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        memset(t, -1, sizeof(t));

        return calculateMinimumHP(0, 0, dungeon);
    }
};




class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size(), n = dungeon[0].size();

        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        // base case
        dp[m-1][n-1] = dungeon[m-1][n-1] <= 0 ? 1 + (-(dungeon[m-1][n-1])) : 1;

        for(int i = m-1; i >= 0; i--) {

            for(int j = n-1; j >= 0; j--) {
                
                if(i == m-1 && j == n-1)
                    continue;

                int requiredHp = -(dungeon[i][j]);

                if(i + 1 < m && j + 1 < n) {
                   requiredHp += min(dp[i+1][j], dp[i][j+1]) ;
                }
                else if (i + 1 < m) {
                    requiredHp += dp[i+1][j];
                }
                else if (j + 1 < n) {
                    requiredHp += dp[i][j+1];
                }

                dp[i][j] = (requiredHp <= 0) ? 1 : requiredHp;
            }
        }

        return dp[0][0];
    }
};

