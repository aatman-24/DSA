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

Question:  1140. Stone Game II 
Topic : Top-Down Pattern=Stone Game
Problems : https://leetcode.com/problems/stone-game-ii/

==============================> Explanation <=============================================

- Idea is that, 

    - The current player always try to minimize the opponent score and maximizie own score.  
    - So we take the minimum score we got from the next player.
    - And subtract from the current total score(sum of piles[i: ])
    - That's how we got the maximum score. 

1) Choise Diagram: -> we can choose (1 <= i <= 2*M) ith piles together. And every time we set 
                      the piles, either it is min(M, i);

2) Base Case: index >= piles.size() -> 0
              2*M >= piles.size() - index then take all the piles...return sum[index].
              
3) Recurrance Relation:
            
              min_score = INT_MAX;
             for(int j = 1; j <= 2*M; j++)
                min_score = min(min_score, solve(index+j, max(M, j), sums))

             dp[index][M] = sum[index](max_score) - min_score

             return dp[index][M] 

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern=Stone Game
Time: O(N^2)
Space: O(N)

*/



class Solution {
public:
    int t[101][101];

    int stoneGameII(int index, int M, vector<int> &sums) {

        // No piles return 0.
        if(index >= sums.size())
            return 0;

        // If M is big such that we can took all the remaining piles then we did directly.
        if(2*M >= sums.size() - index)
            return sums[index];

        if(t[index][M] != -1)
            return t[index][M];

        // try to find minimum score can next player can get.
        int min_For_next_player = INT_MAX;

        for(int j = 1; j <= 2*M; j++) {
            min_For_next_player = min(min_For_next_player, stoneGameII(index+j, max(M, j), sums));
        }


        // current player maximum score
        t[index][M] = sums[index] - min_For_next_player;

        return t[index][M];
    }




    int stoneGameII(vector<int>& piles) {
        
        // base case.
        int N = piles.size();
        if(N == 1)
            return piles[0];
        
        // suffix sum.
        vector<int> sums(N, 0);
        sums[N-1] = piles[N-1];
        for(int i = N-2; i >= 0; i--)
            sums[i] = sums[i+1] + piles[i];

        memset(t, -1, sizeof(t));

        return stoneGameII(0, 1, sums);

    }
};