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

Question : 23.7 Infix to Postfix 
Topic : Stack
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/

int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '*' || c == '|')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else return -1;
}

string infixToPostfix(string s) {

	stack<char> st;
	string res = "";

	for(int i = 0; i < s.size(); i++) {

		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
			res += s[i];
		else if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')') {
			while(!st.empty() && st.top() != '(') {
				res += st.top();
				st.pop();
			}
			if(!st.empty()) st.pop();
		}
		else {
			while(!st.empty() && prec(st.top()) > prec(s[i])) {
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()) {
		res += st.top();
		st.pop();
	}

	return res;
}

string infixToPrefix(string s) {
	reverse(s.begin(), s.end());	
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ')') s[i] = '(';
		if(s[i] == '(') s[i] = ')';	
	}
	string res =  infixToPostfix(s);
	reverse(res.begin(), res.end());
	return res;
}

int main() {

	string expression = "(a-b/c)*(a/k-l)";
	cout << infixToPostfix(expression) << endl;

	return 0;
}

