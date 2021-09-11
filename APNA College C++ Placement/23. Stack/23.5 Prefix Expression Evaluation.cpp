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

Question : 23.5 Prefix Expression Evaluation 
Topic : Stack
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
For Prefix evalution we start from the end of expression. and for postfix
evalution we start begining of the expression.
 
*/


// O(N) - O(N)
int prefixEvalution(string s) {

	stack<int> st;
	for(int i = s.length()-1; i >= 0; i--) {

		if(s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
		}
		else {

			int op1 = st.top();
			st.pop();
			int op2 = st.top();
			st.pop();

			switch(s[i]) {
				case '+':
					st.push(op1+op2);
					break;

				case '-':
					st.push(op1-op2);
					break;

				case '*':
					st.push(op1*op2);
					break;

				case '/':
					st.push(op1/op2);
					break;

				case '^':
					st.push(pow(op1,op2));
					break;

				default:
					break;
			}
		}
	}

	return st.top();
}


int main() {


	string expression = "-+7*45+20";
	cout << prefixEvalution(expression) << endl;

	return 0;

}

