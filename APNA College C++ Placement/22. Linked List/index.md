22.Introduction to Linked List

- class node
- insertAtTail(node* &head, int val) : return void
- insertAtHead(node* &head, int val) : return void
- search(node* head, int key) : return bool
- display(node* head) : return void
- length(node* &head) : return int

22.2 Deletion at Linked List

- deleteAtHead(node* &head) : return void
- deleteAtTail(node* &head) : return void
- deletion(node* &head, int val) : return void

22.3 Reverse a Linked List

- reverseLinkedList(node* &head) : return node* 
- reverseLinkedList(node* &head) : return node* (Recursive)

22.4 Reverse K nodes In Linked List

- reveseK(node* &head, int k) : return node* 


22.5 Detection and Removal of Cycle in Linked List

- makeCycle(node* &head, int pos) : return void
- detectCycle(node* &head) : return bool
- removeCycle(node* &head) : return void

22.6 Doubly Linked List

- node
- insertAtHead(node* &head, int val)
- insertAtTail(node* &head, int val)
- insertAtPosition(node* &head, int val, int pos)
- deleteAtHead(node* &head)
- deleteAtTail(node* &head)
- deleteAtPosition(node* &head, int pos)
- display(node* &head)

22.7 Append Last K node into front of Linked List (single LL)

- kappend(head)

22.8 Find Intersection point of 2 Linked List

- intersection(node* &head1, node* &head2) : return int
- makeIntersection(node* &head1, node* head2, int d)

22.9 Merge 2 Sorted Linked List

- mergeRecursively(node* &head1, node* &head2) : return node*
- merge(node* &head1, node* &head2) : return node*

22.10 Circular Linked List

- insertAtHead(node* &head, int val)
- insertAtTail(node* &head, int val) 
- deleteAtHead(node* &head)
- deleteAtTail(node* head)
- deletion(node* &head, int pos)

22.11 Put Even Position Nodes after Odd Position Nodes

- evenAfterOdd(node* &head)