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

Question : 25.4 Redundant Parenthesis 
Problems : -
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/

// O(N) - O(1)
bool redundant_parenthesis(string s) {
	stack<char> st;
	int n = s.size(), i = 0;
	bool extra_bracket = false;

	while(i < n) {
		if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')') {
			if(st.top() == '(') {
				extra_bracket = true;
				break;
			}
			while(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/') {
				st.pop();
				if(st.empty()) break;
			}
		}
		i++;
	}
	return extra_bracket;
}


int main() {

	cout << redundant_parenthesis("(a+b)") << endl;
	return 0;
}

