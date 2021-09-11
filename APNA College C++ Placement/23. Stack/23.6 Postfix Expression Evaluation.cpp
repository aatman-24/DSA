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

Question : 23.6 Postfix Expression Evaluation 
Topic : Stack
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
For Prefix evalution we start from the end of expression. (op1+op2)
Postfix evalution we start begining of the expression. (op2+op1)
*/

 {

	stack<int> st;

	for(int i = 0; i < s.size(); i++) {


		if(s[i] >= '0' && s[i] <= '9') {
			st.push(s[i] - '0');
		}
		else {

			int op2 = st.top();
			st.pop();
			int op1 = st.top();
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
			}
		}
	}

	return st.top();
}


int main() {


	string expression = "46+2/5*7+";
	cout << postfixEvalution(expression) << endl;

	return 0;

}

