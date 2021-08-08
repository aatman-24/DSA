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

Question : 945. Minimum Increment to Make Array Unique
Topic : Greedy
Problems : https://leetcode.com/problems/minimum-increment-to-make-array-unique/submissions/

==============================> Explanation <=============================================
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // O(N) + O(N). 
    // map store the number -> position.  for the non duplicate number it is number -> number.
    // so differnce is 0. But duplicate number we store the number + 1... like that.
    // After that all are relative to each other.
    int minIncrementForUnique(vector<int>& nums) {
        unordered_map<int, int> root;
        int minIncrementForUnique(vector<int>& A) {
            int res = 0;
            for (int a : A)
                res += find(a) - a;
            return res;
        }
    }

    // Good. when duplicate found again made the call find(root[x]+1). and store the root[x] + 1 for
    // the first duplicate. for second find[root[x] + 2] by calling two times.
    int find(int x) {
        return root[x] = root.count(x) ? find(root[x] + 1) : x;
    }




    // O(NlogN) + O(1)
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int minimumCost = 0;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] <= nums[i-1]) {

                int actual = nums[i];
                nums[i] = nums[i-1] + 1;
                minimumCost += nums[i] - actualCurr;
            }

        }

        return minimumCost;
    }
};