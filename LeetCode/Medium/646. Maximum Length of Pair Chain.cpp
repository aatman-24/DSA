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
d
/*
==============================> Description <=============================================

Question : 646. Maximum Length of Pair Chain
Topic : Greedy, DP
Problems : https://leetcode.com/problems/maximum-length-of-pair-chain/
/*
==============================> Explanation <=============================================

- Overlapping Interval Problem. Here Need to count total Non-overlapping Interval.


452. Minimum Number of Arrows to Burst Balloons
- Same Solution. Just change array name.
- sort based on lowest end_time. Then skip all the overlap point but not change end_time.

[1, 4] [2, 5] -> overlapping.  then don't need [2,5].
[2,4] [1,5] -> overlapping. 

Why this works?
Consider pairA and pairB, where pairA appears before pairB in the sorted pairs.
That implies that pairA[1] < pairB[1], but there is no constraint on pairA[0] and pairB[0].
Now, the greedy part is: I claim that it's always better to try to add pairA to the chain first.


452. Minimum Number of Arrows to Burst Balloons <- Same
56 Merge Intervals <- very similar😈
435 Non-overlapping Intervals <- very similar😈
252 Meeting Rooms
253 Meeting Rooms II



2) Dynamic programming of LIS variants:

parent: 300. Longest Increasing Subsequence

1) Choise Diagram: If we are at current index i in the array. Then LIS[i] is the maximum among all,
                   numbers arr[j] such that, It can be extend all the LIS for which nums[j][1] < nums[i][0].
                   So that, reason LIS[i] = LIS[j] + 1. nums[j] < nums[i]. j can be (0 -> i).

2) Base Case: LIS[i] = 1. Every number itself is LIS.

3) Recurrence Relation: 
                    for j = 0 -> i,
                        if(nums[j][1] < nums[i][0])
                            LIS[I] = max(LIS[i], LIS[j]+1)


*/


/*
==============================> Apporach and Time Complexity <=============================================
1) DP, pattern=LIS:
Time:O(N^2)
Space:O(N)

2) Greedy + Time Interval:
Time: O(NlogN)
Space: O(1)

*/

// bottom-up..
// need top down check parent problem
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {


    // Each pair itself is LIS of length 1.
    vector<int> lis(pairs.size(), 1);

    sort(pairs.begin(), pairs.end());

    for(int i = 1; i < pairs.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(pairs[j][1] < pairs[i][0]) {
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < pairs.size(); i++) {
        ans = max(ans, lis[i]);
    }

    return ans;
}
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(), pairs.end(), [](vector<int> p1, vector<int> p2) {
            if(p1[1] == p2[1]) p1[0] < p2[0];
            return p1[1] < p2[1];
        });

        int count = 1;
        int end_time = pairs[0][1];

        for(int i = 1; i < pairs.size(); i++) {

            if(pairs[i][0] > end_time) {
                count++;
                end_time = pairs[i][1];
            }

        }

        return count;

    }

};