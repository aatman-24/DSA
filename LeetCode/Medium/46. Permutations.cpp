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