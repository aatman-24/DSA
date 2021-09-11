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

Question : 22.9 Merge 2 Sorted Linked List
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

void insertAtTail(node* &head, int val) {
	node* n = new node(val);

	if(head == NULL) {
		head = n;
		return;
	}

	node* tmp = head;
	while(tmp->next != NULL)  {
		tmp = tmp->next;
	}
	tmp->next = n;
}

void display(node* head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << ' ';
		tmp = tmp -> next;
	}
	cout << endl;
}

node* mergeRecursively(node* &head1, node* &head2) {

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	node* result;
	if(head1 -> data < head2 -> data) {
		result = head1;
		result -> next = mergeRecursively(head1->next, head2);
	}
	else{
		result = head2;
		result -> next = mergeRecursively(head1, head2->next);
	}
	return result;
}


node* merge(node* &head1, node* &head2) {

	node* dummy = new node(-1);
	node* tmp1 = head1;
	node* tmp2 = head2;

	node* tmp3 = dummy;

	while(tmp2 != NULL && tmp1 != NULL) {
		if(tmp1 -> data < tmp2 -> data) {
			tmp3 -> next = tmp1;
			tmp1 = tmp1 -> next;
		}
		else {
			tmp3 -> next = tmp2;
			tmp2 = tmp2 -> next;
		}
		tmp3 = tmp3 -> next;
	}

	// Remaining linkelist directly added
	if(tmp1 != NULL) {
		tmp3 -> next = tmp1;
	}

	if(tmp2 != NULL) {
		tmp3 -> next = tmp2;
	}

	dummy = dummy -> next;
	return dummy;
}



int main() {

	node* head1 = NULL;
	insertAtTail(head1, 1);
	insertAtTail(head1, 3);
	insertAtTail(head1, 5);
	insertAtTail(head1, 7);

	node* head2 = NULL;
	insertAtTail(head2, 2);
	insertAtTail(head2, 4);
	insertAtTail(head2, 6);
	insertAtTail(head2, 8);
	insertAtTail(head2, 10);
	insertAtTail(head2, 12);
	insertAtTail(head2, 14);

	display(head1);
	display(head2);

	node* head3 = merge(head1, head2);
	display(head3);


	return 0;
}