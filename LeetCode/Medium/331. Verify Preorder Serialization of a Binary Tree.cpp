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
d
/*
==============================> Description <=============================================

Question : 331. Verify Preorder Serialization of a Binary Tree
Topic :BT
Problems : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

==============================> Explanation <=============================================
Either Current Root Node we found the LinkedList. 
But once this is triggered we keep increase pointer for the left and right child and LL. Or If value
don't match we return false.


If not then it is possible we foudn on its left or right child.

*/


/*
==============================> Edge Case <=============================================


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    

    void preorder_traversal(vector<string> s, int &i) {

        if(i > s.size() - 1)
            return;

        if(s[i] == "#")
            return;

        preorder_traversal(s, ++i);

        preorder_traversal(s, ++i);
    }

    // TLE Don't know why.
    bool isValidSerialization(string preorder) {

        vector<string> arr;
        stringstream ss(preorder);
        string temp;
        while(getline(ss, temp, ',')) {
            arr.push_back(temp);
        }

        int index = 0;

        preorder_traversal(arr, index);

        return arr.size() - 1 == index;
    }




    // Iterative Work well.
    bool isValidSerialization(string preorder) {

        vector<string> arr;
        stringstream ss(preorder);
        string temp;
        while(getline(ss, temp, ',')) {
            arr.push_back(temp);
        }


        // For Base Condition when tree contain single null node.
        int credit=1;
        for(string pre: arr){

            // If array goes to either left or right, decrease the credit by one.
            if(--credit<0) return false;

            // And some not null found which means it must have two child either not null or null.
            // so increase the credit.
            if(pre!="#") credit+=2;
        }

        // Check credit is zero or not. Because we add 2 credit for every not null node. And 
        // Subtract 1 when we reach to the child node. So overall it must be zero.
        return credit==0;

    }



};