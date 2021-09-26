
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

1) Backtracking -> Here we can not use the same element twice so if we add the current 
element at ith index then go to next index i+1. 

Duplication not allowed. How to handle this ?
- First sort the array.
- As per the recurion tree,
    If we performing the BFS that time if nums[i] == nums[i-1] then we don't start DFS from the ith because
    already the (i-1) store the answer so doing from the ith same result we got.


    1 1 1 1 2 3 -> target = 4.
    
    0th index have one of solution = [1, 3]. So After 0th index (1, 2, 3) can also have [1, 3] so avoid that, we
    make the restriction on DFS call while performing BFS(on Loop).

    We can have solution [1, 1, 1, 1] So that reson restiriction on BFS(Loop) not on Depth.

                0
             /  R  R  R    
            1   2   3  4
          /
         2
        /
       3
     /
    4 
    

    - In short, if the previous number is same in level then don't start the new branch from that index.
    It make the duplication in answer.

==============================> Apporach and Time Complexity <=============================================

1) Backtracking:
Time = O(2^N) -> 2 choice either add or not for n object.
Space = O(2^N)(all are combination sum)(2d Vector) + O(N) (single vector) + O(2^N)(Aux)

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

            // Avoid Duplicate. Not Start new Branch from Here. Duplicate subarray is not allowed.
            if(i > index && arr[i] == arr[i-1]) continue;

            if(T - arr[i] >= 0) {
                tmp.push_back(arr[i]);

                // Here we go the next element. Same element is not allowed.
                solve(tmp, i+1, T - arr[i]);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)     {
        
        N = candidates.size();
        for(int i = 0; i < N; i++)
            arr[i] = candidates[i];
        
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