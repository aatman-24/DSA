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

Question : 23.3 Reverse a Stack
Topic : 
Problems :
*/

void insertAtBottom(stack<int> &st, int ele) {
	if(st.empty()) {
		st.push(ele);
		return;
	}

	int topEle = st.top();
	st.pop();
	insertAtBottom(st, ele);

	st.push(topEle);
}

void reverse(stack<int> &st) {
	if(st.empty()) {
		return;
	}

	int ele = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st, ele);
}

int main() {

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	reverse(st);

	while(!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	return 0;

}

