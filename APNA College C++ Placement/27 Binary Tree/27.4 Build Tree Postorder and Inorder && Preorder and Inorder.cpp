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
Question : 27.4 Build Tree Postorder and Inorder && Preorder and Inorder
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

Using preorder and postorder there are many tree possible. 

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




int search(int inorder[], int start, int end, int curr) {
	for(int i = start; i <= end; i++)
		if(inorder[i] == curr)
			return i;
	return -1;
}


Node* buildTreePre(int preorder[], int inorder[], int start, int end) {
	static int idx = 0;

	if(start > end) 
		return NULL;

	int curr = preorder[idx];
	idx++;
	Node* node = new Node(curr);

	if(start == end)
		return node;

	int pos = search(inorder, start, end, curr);
	node -> left = buildTreePre(preorder, inorder, start, pos-1);
	node -> right = buildTreePre(preorder, inorder, pos+1, end);

	return node;
}


Node* buildTreePost(int postorder[], int inorder[], int start, int end) {

	static int idx = 6;

	cout << idx << endl;

	if(start > end)
		return NULL;

	int curr = postorder[idx];
	idx--;
	Node* node = new Node(curr);

	if(start == end)
		return node;

	int pos = search(inorder, start, end, curr);
	node -> right = buildTreePost(postorder, inorder, pos+1, end);
	node -> left = buildTreePost(postorder, inorder, start, pos-1);

	return node;
}


int main() {

	int inorder_arr[] =  {1,2,4,5,3,6,7};
	int preorder_arr[] = {4,2,5,1,6,3,7};
	int postorder_arr[] = {4,5,2,6,7,3,1};

	Node* root = buildTree(inorder_arr, preorder_arr, 0, 6);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;

	Node* root2 = buildTreePost(postorder_arr, inorder_arr, 0, 6);
	postorder(root2);
	cout << endl;
	inorder(root2);

	int b = sizeof(postorder_arr)/sizeof(int);
	cout << b << endl;

}

