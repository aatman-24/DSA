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

Question : 23.8 Balanced Parenthesis
Topic : Stack
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/

map<char, char> mcc;
mcc[')'] = '(';
mcc['}'] = '{';
mcc[']'] = '[';


bool isBalancedParenthesis(string s) {
	stack<char> st;
	bool flag = true;

	for(int i = 0; i < s.size(); i++) {

		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		else{
			if(!st.empty())
				flag = st.top() == mcc[s[i]];
			if(!flag) return false;
		}

	}
	return st.empty();

}

int main() {

	string exp = "[{([{()}])}]";
	cout << isBalancedParenthesis(exp) << endl;

	return 0;
}

