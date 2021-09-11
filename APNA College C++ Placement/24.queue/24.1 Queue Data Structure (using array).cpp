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

Question : 24.1 Queue Data Structure (using array)
Topic : Stack
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/

#define size 20

class Queue{
	int* arr;
	int front;
	int back;

public:

	Queue() {
		arr = new int[size];
		front = -1;
		back = -1;
	}

	void enqueue(int x) {
		if(back == size - 1) {
			cout << "Queue is overflow" << endl;
			return;
		}

		back++;
		arr[back] = x;

		if(front == -1) front++;
	}


	void dequeue() {
		if(front == -1 || front > back) {
			cout << "Queue is Empty" << endl;
			return;
		}
		front++;
	}


	int first() {
		if(front == -1 || front > back) {
			cout << "Queue is Empty" << endl;
			return -1;
		}
		return arr[front];
	}


	bool empty() {
		if(front == -1 || front > back)
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
	q.dequeue();

	return 0;
}

