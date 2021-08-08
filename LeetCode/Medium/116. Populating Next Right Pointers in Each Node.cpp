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

Question : 116. Populating Next Right Pointers in Each Node
Topic :BT
Problems : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

==============================> Explanation <=============================================

- Initution is that, 


Here we given the next node. So use it properly so we can perform the level order travesal.

Idea is that,

connect the next pointer of parent node first with appropriate node
and after connect its child using level order traveral which can be easy after using the next pointer.


        1
       / \
      2 - 3
     / \ / \
    4  5 6  7

- So once we connect the 2 with 3.

    4 is connect with 5 directly. curr -> left -> next = curr -> right.

And for the curr -> right two case.

    1) It is last right node. (3, 7) for that, It's right must be NULL. Here default value is NULL
    so no need to handle this case.

    2) If right child is intermidate node(5).

        curr -> right -> next = curr -> next -> left.
            5 -> next = 6.

It is only possible due to th curr is linked with next node.

So we start from the root and perform this opreation. And after one level complete we move to
the next level. So every time we assure that curr node next is connected with next node.
*/


/*
==============================> Edge Case <=============================================


*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* connect(Node* root) {
        dfs(root, nullptr);
        return root;
    }

    // We have to perform,
    // curr -> next = next And Connect the left and right children.
    // But before that parent must be connect with respecitve node.
    void dfs(Node* curr, Node* next) {

        if(curr == NULL)
            return;

        // Connect the current with given next node.
        curr -> next = next;

        // Connect Left Children with right childer. Left Done.
        dfs(curr->left, curr->right);

        // Connect Right children with either NULL or curr -> next -> left children.
        dfs(curr->right, curr->next == NULL ? NULL : curr->next->left);
    }






    // Iterative Form.
    // pre move from top to bottom with attach with left most node.
    // cur move from the left to right in level.
    Node* connect(Node* root) {

        if(root == NULL) return NULL;

        Node *pre, *cur;
        pre = root;
        cur = NULL;

        // If there is next level then and only we perform the opreation.
        // Our goal is to connect the children or pre node that's why.
        while(pre -> left) {

            // Currnent Node.
            cur = pre;

            while(cur) {

                // Connect Left Children with right children.
                cur->left->next = cur->right;

                
                if(cur -> next) {
                    // Connect Right Children with (Curr->next) node left most child.
                    cur -> right -> next = cur -> next -> left;
                }

                // Move into the level from left to right.
                cur = cur -> next;
            }

            // Move from top to bottom.
            pre = pre -> left;

        }

        return root;
    }
};