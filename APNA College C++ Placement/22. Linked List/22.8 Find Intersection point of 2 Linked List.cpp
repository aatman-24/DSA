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

Question : 22.8 Find Intersection point of 2 Linked List
Topic : 
Problems :
*/

class node {
public:
	int data;
	node* next;

	node(int val){
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
	while(tmp -> next != NULL) {
		tmp = tmp -> next;
	}

	tmp -> next = n;
	return;
}

void display(node* &head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp -> next;
	}
	cout << "NULL " << endl;
}

int length(node* &head) {
	node* tmp = head;
	int cnt = 0;
	while(tmp != NULL) {
		tmp = tmp -> next;
		cnt++;
	}
	return cnt;
}

int intersection(node* &head1, node* &head2) {

	if(head1 == NULL || head2 == NULL) return -1;

	int l1 = length(head1);
	int l2 = length(head2);

	node* tmp1;
	node* tmp2;

	if(l1 > l2) {
		tmp1 = head1;
		tmp2 = head2;
	}
	else {
		tmp1 = head2;
		tmp2 = head1;
	}

	int d = abs(l1 - l2);

	// skip first d node form large linked list.
	while(d) {
		tmp1 = tmp1 -> next;
		d--;
	}

	while(tmp1 != NULL && tmp2 != NULL) {

		if(tmp1 == tmp2) {
			return tmp2->data;
		}
		tmp1 = tmp1 -> next;
		tmp2 = tmp2 -> next;
	}

	return -1;
}

void makeIntersection(node* &head1, node* head2, int d) {

	node* tmp1 = head1;
	node* tmp2 = head2;
	d--;
	while(d--) {
		tmp1 = tmp1 -> next;
	}
	tmp1 -> next = tmp2;
}



int main() {


	node* head1 = NULL;
	insertAtTail(head1, 1);
	insertAtTail(head1, 2);
	insertAtTail(head1, 3);
	insertAtTail(head1, 4);
	insertAtTail(head1, 5);
	insertAtTail(head1, 6);

	display(head1);

	node* head2 = NULL;
	insertAtTail(head2,7);
	insertAtTail(head2,8);
	insertAtTail(head2,9);
	display(head2);

	makeIntersection(head1, head2, 3);

	cout << intersection(head1, head2) << endl;	

	display(head1);

	return 0;
}
