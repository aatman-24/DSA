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

Question:  1155. Number of Dice Rolls With Target Sum
Topic : Top-Down Bottom-up Pattern=MultiDimesional DP
Problems : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

==============================> Explanation <=============================================
- Dp variant = MultiDimesion DP, 

- First Intuition is that, 

    - We try all the face one by one and whatever target is remaining(target-face) is got from
    the previous level.

    Ex... Face = 5, Dice = 2, Target = 6.

    F(D, F, Target)


    F(2, 5, 6) = F(1, 5, 5)  
               + F(1, 5, 4)
               + F(1, 5, 3)
               + F(1, 5, 2)
               + F(1, 5, 1)

    And return it.


1) Choise Diagram: -> Choose Every face one by one and try to get the answer from the previous
                      level with remaining target.

2) Base Case: Target == 0 -> Return 0. (No dice have 0 face)
              Dice == 1 -> Target -> [1, F] return 1.
              
3) Recurrance Relation:
            
            for(int face = 1; face <= f; face++) 
                dp[dice][target] += dp[dice-1][target-face]


Here, Notice that (only target and dice(level) is changed, face is not the state.) Yes you can
add but it is unnecessary.

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Bottom-up Pattern=MultiDimesional DP
Time: O(Dice*Target)
Space: O(Dice*Target)

*/

#define mod 1000000007

class Solution {
public:

    long t[31][1001];

    long numRollsToTargetSolve(int d, int f, int target) {

        // No dice have face 0. return 0. (Not possible)
        // if you throw any number of dice, each dice must have number between [1, f].
        if(target == 0)
            return 0;
        
        // for single dice...If target is between [1, f] then we return 1.
        if(d == 1) {
            return int(target > 0 && target <= f);
        }

        if(t[d][target] != -1)
            return t[d][target];

        // count total ways.
        long ways = 0;

        for(int i = 1; i <= f; i++) {

            // If the dice face has value less than target.
            if(i <= target)
                ways += numRollsToTargetSolve(d-1, f, target-i) % mod;
        }

        return t[d][target] = ways % mod;
    }


    int numRollsToTarget(int d, int f, int target) {

        memset(t, -1, sizeof(t));

        return (int)numRollsToTargetSolve(d, f, target);
    }
};





#define mod 1000000007

class Solution {
public:

    long t[31][1001];

    long numRollsToTargetSolve(int d, int f, int target) {
        
        // for single dice...If target is between [1, f] then we return 1.
        if(d == 1) {
            return int(target > 0 && target <= f);
        }

        if(t[d][target] != -1)
            return t[d][target];

        // count total ways.
        long ways = 0;

        for(int i = 1; i <= f; i++) {

            // If the dice face has value less than target.
            
            // Why ? i == target not added.
            // No dice has face 0.
            // If you throw any number of dice, each dice must have number between [1, f].
            if(i < target)
                ways += numRollsToTargetSolve(d-1, f, target-i) % mod;
        }

        return t[d][target] = ways % mod;
    }


    int numRollsToTarget(int d, int f, int target) {

        memset(t, -1, sizeof(t));

        return (int)numRollsToTargetSolve(d, f, target);
    }
};





#define mod 1000000007

class Solution {
public:

       int numRollsToTarget(int d, int f, int target) {

        long dp[31][1001] = {0};
           
        // when dice = 1, any face is between [1, f] then there is one way to make target.
        for(int i = 1; i <= f; i++) {
            dp[1][i] = 1;
        }

        for(int dice = 2; dice <= d; dice++) {
            for(int j = 1; j <= target; j++) {
                for(int face = 1; face <= f; face++) {
                    if(face <= j) {
                        dp[dice][j] = (dp[dice][j] % mod) + (dp[dice-1][j-face] % mod) % mod;
                    }
                }
            }
        }

        return dp[d][target] % mod;
    }
    
};