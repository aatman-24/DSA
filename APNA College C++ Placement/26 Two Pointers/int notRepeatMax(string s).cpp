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

Question : 26.3 Longest substring without repeating characters
Problems : -
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/

int notRepeatMax(string s) {

	vector<int> dict(256, -1);
	int maxLen = 0, start = -1;
	for(int i = 0; i < s.size(); i++) {
		if(dict[s[i]] > start)
			start = dict[s[i]];

		dict[s[i]] = i;
		maxLen = max(maxLen,i-start);
	}
	return maxLen;
}


int main() {

	// vector<int> a = {0,1,0,1,0,1,1};
	cout << notRepeatMax("aabacdefd") << endl;
}

