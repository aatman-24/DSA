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

Question : 39. Combination Sum
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/combination-sum/

==============================> Explanation <=============================================

- Both are same.

Time = O(2^N * K) -> 2 choice either add or not for n object. K is total combination possible don't calculate direct
        varry with problem.
Space = O(2^N)(all are combination sum)(2d Vector) + O(N) (single vector)


==============================> Edge Case <=============================================




*/

class Solution {
public:

    vvi ans;
    int arr[31];
    int n;
    
    void solve(vi &tmp, int C, int cIndex)
    {
        if(C == 0) ans.push_back(tmp);
        if(C < 0 || cIndex == n) return;

        for(int i = cIndex; i < n; i++) {
            if(C - arr[i] >= 0) {
                tmp.push_back(arr[i]);
                solve(tmp, C - arr[i], i);
                tmp.pop_back();
            }
        }
    }
    
    // O(2^N * K) K = possible combination
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        ans.clear();
        n = candidates.size();
        memset(arr, sizeof(arr), 0);
        for(int i = 0; i < n; i++) arr[i] = candidates[i];
        vi tmp;
        solve(tmp, target, 0);
        return ans;
    }
};



class Solution {
public:

    vvi ans;
    int arr[31];
    int n;
    
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> ans, vector<int> &ds) {
        if(ind == arr.size()) {
            if(target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // either add if it is possible
        if(arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back();
        }

        // or don't add. Jump to the next number.
        findCombination(ind+1, target, arr, ans, ds);

    }
    
    // O(2^N * K)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
