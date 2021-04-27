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

Question : 47. Permutations II
Topic : Array, Backtracking, permutations
Problems : https://leetcode.com/problems/permutations-ii/
*/

class Solution {
public:

    vvi ans;
    int arr[11];
    bool used[11];
    int N;

    void backtrackPermute(vi &tmp) {
        if(tmp.size() == N) {
            ans.push_back(tmp);
            return;
        }

        for(int i = 0; i < N; i++) {
           if(used[i] == 1) continue;

           // We never going to start with the same number (arr[i] == arr[i-1]) when arr[i] is not in use.
           if(i > 0 && arr[i] == arr[i-1] && (used[i-1] == 0)) continue;  
            used[i] = 1;
            tmp.push_back(arr[i]);
            backtrackPermute(tmp);
            tmp.pop_back();
            used[i] = 0;
        }


    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        N = nums.size();
        memset(arr, 0, sizeof(arr));
        memset(used, 0, sizeof(used));
        for(int i = 0; i < N; i++) arr[i] = nums[i];
        sort(arr, arr+N);
        vi tmp;
        backtrackPermute(tmp);
        return ans;  
    }
};