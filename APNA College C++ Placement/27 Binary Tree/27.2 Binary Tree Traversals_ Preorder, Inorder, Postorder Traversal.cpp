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
Question : 27.2 Binary Tree Traversals_ Preorder, Inorder, Postorder Traversal
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

preorder  = root -> left -> right
inorder   = left -> root -> right
postorder = left -> right -> root
(Take root as opreation it is easy to remember).

*/

struct Node {
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

void preorder(struct Node* root) {
	if(root == NULL)
		return;
	cout << root -> data << ' ';
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(struct Node* root) {
	if(root == NULL)
		return;
	inorder(root -> left);
	cout << root -> data << ' ';
	inorder(root -> right);
}

void postorder(struct Node* root) {
	if(root == NULL)
		return;
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << ' ';
}



int main() {

	struct Node* root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);

	/*
		1
	   / \
	  2   3

	*/

	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);

	/*
		1
	   / \
	  2   3
	 / \
    4   5

	*/


	root -> right -> left = new Node(6);
	root -> right -> right = new Node(7);


	/*
		 1
	   /   \
	  2     3
	 / \   / \
    4   5 6   7

	*/

	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);

}

