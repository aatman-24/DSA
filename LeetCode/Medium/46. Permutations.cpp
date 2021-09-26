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

Question : 46. Permutations
Topic : Array, Backtracking, permutations
Problems : https://leetcode.com/problems/permutations/

==============================> Explanation <=============================================


1) Backtracking with Used[]|visited[]:
- In this approach, start from i = 0 -> N. We add the ith number if it is not already taken and next time
we start from 0th index again. Backtrack On used[] and temp array.

2) Backtraking with Swapping:
- We try to put every element index from [i, n-1] at current index IDX. And in next call we try the same
things but at IDX+1.
Backtrack we again swap that already swapped element in the array.


Time = O(N!) * O(N) (For Loop) = O(N * N!)
Space = O(N)(DS) + O(N)(Visited) + O(N)(Auxiliary)



==============================> Apporach and Time Complexity <=============================================

1) Backtracking + Used:
Time: O(N * N!) (Total Call N! and each call O(N))
Space: O(N!)(Aux) + O(N)  

2) Backtracking + Swapping:
Time: O(N * N!) (Total Call N! and each call O(N))
Space: O(N!)(Aux)


*/

class Solution {
public:
    vvi ans;
    int arr[11];
    bool used[11];
    int N;

    void backtrackSubset(vi &tmp , int cIndex) {
        if(tmp.size() == N) {
            ans.push_back(tmp);
            return;
        }

        for(int i = 0; i < N; i++) {
            if(used[i] == 1) continue;
            tmp.push_back(arr[i]);
            used[i] = 1;
            backtrackSubset(tmp, i+1);
            tmp.pop_back();
            used[i] = 0;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        N = nums.size();
        memset(arr, 0, sizeof(arr));
        memset(used, 0, sizeof(used));
        for(int i = 0; i < N; i++) arr[i] = nums[i];
        vi tmp;
        backtrackSubset(tmp, 0);
        return ans;  
    }
};




class Solution {
public:

    void recurPermute(vector<int> &nums, vector<int> &ds, int visited[], vector<vector<int>> ans) {
        if(ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!visited[i]) {
                ds.push_back(nums[i]);
                visited[i] = 1;
                recurPermute(nums, ds, visited, ans);
                visited[i] = 0;
                ds.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int visited[nums.size()] = {0};
        recurPermute(nums, ds, visited, ans);
        return ans;
    }
};


// Optimized NO Extra Space.

// Time = 
// Space = O(N)(Auxiliary)
class Solution {
public:

    void recurPermute(int idx, vector<int> &nums, vector<vector<int>> ans) {
        if(nums.size() == idx) {
            ans.push_back(nums);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            swap(nums[i], nums[idx]);

            recurPermute(idx+1, nums, ans);
            
            // Backtrack.
            swap(nums[i], nums[idx]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};
