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

Question : 22.5 Detection and Removal of Cycle in Linked List
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



void makeCycle(node* &head, int pos) {
	node* temp = head;
	node* startNode;

	int count = 1;
	while(temp -> next != NULL) {

		if(count == pos) {
			startNode = temp;
		}

		count++;
		temp = temp -> next;
	}

	temp -> next = startNode;
}


bool detectCycle(node* &head) {

	node* slow = head;
	node* fast = head;

	while(fast != NULL && fast->next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;

		if(fast == slow) {
			return true;
		}
	}

	return false;

}

void removeCycle(node* &head) {
	node* slow = head;
	node* fast = head;

	do {
		slow = slow -> next;
		fast = fast -> next -> next;
	} while(slow != fast);


	fast = head;
	while(slow -> next != fast -> next) {
		slow = slow -> next;
		fast = fast -> next;
	}
	slow -> next = NULL;
}


void display(node* head) {
	node* tmp = head;
	while(tmp != NULL) {
		cout << tmp->data << "-> ";
		tmp = tmp -> next;
	}
	cout << "NULL" << endl;
}


int main() {


	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);

	makeCycle(head, 2);
	cout << detectCycle(head) << endl;

	removeCycle(head);
	cout << detectCycle(head) << endl;

}

/*
Why It works.

m = distance from head to cycle start point
n = distance from cycle start point to meet point
i = number of times fast traverse the loop
j = number of times slow traverse the loop
l = distance of loop(cycle)

distance moved by fast ptr = 2 * distance moved by slow ptr

m + n + l*j = 2 * (m + n + l*i)

m + n = l * (j - 2*i)

m = l * (j - 2*i) - n


here (j-2*i) is represet some integer.

m = l*k - n
let take k = 1,

m = l - n

means distance of m == distance of remaining distance of l cycle.

that's why we put fast again at head and move only by single next.

*/
