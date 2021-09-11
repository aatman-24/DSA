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

Question : 22.2  Deletion at Linked List
Topic : 
// Problems :
*/

void deleteAtHead(node* &head) {
	node* todelete = head;
	head = head -> next;
	delete todelete;
}

void deleteAtTail(node* &head) {

	node* tmp = head;
	while(tmp -> next -> next != NULL) {
		tmp = tmp -> next;
	}
	node* todelete = tmp -> next
	tmp -> next = NULL;
	delete todelete;
}

void deletion(node* &head, int val) {

	// Empty LinkedList
	if(head == NULL) {
		return;
	}

	// Single node LinkedList (assumed that single node value is val).
	if(head->next == NULL) {
		deleteAtHead(head);
		return;
	}

	node* tmp = head;
	while(tmp->next->data != val) {
		tmp = tmp -> next;
	}

	node* todelete = tmp -> next;
	tmp->next = tmp->next->next;

	delete todelete;
}

int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	display(head);


	deletion(head, 2);
	display(head);

	return 0;

}

