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
Question : 27.1 Binray Tree Introduction
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/


struct Node {
	int data;
	struct Node* left;
	struct NOde* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

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
	rott -> left -> right = new Node(5);

	/*
		1
	   / \
	  2   3
	 / \
    4   5

	*/

}

