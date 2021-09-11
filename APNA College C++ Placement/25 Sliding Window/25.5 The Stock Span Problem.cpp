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

Question : 25.5 The Stock Span Problem 
Problems : -
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/

// O(N) - O(N)
vector<int> stockspan(vector<int> prices) {
	vector<int> ans;
	stack<pair<int,int>> st;
	int i = 0, n = prices.size();
	for(auto price : prices) {
		int days = 1;
		while(!st.empty() && st.top().first <= price) {
			days += st.top().second;
			st.pop();
		}
		st.push({price, days});
		ans.push_back(days);
	}

	return ans;
}

int main() {

	vector<int> a = {100, 80, 60, 70, 60, 75, 85};
	vector<int> ans = stockspan(a);
	for(auto i : ans) {
		cout << i << ' ';
	}
	cout << endl;


}

