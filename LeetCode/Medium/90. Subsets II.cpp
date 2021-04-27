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

Question : 90. Subsets II
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/subsets-ii/
*/

class Solution {
public:
    vvi ans;
    int arr[11];
    int N;


    void backtrackSubset(vi &tmp , int cIndex) {
        ans.push_back(tmp);
        if(cIndex == N) return;
        for(int i = cIndex; i < N; i++) {
            if(i > cIndex && arr[i] == arr[i-1]) continue; // skip the duplicates
            tmp.push_back(arr[i]);
            backtrackSubset(tmp, i+1);
            tmp.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        N = nums.size();
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < N; i++) arr[i] = nums[i];
        sort(arr, arr+N);
        vi tmp;
        backtrackSubset(tmp, 0);
        return ans;    
    }
};