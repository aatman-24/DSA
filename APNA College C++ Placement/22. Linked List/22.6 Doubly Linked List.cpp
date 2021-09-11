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

Question : 22.6 Doubly Linked List
Topic : 
Problems :
*/

class node {
public:
	int data;
	node* next;
	node* prev;

	node(int val) {
		data = val;
		next = NULL;
		prev = NULL;
	}
};

void insertAtHead(node* &head, int val) {
	node* n = new node(val);
	n -> next = head;
	if(head != NULL) head -> prev = n;
	head = n;
}

void insertAtTail(node* &head, int val) {

	if(head == NULL) {
		insertAtHead(head, val);
		return;
	}

	node* n = new node(val);
	node* tmp = head;

	while(tmp -> next != NULL) {
		tmp = tmp -> next;
	}

	tmp -> next = n;
	n -> prev = tmp;
}

void insertAtPosition(node* &head, int val, int pos) {
	if(pos == 1) {
		insertAtHead(head, val);
		return;
	}
	node *n = new node(val);
	node *tmp = head;
	int count = 1;
	while(count != pos && tmp != NULL) {
		tmp = tmp -> next;
		count++;
	}

	if(tmp == NULL) {
		insertAtTail(head, val);
		return;
	}

	n -> prev = tmp -> prev;
	tmp -> prev -> next = n;

	n -> next = tmp;
	tmp -> prev = n;
}

void deleteAtHead(node* &head) {
	node *todelete = head;
	head = head -> next;
	head -> prev = NULL;

	delete todelete;
}

void deleteAtTail(node* &head) {
	if(head == NULL) {
		return;
	}
	if(head -> next == NULL) {
		deleteAtHead(head);
		return;
	}
	node* tmp = head;

	while(tmp -> next != NULL) {
		tmp = tmp -> next;
	}

	node* todelete = tmp;
	tmp -> prev -> next = NULL;
	tmp -> prev = NULL;

	delete todelete;
}

void deleteAtPosition(node* &head, int pos) {
	if(pos == 1) {
		deleteAtHead(head);
	}

	node* tmp = head;
	int count = 1;
	while(tmp != NULL && count != pos) {
		tmp = tmp -> next;
		count++;
	}

	tmp -> prev -> next = tmp -> next;

	if(tmp -> next != NULL )
		tmp -> next -> prev = tmp -> prev;

	delete tmp;

}

void display(node* &head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp -> next;
	}
	cout << "NULL" << endl;
}


int main() {
	node *head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtHead(head, 6);
	deleteAtHead(head);
	deleteAtPosition(head, 2);
	insertAtPosition(head, 2, 2);
	insertAtPosition(head, 66, 5);
	deleteAtPosition(head, 6);
	deleteAtTail(head);

	display(head);
}
