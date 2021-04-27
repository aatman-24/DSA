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

Question : 216. Combination Sum III
Topic : Array, Recursion, Backtracking
Problems : https://leetcode.com/problems/combination-sum-iii/
*/


class Solution {
public:
    
    vvi result;
    

    // O(9^K)
    void backtrack(int k, int n, vi tmp, int cNum) {
        if(n == 0 && k == 0) {
            result.push_back(tmp);
            return;
        }
        if(n < 0 || k <= 0) return;

        for(int i = cNum; i <= 9; i++) {
            if(i <= n) {
                tmp.push_back(i);
                backtrack(k-1, n -i, tmp, i+1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
       vi tmp;
       solve(k,n,tmp,1);
       return result;     
    }

};
