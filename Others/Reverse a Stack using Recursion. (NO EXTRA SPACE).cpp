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

Question : Reverse a Stack using Recursion. (NO EXTRA SPACE)
Topic : 
Problems :
*/


// O(N^2) - O(1).

void insertAtLast(stack<int> &st, int element) {
	if(st.empty()) {
		st.push(element);
		return;
	}
	int topElement = st.top(); st.pop();
	insertAtLast(st, element);
	st.push(topElement);
}


void reverseStack(stack<int> &st) {
	if(st.size() == 1) return ;
	int topElement = st.top(); st.pop();
	reverseStack(st);
	insertAtLast(st, topElement);
}


int main() {

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);

	reverseStack(st);

	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;

}

