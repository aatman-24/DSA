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

Question: 77. Combinations
Topic : Backtracking
Problems : https://leetcode.com/problems/combinations/

==============================> Explanation <=============================================
1) Interview perspective you can say bit manipulation method of generating subset.
    - go from (1 to 1 << n)
    - check how many bit is set. If it is k then add all the related element into the vector.
        and push into the answer.



2) Backtracking
- Easy and optimized.


==============================> Apporach and Time Complexity <=============================================

1) Bit manipulation subset generation:
Time: O(N * 2^N)
Space: O(N)

2) Backtracking:
Time: O(2^N) (Take the element or not to take).
Space: O(N)(Aux) + O(N)(temp)

*/

class Solution {
public:

    vector<vector<int>> answer;

    void backtrack(int start, int n, int k, vector<int> &cur) {
        if(cur.size() == k) {
            answer.push_back(cur);
            return;
        }
        for(int i = start; i <= n; i++) {
            cur.push_back(i);
            backtrack(i+1, n, k, cur);
            cur.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        backtrack(1, n, k, arr);
        return answer;
    }
};