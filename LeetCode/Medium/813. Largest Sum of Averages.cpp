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

Question:  813. Largest Sum of Averages
Topic :Top-Down  Pattern= MultiDimesional DP, MCM
Problems : https://leetcode.com/problems/largest-sum-of-averages/

==============================> Explanation <=============================================
- Dp variant = MultiDimesional DP, MCM.

- I used MCM varinats. Try to make the cut at every index until possible. And we don't make the more than given cut
so last whatever is remaining we directly take the avg of that array.

- Whatever left array is got from the cut is final array we don't make more partition on it.
- In right if cut > 1 then we still have (cut-1) choice to make partition so we choose from that.
- And overall which ever cut give the max average we return that.

1) Choise Diagram: 
            - Make the cut at every where if available from [i, j].
            - On the left side direct calculate the average (cut = 0)
            - and on right side still have (cut-1) paritition possible so use that find maximum among them.

2) Base Case: i > j -> return 0.
              i == j -> return nums[i]
              cut == 0 -> average of num[i..j].     // if we don't want to count every time we can use prefix sum to get direct.
              
3) Recurrance Relation:
    
        try to make cut every where between [i, j].
        for(int k = i; k <= j; k++) {
            ans = max(ans, solve(i, k, 0) + solve(k+1, j, cut-1));
        }

==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern= MCM
Time: O(N^3)
Space: O(N^3)

*/

// Using MCM approach.
class Solution {
public:

    double largestSumOfAverages(int i, int j, int cut, vector<int> &nums, double t[][101][101]) {

        // base case
        if(i > j)
            return 0.0;

        // single number.
        if(i == j)
            return (double)nums[i];

        // base case. (cut == 0) direct calculate the sum.
        if(cut == 0) {
            double sum = 0.0;
            for(int p = i; p <= j; p++)
                sum += nums[p];
            sum = sum/(j-i+1);
            return t[cut][i][j] = sum;
        }

        if(t[cut][i][j] != -1)
            return t[cut][i][j];
        
        double maxAvg = 0;
        // try to make the cut from [i, j].
        
        // on left we don't make any others cut, cut = 0 (if we use cut-1 there, then total partition increase.)
        // even left part direct calculate the average of the [i..k] in nums.

        // on right we use (cut-1) because still we have some cut to make.
        for(int k = i; k <= j; k++) {
            maxAvg = max(maxAvg, largestSumOfAverages(i, k, 0, nums, t) + largestSumOfAverages(k+1, j, cut-1, nums, t));
        }

        return t[cut][i][j] = maxAvg;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {

        double t[101][101][101];
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                for(int k = 0; k < 101; k++) {
                    t[i][j][k] = -1.0;
                }
            }
        }


        // k - 1.. Because k = 1, Means entire array so based on that logic. I used it.
        return largestSumOfAverages(0, nums.size()-1, k-1, nums, t);
    }
};