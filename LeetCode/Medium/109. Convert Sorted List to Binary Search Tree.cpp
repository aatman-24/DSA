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

Question :  109. Convert Sorted List to Binary Search Tree
Topic :BST
Problems : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

==============================> Explanation <=============================================
Choose the middle element always as current node. It always return height-balanced binary search tree.

follow-up = 108. Convert Sorted Array to Binary Search Tree.

Where we need to convert the Array into BST. We choose middle element as node and [0,mid-1] form the
left BST and [mid+1, end] form the right BST.


Same logic is Here,


We find the mid, create TreeNode for that, (Use slow and Fast pointer technique for that).

[head, mid] left BST
[mid+1, tail] right BST.

One point to remember for tail node we are not going to create any TreeNode it is just for
boundary so we can know that we reach the tail. 


That's why we use, mid as tail for the left half and NULL for the second half.


Time = O(N/2) + O(N/4) + O(N/6) ... = O(N)
Space = O(1)


*/


/*
==============================> Edge Case <=============================================
(head == tail) -> return NULL. (We are not going to create any TreeNode for Tail).

(head -> next == tail) -> TreeNode(head->val, null, null). Single Node.

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
    TreeNode* helper(ListNode* head, ListNode* tail) {

        // Base Condition. Tail not is just for boundary purpose.
        if(head == tail)
            return NULL;

        // Single Node Remain in LL.
        if(head -> next == tail) {
            return new TreeNode(head->val);
        }

        // Slow and fast pointer technique.
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast != tail && fast -> next != tail) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }


        TreeNode* node = new TreeNode(slow->val);
        node -> left = helper(head, slow);
        node -> right = helper(slow->next, tail);

        return node;

    }

    // O(N) - O(1)
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL); 
    }

};