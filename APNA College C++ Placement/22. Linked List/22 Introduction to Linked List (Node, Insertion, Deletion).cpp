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

Question : 22 Introduction to Linked List (Node, Insertion, Deletion)
Topic : 
// Problems :
*/


class node {
public:
	int data;
	node* next;

	node(int val) {
		data = val;
		next = NULL;
	}
	// node(int val): data(val), next(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

void insertAtHead(node* &head, int val) {
	node *n = new node(val);
	n -> next = head;
	head = n;
}

bool search(node* head, int key) {
	node* tmp = head;
	while(tmp != NULL) {
		if(tmp -> data == key) return true;
		tmp = tmp -> next;
	}
	return false;
}


void display(node* head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << ' ';
		tmp = tmp -> next;
	}
	cout << endl;
}

int length(node* &head) {
	node* tmp = head;
	int count = 0;
	while(tmp != NULL) {
		tmp = tmp -> next;
		count++;
	}
	return count;
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

	return 0;

}

