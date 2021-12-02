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

Question:  486. Predict the Winner
Topic : Top-Down Bottom-up Pattern=GamePlay
Problems : https://leetcode.com/problems/predict-the-winner/

==============================> Explanation <=============================================
- Dp variant = Game Play-Min,Max.


1) Choise Diagram: current array is from [i, j] with our turn.
            1) I choose ith,
                - For the next player array is [i+1, j]
                    a) he could choose (i+1)th   -> our array is (i+2, j)
                    b) he could choose (j)th     -> our array is (i+1, j-1)

            2) I choose jth,
                - For the next player array is [i, j-1]
                    a) he could choose (i)th   -> our array is (i+1, j)
                    b) he could choose (j-1)th     -> our array is (i, j-2)

As we know both player must be play in optimal way,

So we try to maximize our score, so opponent are also doing same things,

1st turn -> Our
2nd turn -> You
3rd turn -> Our.


So when we are at 3rd turn to choose the best possible move, "You" Player choose the one of the maximize
score move in 2nd turn so we got the minimum in 3rd turn.


curScore = max(nums[i] + min(PredictTheWinner(i+2,j, nums), PredictTheWinner(i+1,j-1, nums)), 
    nums[j]+  min(PredictTheWinner(i+1,j-1, nums), PredictTheWinner(i,j-2, nums)));

1st Turn Choose maximum + 3rd turn choose minimum. Because In 2nd turn Player "You" must choose maximum
score move.



2) Base Case: i > j return 0.
              i == j return 0.
              
3) Recurrance Relation:
                

curScore = max(nums[i] + min(PredictTheWinner(i+2,j, nums), PredictTheWinner(i+1,j-1, nums)), 
    nums[j]+  min(PredictTheWinner(i+1,j-1, nums), PredictTheWinner(i,j-2, nums)));              


Check this one also :
https://leetcode.com/problems/predict-the-winner/discuss/96828/JAVA-9-lines-DP-solution-easy-to-understand-with-improvement-to-O(N)-space-complexity.

==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=GamePlay
Time: O(N^2)
Space: O(N^2)

*/


class Solution {
public:
    int t[21][21];

    int PredictTheWinner(int i, int j, vector<int> &nums) {

        if(i > j)
            return 0;

        if(i == j)
            return nums[i];

        if(t[i][j] != -1)
            return t[i][j];

        int curScore = max(nums[i] + min(PredictTheWinner(i+2,j, nums), PredictTheWinner(i+1,j-1, nums)), 
                           nums[j]+  min(PredictTheWinner(i+1,j-1, nums), PredictTheWinner(i,j-2, nums)));

        return t[i][j] = curScore;
    }                       



    bool PredictTheWinner(vector<int>& nums) {

        memset(t, -1, sizeof(t));
        int total = 0;
        for(auto num: nums)
            total += num;

        int scoreFirstOne = PredictTheWinner(0, nums.size()-1, nums);

        return scoreFirstOne >= total - scoreFirstOne;
    }

};