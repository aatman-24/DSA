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

Question : 22.10 Circular Linked List
Topic : 
Problems :
*/

class node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAtHead(node* &head, int val) {
	node* n = new node(val);
	if(head == NULL) {
		n -> next = n;
		head = n;
		return;
	}

	node* tmp = head;
	while(tmp -> next != head) {
		tmp = tmp -> next;
	}

	n -> next = head;
	tmp -> next = n;
	head = n;
}

void insertAtTail(node* &head, int val) {
	node* n = new node(val);
	node* tmp = head;
	if(head == NULL) {
		insertAtHead(head, val);
		return;
	}

	while(tmp -> next != head) {
		tmp = tmp -> next;
	}

	tmp -> next = n;
	n -> next = head;
}

void deleteAtHead(node* &head) {
	node* tmp = head;
	while(tmp -> next != head) {
		tmp = tmp -> next;
	}
	node* todelete = head;
	tmp -> next = head -> next;
	head = head -> next;

	delete todelete;
}

void deleteAtTail(node* head) {
	node* tmp = head;
	while(tmp -> next -> next != head) {
		tmp = tmp -> next;
	}
	tmp->next = tmp -> next -> next;
}

void deletion(node* &head, int pos) {
	if(pos == 1) {
		deleteAtHead(head);
		return;
	}
	node* temp = head;
	int count = 1;
	while(count != pos - 1) {
		temp = temp -> next;
		count++;
	}
	node* todelete = temp -> next;
	temp -> next = temp -> next -> next;
}



void display(node* &head) {
	node* tmp = head;
	do{
		cout << tmp->data << ' ';
		tmp = tmp -> next;
	} while(tmp != head);
}



int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	insertAtHead(head, 0);
	deleteAtTail(head);
	display(head);


	return 0;
}