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

Question: 508. Most Frequent Subtree Sum
Topic : Hashing
Problems : https://leetcode.com/problems/most-frequent-subtree-sum/

==============================> Explanation <=============================================

- Recursion With Map. Same as Depth of the tree.

==============================> Apporach and Time Complexity <=============================================
1) BruteForce: 
Time: O(N^2)
Space: O(1)

2) HashMap:
Time: O(N)
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

    unordered_map<int, int> sumToFreq;
    int maxFrequency = 0;

    int sumOfSubTree(TreeNode* root) {

        int sum = 0;

        if(root == nullptr)
            return 0;

        sum += sumOfSubTree(root -> left);
        sum += sumOfSubTree(root -> right);
        sum += root -> val;

        sumToFreq[sum]++;
        if(sumToFreq[sum] > maxFrequency)
            maxFrequency = sumToFreq[sum];

        return sum;
    }



    vector<int> findFrequentTreeSum(TreeNode* root) {

        sumOfSubTree(root);

        vector<int> answer;
       
        // Get all most Frequent Sum.
        for(auto it: sumToFreq) {
            if(it.second == maxFrequency)
                answer.push_back(it.first);
        }

        return answer;
    }
};