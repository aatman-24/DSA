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

Question : 1310. XOR Queries of a Subarray
Topic : Prefix Sum
Problems : https://leetcode.com/problems/insertion-sort-list/
*/

/*
==============================> Edge Case <=============================================
when we perform xor for given query,
(i,j) query

if i == 0 then need to handle case. Don't need to perform xor with arr[i-1].
*/


/*
==============================> Explanation <=============================================
xor of same value is 0.
*/

class Solution {
public:


    // METHOD 1: O(N*K) Use for loop for given k queries(i -> j)


    // O(N) - O(1)
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); i++) 
            arr[i] = arr[i-1] ^ arr[i];

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int queryAns = arr[queries[i][1]];
            if(queries[i][0] - 1 >= 0)
                queryAns ^= arr[queries[i][0] - 1];
            ans.push_back(queryAns);
        }
        return ans;
    }

};