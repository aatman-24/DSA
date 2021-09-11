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

Question : 23.2 Reverse a Sentence using Stacks
Topic : 
Problems :
*/

void reverseString(string s) {

	stack<string> st;

	for(int i = 0; i < s.size(); i++) {

		string word = "";
		while(i < s.size() && s[i] != ' ') {
			word += s[i];
			i++;
		}
		st.push(word);
	}

	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}

	cout << endl;

}

int main() {

	string s = "How are you?";
	reverseString(s);

	return 0;
}

