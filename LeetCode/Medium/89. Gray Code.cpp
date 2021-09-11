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

Question: 89. Gray Code
Topic : Math
Problems : https://leetcode.com/problems/gray-code/

==============================> Explanation <=============================================
N = 1 -> 0 
         1
 
N = 2 -> 00
         01
    --------------
         11
         10

It is just copy of previous(N-1) and adding Extra bit as 1 into that. 


==============================> Apporach and Time Complexity <=============================================

1) Maths & Logic:
Time: O(2^N) -> (Set All the Bits one by one upto the number 2^N.) 
Space: O(1)

*/



class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; i++) {
            int size = ans.size();
            for(int j = size - 1; j >= 0; j--) {

                // Set the ith bit.
                ans.push_back((ans[j] | 1 << i));
            }
        }
        return ans;
    }
};