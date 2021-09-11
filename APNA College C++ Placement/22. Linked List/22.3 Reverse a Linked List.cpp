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

Question : 22.3 Reverse a Linked List
Topic : 
// Problems :
*/


// Iterative
node* reverseLinkedList(node* &head) {
	node *currptr, *preptr, *nextptr; 

	currptr = head;
	preptr = NULL;
	nextptr = head -> next;

	while(currptr != NULL) {
		nextptr = currptr -> next;
		currptr -> next = preptr;

		preptr = currptr;
		currptr = nextptr;
	}
	return preptr;
}

// Recursive
node* reverseLinkedList(node* &head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	node* newhead = reverseLinkedList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}


void display(node* head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << ' ';
		tmp = tmp -> next;
	}
	cout << endl;
}


int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	display(head);

	insertAtHead(head, 4);
	display(head);


	cout << search(head, 8) << endl;


	// deletion(head, 2);
	display(head);
	node* nwHead = reverseLinkedList(head);
	display(nwHead);

	reveseK(nwHead, 2);
	display(nwHead);

	return 0;

}

