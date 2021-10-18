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

Question: 1626. Best Team With No Conflicts
Topic : Bottom-Up Pattern=LIS
Problems : hhttps://leetcode.com/problems/best-team-with-no-conflicts/

==============================> Explanation <=============================================
- Dp variant = LIS,

- sort the player based on age in decreasing order. So now we don't need to consider age
restriction. 

- Exapnd the best oldMan score from (0 -> i-1). If we are at current i.

==============================> Apporach and Time Complexity <=============================================

1) Bottom-Up Pattern=Bounded Knapsack
Time: O(N^2)
Space: O(N^2)

*/



class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<pair<int, int>> players;
        
        int n = scores.size();
        
        for (int i=0; i<n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        
        sort(players.begin(), players.end(), greater<>());
        
        int ans = 0;
        
        vector<int> dp(n);

        for (int i=0; i<n; i++) {
        
            int score = players[i].second;
            
            dp[i] = score;
        
            for (int j=0; j<i; j++) {
                //  age of j is certainly >= i, so only important part to check 
                //  before we add i and j in the same team is the score.
                // jth(older) score more than or equal to younger or not.
                if (players[j].second >= players[i].second) { 
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};