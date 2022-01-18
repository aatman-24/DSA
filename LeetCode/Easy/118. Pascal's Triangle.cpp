#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question: 118. Pascal's Triangle
Topic : DP, Bottom-Up
Problems : https://leetcode.com/problems/pascals-triangle/

==============================> Explanation <=============================================

Base Case: N = 1. Single Entry {{1}}

N != 1. Add 1 as Guard For Each Row. And between of guard is sum of above row.

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(N*M) -> N = Number of Rows Given, M = N. -> O(N^2)
Space: O(1)

*/

class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>> ans;

        while(n--) {

            int m = ans.size();
            vector<int> temp;

            // First Entry must be single 1.
            if(m == 0) {
                temp.push_back(1);
            }
            else {

                // Add First 1 into each row.
                temp.push_back(1);

                for(int i = 0; i < ans[m-1].size() - 1; i++) {
                    temp.push_back(ans[m-1][i] + ans[m-1][i+1]);
                }

                // Add Last 1 into each row.
                temp.push_back(1);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};


// Refactor above code.
class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>> ans;

        while(n--) {

            int m = ans.size();
            vector<int> temp;
            temp.push_back(1);

            if(m != 0) {

                for(int i = 0; i < ans[m-1].size() - 1; i++) {
                    temp.push_back(ans[m-1][i] + ans[m-1][i+1]);
                }

                temp.push_back(1);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
