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

Question : Reverse K nodes In Linked List
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

int length(node* head) {
	int cnt = 0;
	while(head != NULL) {
		head = head -> next;
		cnt++;
	}
	return cnt;
}


// Reverse K node (K-K-K) 1 2 3 6 5 4 like that.
node* reveseK(node* &head, int k) {

	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;

	int count = 0;
	while(currptr != NULL & count < k) {
		nextptr = currptr -> next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}

	if(nextptr != NULL) {
		head->next = reveseK(nextptr, k);
	}	

	return prevptr;

}

int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	display(head);

	reveseK(head, 2);
	display(head);

	return 0;

}

