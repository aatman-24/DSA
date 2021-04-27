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

Question : Sort Stack Using only Recursion (NO LOOP).
Topic : STACK
Problems :
*/

void insert(stack<int> &st, int tmp) {
	if(st.size() == 0 || st.top() <= tmp) {
		st.push(tmp);
		return ;
	}
	int topEle =  st.top();
	st.pop();
	insert(st, tmp);
	st.push(topEle);
}

void sort_stack(stack<int> &st) {
	if(st.size() == 1) return ;
	int tmp = st.top();
	st.pop();
	sort_stack(st);
	insert(st, tmp);
}

int main() {
	
	stack<int> st;
	st.push(3);
	st.push(0);
	st.push(1);
	st.push(2);

	sort_stack(st);

	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;

}