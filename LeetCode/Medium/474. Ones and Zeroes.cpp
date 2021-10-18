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

Question: 474. Ones and Zeroes
Topic : Top-Down Bottom-up Pattern=Bounded Knapsack
Problems : https://leetcode.com/problems/ones-and-zeroes/

==============================> Explanation <=============================================
- Dp variant = Unbounded Knapsack,

- Actually Idea is very staright forward to use Unbounded Knapsack...

- Either we pick up or don't pick up. 

- State is presented by three parameter (index, m, n)

2) Base Case:
- At every step, N = 0 -> Return 0. No subset. 

3) Recurrance Relation: 
    j and k are running on the m and n.

-   if(arr[i-1].first <= j && arr[i-1].second <= k):
        dp[i][j][k] = dp[i-1][j-arr[i-1].first][k-arr[i-1].second] + dp[i-1][j][k];
    else:
        dp[i][j] = dp[i-1][j][k]


==============================> Apporach and Time Complexity <=============================================

1) Bottom-up Pattern=Bounded Knapsack
Time: O(N*M)
Space: O(N*M)

*/


class Solution {
    
public:
    
    int t[601][101][101];

    pair<int,int> countZeroAndOne(string s) {

        int zero = 0, one = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
                zero++;
            else
                one++;

        return make_pair(zero, one);
    }


    int findMaxForm(int idx, int m, int n, vector<pair<int,int>> &arr) {

        if(idx == 0)
            return 0;
        
        if(t[idx][m][n] != -1)
            return t[idx][m][n];

        int largest = 0;
        
        if(arr[idx-1].first <= m && arr[idx-1].second <= n) {  
            largest = max(findMaxForm(idx-1, m, n, arr), findMaxForm(idx-1, m - arr[idx-1].first, n - arr[idx-1].second, arr) + 1);
        }
        else {
            largest = findMaxForm(idx-1, m, n, arr);
        }

        return t[idx][m][n] = largest;
    }


    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int,int>> arr;
            
        memset(t, -1, sizeof(t));
        
        for(auto str: strs) {
            arr.push_back(countZeroAndOne(str));
        }
        
        return findMaxForm(arr.size(), m, n, arr);
    }
};



class Solution {
    
public:
    
    pair<int,int> countZeroAndOne(string s) {

        int zero = 0, one = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '0')
                zero++;
            else
                one++;

        return make_pair(zero, one);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int,int>> arr;
        
        for(auto str: strs) {
            arr.push_back(countZeroAndOne(str));
        }

        // State is represented by three 
        int dp[arr.size()+1][m+1][n+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= arr.size(); i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k <= n; k++) {
                    if(arr[i-1].first <= j && arr[i-1].second <= k) {
                        dp[i][j][k] = max(dp[i-1][j-arr[i-1].first][k-arr[i-1].second] + 1, dp[i-1][j][k]);
                    }
                    else {
                        dp[i][j][k] = dp[i-1][j][k];
                   }
                }
            }
        } 

        return dp[arr.size()][m][n];
    }
};