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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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
Topic : Array
Problems : https://leetcode.com/problems/subsets/
*/


class Solution {
public:
    vvi res;

    // O(2^N). - 4MS.
    void recursiveSubset(vi num, vi run, int cI) {
        if(cI == num.size()) return;
        recursiveSubset(num, run, cI+1);
        run.push_back(num[cI]);
        res.push_back(run);
        recursiveSubset(num, run, cI+1);
    } 
    vvi subsets(vector<int>& nums) {
           res.clear();
           recursiveSubset(nums, {}, 0);
           res.push_back({});
           return res;     
    }

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
    
    // O(2^N). - 0MS
    void backtrack(vi num, vi run, int cI, vvi &res) {
        res.push_back(run);

        for(int i = cI; i < num.size(); i++) {
            run.push_back(num[i]);
            backtrack(num, run, i+1, res);
            run.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vvi res;
       backtrack(nums, {}, 0, res);
       return res;   
    }

};
