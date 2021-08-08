#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

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

Question : 55. Jump Game
Topic : DP, BFS, Greedy, Array
Problems : https://leetcode.com/problems/jump-game/
/*
==============================> Explanation <=============================================

45. Jump Game II -> Needs to find minimum number of jump to reach the last index.


So same logic we just keep track of how much fartherst we can go using jump. But 
If any time if we reach at i and i > curFarthest that means we can not even reach to
the ith index. so we can not reach at end.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {

public:

    // O(N) - O(1)
    bool canJump(vector<int>& nums) {
        
        int curFarthest = 0;

        for(int i = 0; i < nums.size(); i++) {

            // If any time our i > curFarthest means that we can not even reach to the i so
            // we break the loops.
            if(i > curFarthest) break;

            // Only allow to use the nums[i] to go further if i <= curFarthest.
            curFarthest = max(curFarthest, i + nums[i]);
        }

        return curFarthest >= nums.size() - 1;

    }

};
