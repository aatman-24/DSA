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

1) Backtracking -> We can use the same element twice so pass the same Index for the next solve() call. In recursive
manner it follow DFS and for loop it follow BFS.

==============================> Apporach and Time Complexity <=============================================

1) Backtracking:
Time = O(2^N) -> 2 choice either add or not for n object.
Space = O(2^N)(all are combination sum)(2d Vector) + O(N) (single vector) + O(2^N)(Aux)

*/

class Solution {
public:

    vvi ans;
    int arr[31];
    int n;
    
    void solve(int currentIndex, int target, vector<int> &temp)
    {
        if(target == 0) 
            ans.push_back(temp);
        
        if(target < 0 || currentIndex == n) 
            return;

        for(int i = currentIndex; i < n; i++) {

            // If target is positive or zero then we can add otherwise not.
            if(C - arr[i] >= 0) {

                temp.push_back(arr[i]);
                solve(i, C - arr[i], temp);
                temp.pop_back();
            }
        }
    }
    
    // O(2^N * K) K = possible combination
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)     {
    
        n = candidates.size();
        for(int i = 0; i < n; i++) 
            arr[i] = candidates[i];
        
        vector<int> temp;

        // backtracking solution.
        solve(temp, target, 0);
    
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
