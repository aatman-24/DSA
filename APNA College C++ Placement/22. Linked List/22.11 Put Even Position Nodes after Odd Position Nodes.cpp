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

Question : 22.11 Put Even Position Nodes after Odd Position Nodes
Topic : 
Problems :
*/

/*
Edge Case: Odd Length LinkedList. odd -> next = NULL break while loop.
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
	while(tmp -> next != NULL) {
		tmp = tmp -> next;
	}
	tmp -> next = n;
}


void display(node* &head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << ' ';
		tmp = tmp -> next;
	}
	cout << endl;
}

// standard
void evenAfterOdd(node* &head) {
	node* odd = head;
	node* even = odd -> next;
	node* evenHead = even;

	while(odd -> next != NULL && even -> next != NULL) {
		odd -> next = even -> next;
		odd = odd -> next;

		if(odd -> next != NULL) {
			even -> next = odd -> next;
			even = even -> next;
		}
	}
	odd -> next = evenHead; 
	even -> next = NULL;
}


void putOddEven(node* head) {
	node* odd = head;
	node* even = odd -> next;

	// If only single node in LL
	if(even == NULL) return;

	node* evenHead = even;
	int count = 0;
	while(true) {
		if(count % 2 == 0) {
			if(even -> next != NULL) {
				odd -> next = even -> next;
				odd = odd -> next;
			}
			else break;
		}
		else {
			if(odd -> next != NULL) {
				even -> next = odd -> next;
				even = even -> next;
			}
			else break;
		}
		count++;
	}

	even -> next = NULL;
	odd -> next = evenHead;
}




int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	// insertAtTail(head, 6);
	display(head);

	evenAfterOdd(head);
	display(head);

	return 0;
}