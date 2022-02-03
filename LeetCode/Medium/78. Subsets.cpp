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

Question : 78. Subsets
Topic : Array, Backtracking
Problems : https://leetcode.com/problems/subsets/

==============================> Explanation <=============================================
1) Proper Backtracking:

- Either add or don't add each element. O(2^N)


2) Iterative:

- For current_num -> n... we add n each of the previous vector..


Exmaple...

{}, {1}, {2}, {1, 2}


for 3,


{3}, {1, 3}, {2, 3}, {1, 2, 3}

Add all into the main.....


{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}



==============================> Apporach and Time Complexity <=============================================

1) Backtracking Recursion
Time: O(2^N)
Space: O(N)


1) Backtracking Iterative
Time: O(2^N)
Space: O(1)


*/


class Solution {
public:
   
   void backtrack(vector<int> &nums, int startFrom, vector<int> &store, vector<vector<int>> &ans) {

        ans.push_back(store);

        for(int i = startFrom; i < nums.size(); i++) {

            store.push_back(num[i]);

            backtrack(nums, i+1, store, ans);

            store.pop_back();
        }

   }


    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> store;

        vector<vector<int>> ans;

        backtrack(nums, 0 , store, ans);
    }
};




class Solution {
public:

    // O(2^N). - 0MS
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi res;
        res.push_back({});
        for(int n : nums) {
            int size = res.size();
            for(int j = 0; j < size; j++) {
                vi subset(res[j]);
                subset.push_back(n);
                res.push_back(subset);
            }
        }
        return res;   
    }
    
};