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

Question : 40. Combination Sum II
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/combination-sum-ii/

==============================> Explanation <=============================================

- Both are same.

Time = O(2^N * K) -> 2 choice either add or not for n object. K is total combination possible don't calculate direct
        varry with problem.
Space = O(K * X)(all are combination sum) + O(N) (single vector)


==============================> Edge Case <=============================================




*/

class Solution {
public:
 int arr[101];
    vvi ans;
    int N;

    void solve(vi &tmp, int index, int T)
    {
        if(T == 0) {ans.push_back(tmp); return;}
        if(T < 0 || index == N) return;

        for(int i = index; i < N; i++) {
            if(i > index && arr[i] == arr[i-1]) continue;
            if(T - arr[i] >= 0) {
                tmp.push_back(arr[i]);
                solve(tmp, i+1, T - arr[i]);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)     {
        ans.clear();
        N = candidates.size();
        for(int i = 0; i < N; i++) arr[i] = candidates[i];
        sort(arr, arr+N);
        vi tmp;
        solve(tmp, 0, target);   
        return ans;
    }
};


class Solution {
public:

    void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(target == 0) {
            ans.push_back(ds); 
            return;
        }

        for(int i = idx; i < N; i++) {

            // Avoid duplicates.
            if(i > idx && arr[i] == arr[i-1]) continue;
            
            if(arr[i] > target) break;

            if(target - arr[i] >= 0) {

                ds.push_back(arr[i]);
                solve(i+1, target - arr[i], arr, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)     {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};