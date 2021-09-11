28.1 Binary Search Trees Introduction & Insertion block 

- struct Node
- Node* insertBST(Node* root, int val) : O(logN)

28.2 Search and Delete in Binary Search Tree

- Node* searchInBST(Node* root, int key) : O(logN)
- Node* inorderSuccessor(Node* root) : O(logN) 
- Node* inorderPredecssor(Node* root) : O(logN) 
- Node* deleteInBST(Node* root, int key) : O(logN) 


28.3 Construct Binary Search Tree from Preorder

- Node* constructBST(int preorder[], int &preorderIdx, int key, int min, int max, int n) : O(N) 

28.4 Check for Binary Search Tree

- bool isBST(Node* root, Node* min=NULL, Node* max=NULL) : O(N)

28.5 Build Balanced BST from Sorted Array

- Node* sortedArrayToBST(int arr[], int start, int end) : O(N)

28.6 Catalan Numbers Application

- vector<Node*> constructTree(int start, int end) : O(catalan(N)) 


28.7 Zig Zag Traversal Binary Search Tree

- void zigzagTraversal(Node* root) : O(N) + O(N)

28.8 Identical Binary Search Tree

- bool isIdentical(Node* root1, Node* root2) :
O(min(N,M))

28.10 Largest Binary Search Tree in BT

-  struct Info
- Info largestBST(Node* root)

28.11 Recover Binary Search Tree

- void calcPointers(Node* root, Node* &prev, Node* &first, Node* &mid, Node* &last)

- void restoreBST(Node* root)

