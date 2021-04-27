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
    
    // O(2)
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