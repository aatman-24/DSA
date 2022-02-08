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

Question : 241. Different Ways to Add Parentheses
Topic : DPPattern=IntervalDP, Backtracking...
Problems : https://leetcode.com/problems/different-ways-to-add-parentheses/

==============================> Explanation <=============================================

For the given expression,

- we divide the expression in subexpression using help of operator...

    expr1 operator expr2

- evaluate left expr1 on its own and right on its own.

- After that we perform evaluation of current expression by peforming... 

    for lf in lftEvaluation:
        for rf in rhtEvaluation:
            add into result lf operator rf
    
    return result.

- We can use the memo table for don't evaluate the expression which is already evaluate...

==============================> Apporach and Time Complexity <=============================================

1) Two Pointer
Time: O(2^N) -> O(N^2)
Space: O(N^2) (maximum possible)

*/

class Solution {

    public:

    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string s) {

        // number is left.
        if(s.size() <= 2) {
            return memo[s] = {stoi(s)};
        }

        if(memo.count(s)) {
            return memo[s];
        }

        vector<int> ans;

        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '*') {

                string leftExpression = s.substr(0, i);
                string rightExpression = s.substr(i+1, s.size());

                vector<int> left = diffWaysToCompute(leftExpression);
                vector<int> right = diffWaysToCompute(rightExpression);

                for(int num1: left) {
                    
                    for(int num2: right) {

                        if(s[i] == '+') {
                            ans.push_back(num1 + num2);
                        }
                        else if(s[i] == '-') {
                            ans.push_back(num1 - num2);
                        }   
                        else {
                            ans.push_back(num1 * num2);
                        }

                    }
                }
            }
        }

        return memo[s] = ans;
    }
};