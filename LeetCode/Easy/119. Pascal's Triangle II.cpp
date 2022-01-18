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

Question: 119. Pascal's Triangle II
Topic : DP, Bottom-up
Problems : hhttps://leetcode.com/problems/pascals-triangle-ii/

==============================> Explanation <=============================================

Same as 118. Pascal's Triangle

But in place of all rows here we need to return single nth row. So rathar than storing all the values into 
2D array we can just keep track of prvious row. 

==============================> Apporach and Time Complexity <=============================================

1) DP Bottom-Up
Time: O(N)
Space: O(N)

*/

// 118. Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>> ans;

        while(n--) {

            int m = ans.size();
            vector<int> temp;

            if(m == 0) {
                temp.push_back(1);
            }
            else {

                temp.push_back(1);

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



// Here Only Need Single Row.
class Solution {
public:
    vector<int> getRow(int n) {
        
        vector<int> ans;
        ans.push_back(1);

        if(n == 0) {
            return ans;
        }

        while(n--) {

            int m = ans.size();
            vector<int> temp;
            temp.push_back(1);

            if(m != 0) {

                for(int i = 0; i < ans.size() - 1; i++) {
                    temp.push_back(ans[i] + ans[i+1]);
                }

                temp.push_back(1);
            }

            ans = temp;
        }

        return ans;
    }
};