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

Question : 22.7 Append Last K Nodes of a Linked List
Topic : Singly Linked List
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

int length(node* &head) {
	node* tmp = head;
	int count = 0;
	while(tmp != NULL) {
		tmp = tmp -> next;
		count++;
	}
	return count;
}

void kappend(node* &head, int k) {

	node* tail = head; 
	node* newTail;
	node* newHead;

	int n = length(head);

	// Same LinkedList if k == n;
	if(k == n) {
		return;
	}

	int count = 1;
	while(tail -> next != NULL) {

		if(count == n - k) {
			newTail = tail;
		}

		if(count == n - k + 1) {
			newHead = tail;
		}
		tail = tail -> next;
		count++; 
	}

	newTail -> next = NULL;
	tail -> next = head;

	head = newHead;
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
	display(head);

	kappend(head, 4);
	display(head);

}
