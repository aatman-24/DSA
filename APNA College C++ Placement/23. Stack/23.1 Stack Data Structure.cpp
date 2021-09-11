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

Question : 23.1 Stack Data Structure
Topic : 
Problems :
*/


#define n 100

class Stack {

int* arr;
int top;

public:

	Stack() {
		arr = new int[n];
		top = -1;
	}

	void push(int x) {
		if(top == n - 1) {
			cout << "Stack OverFlow" << endl;
			return;
		}
	
		top++;
		arr[top] = x;
	}

	void pop() {
		if(top == -1) {
			cout << "No element to pop" << endl;
			return;
		}
		top--;
	}

	int Top() {
		if(top == -1) {
			cout << "No element to pop" << endl;
			return -1;
		}
		return arr[top];
	}

	bool empty() {
		return top == -1;
	}

};

int main() {

	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	cout << st.Top() << endl;

	st.pop();

	cout << st.Top() << endl;

	return 0;

}

