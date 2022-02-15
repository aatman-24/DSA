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

Question : 318. Maximum Product of Word Lengths
Topic : String, Bit Manipulation
Problems : https://leetcode.com/problems/maximum-product-of-word-lengths/

==============================> Explanation <=============================================

- Simple make the mask of given word, only lowercase allowed so it is easy to make.

- After mask1 & mask2 == 0, no common character.

==============================> Apporach and Time Complexity <=============================================

1) String, Bit Manipulation
Time: O(N*M) + O(N^2)
Space: O(N)

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {

public:

    int maxProduct(vector<string>& words) {
    
        int N = words.size();

        if(N <= 1)
            return 0;

        // store the mask of words.
        vector<int> arr(N, 0);

        for(int i = 0; i < N; i++) {

            string str = words[i];

            int mask = 0;

            // make mask.
            for(int j = 0; j < str.size(); j++) {

                mask |= 1 << int(str[j]-'a');
            }

            arr[i] = mask;
        }


        int ans = 0;
        for(int i = 0; i <N; i++) {
            for(int j = i + 1; j < N; j++) {

                // if mask1 & mask2 == 0, means no common character.
                if((arr[i] & arr[j]) == 0) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return ans;
    }
};