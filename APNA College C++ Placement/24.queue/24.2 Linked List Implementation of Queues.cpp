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

Question : 24.2 Linked List Implementation of Queues
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/

class node {
public:
	int data;
	node* next;
	node(int val) {
		data = val;
		next = nullptr;
	}
	
};

class Queue{
	node* front;
	node* back;

public:

	Queue() {
		front = NULL;
		back = NULL;
	}

	void enqueue(int x) {
		node* n = new node(x);

		if(front == NULL) {
			back = n;
			front = n;
			return;
		}

		back -> next = n;
		back = n;
	}


	void dequeue() {
		if(front == NULL) {
			cout << "Queue is Empty" << endl;
			return;
		}
		node* todelete = front;
		front = front -> next;
		delete todelete; 
	}


	int first() {
		if(front == NULL) {
			cout << "Queue is Empty" << endl;
			return -1;
		}
		return front->data;
	}


	bool empty() {
		if(front == NULL)
			return true;
		return false;
	}

};


int main() {


	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);

	cout << q.first() << endl;

	q.dequeue();

	cout << q.first() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	cout << q.first() << endl;

	return 0;
}

