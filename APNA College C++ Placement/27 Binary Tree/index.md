27.1 Binray Tree Introduction
- struct Node

27.2 Binary Tree Traversals_ Preorder, Inorder, Postorder Traversal

- void preorder(struct Node* root) : O(N)
- void inorder(struct Node* root) : O(N)
- void postorder(struct Node* root) : O(N)


27.3 | 27.4 Build Tree Postorder and Inorder && Preorder and Inorder

- Node* buildTreePre(int preorder[], int inorder[], int start, int end) : O(N)

- Node* buildTreePost(int postorder[], int inorder[], int start, int end) : O(N)

 27.5 Level Order Traversal ,Sum at Kth Level In Binary Tree 

- void printLevelOrder(Node* root) : O(N)
- int sumAtKLevel(Node* root, int k) : O(N)

27.6 Count and Sum of Nodes

- int countNodes(Node* root) : O(N)
- int sumNodes(Node* root) : O(N)

27.7 Height and Diameter in Binary Tree

- int heightOfTree(Node* root) : O(N)
- int calcDiameter(Node* root) : O(N^2)
- int calcDiameter(Node* root, int &height) : O(N)

27.8  Sum Replacement in Binary Tree

- void sumReplacementOfBinaryTree(Node* root) : O(N)

27.9 Height Balanced Binary Tree 

- bool isBalanced(Node* root) : O(N^2)
- bool isBalanced(Node* root, int &height) : O(N)

27.10|11 Right View|Left View of Binary Tree 

- void rightView(Node* root) : O(N)
- void LeftView(Node* root) : O(N)


27.15 Lowest Common Ancestor in Binary Tree

- bool getPath(Node* root, int key, vector<int> &path) : O(N)

- int LCA(Node* root, int n1, int n2) : O(N) + overlapping is much

- Node* LCA2(Node* root, int n1, int n2) : O(N)

27.12 Shortest Distance between 2 Nodes

-  int findDist(Node* root, int key, int dist) : O(N)

- int distBwNodes(Node* root, int n1, int n2) : O(N)

27.13 Flatten a Binary Tree in preorder

- void flatten(Node* root) : O(N)

27.14 Nodes at Distance K in Binary Tree

- void printSubtreeNodes(Node* root, int k) : O(N)

- int printAllNodesAtK(Node* root, Node* target, int k) : O(N)

* The Morris Traversal