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

==============================> Explanation <=============================================
Backtracking: Same as, 40. Combination Sum II
array = [1, 2, .. 9] is fixed
And restriction that must use k distinct number which sum to the N.

- Means no element can be repeated in subarray.
- No subarray(combination) can be repeated.

Here, Number is disitinct(1, 9) so first and second both cases are handled automatically.


==============================> Apporach and Time Complexity <=============================================
N = 9.
1) Backtracking:
Time = O(2^N) -> 2 choice either add or not for 9 object.
Space = O(2^N)(all are combination sum)(2d Vector) + O(N) (single vector) + O(2^N)(Aux)

*/



class Solution {
public:
    
    vvi result;
    
    void backtrack(int k, int sum, vi tmp, int cNum) {

        // If sum = 0 and k = 0 means we use the k element which sum is Given K.
        if(sum == 0 && k == 0) {
            result.push_back(tmp);
            return;
        }

        // If above condition is not true and k <= 0, or sum is negative means we can not make it zero. 
        if(sum < 0 || k <= 0) return;

        for(int i = cNum; i <= 9; i++) {

            if(i <= sum) {
                
                tmp.push_back(i);

                backtrack(k-1, sum-i, tmp, i+1);
                
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
