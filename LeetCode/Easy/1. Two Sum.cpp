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
d
/*
==============================> Description <=============================================

Question : 1. Two Sum
Topic : Two Pointer, Hashing
Problems : https://leetcode.com/problems/two-sum/

==============================> Explanation <=============================================

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    // 1 Brute Foce -> O(N^2)

    // 2 Optimal (Extra Space) -> O(N) + O(N)
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            if(mp.find(target-nums[i]) != mp.end()) {
                
                return {mp[target-nums[i]], i};
            }
            
            mp[nums[i]] = i;
        }


        return {-1,-1};

    }



    // 3 Optimal N*logN Sort and One pass. But using this we can only check the
    // target can be made by two element or not.
};