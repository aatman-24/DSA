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
Question : 28.5 Build Balanced BST from Sorted Array 
*/

/*
==============================> Edge Case <=============================================

*/
 
/*
==============================> Explanation <=============================================
What i Found is:

Basic Blocks:

CT(i+1, i) -> NULL


CT(i,i) -> i
          / \
        NULL NULL

CT(i, i+1) ->    i                     i+1  
                / \   and second one   / \
               N  i+1                 i   N


Then just attach the leftSubtree and rightSubtree all combination for with curr nodes.


*/

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << ' ';
    inorder(root -> right);
}


void preorder(Node* root) {
    if(root == NULL)
        return;
    cout << root -> data << ' ';
    preorder(root -> left);
    preorder(root -> right);
}

vector<Node*> constructTree(int start, int end) {
    vector<Node*> trees;

    if(start > end) {
        trees.push_back(NULL);
        return trees;
    }

    // Curr denote the value of node which going to create
    for(int curr = start; curr <= end; curr++) {

        // leftSubtree Nodes contain the value less than < curr.
        vector<Node*> leftSubtress = constructTree(start, curr - 1);

        // rightSubtree Nodes containt the values greater than > curr
        vector<Node*> rightSubtress = constructTree(curr + 1, end);

        for(int i = 0; i < leftSubtress.size(); i++) {

            Node* leftNode = leftSubtress[i];

            for(int j = 0; j < rightSubtress.size(); j++) {

                Node* rightNode = rightSubtress[j];

                // create curr val nodes.
                Node* currNode = new Node(curr);
                currNode -> left = leftNode;
                currNode -> right = rightNode;

                trees.push_back(currNode);
            }
        }

    }

    return trees;

}



int main()
{

    // as per catalan number it should be 5.
    vector<Node*> trees = constructTree(1,3);


    cout << trees.size() << endl;

    for(int i = 0; i < trees.size(); i++){
        preorder(trees[i]);
        cout << endl;
    }



}
 

 