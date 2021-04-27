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

Question : Delete the middle(kth element in stack) using recursion.
Topic : stack
Problems :
*/

void deleteKtheElementInStack(stack<int> &st, int k) {
	if(st.size() == 1) return;
	if(k == 1) {
		st.pop(); return;
	}
	int tmp = st.top();
	st.pop();
	deleteKtheElementInStack(st, k-1);
	st.push(tmp);
}

int main() {
	
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);

	int middle  = st.size() / 2 + 1;

	deleteKtheElementInStack(st, middle);

	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	

}