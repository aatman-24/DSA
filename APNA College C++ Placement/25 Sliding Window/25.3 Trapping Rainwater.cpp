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

Question : 25.3 Trapping Rainwater
Problems : -
*/

/*
==============================> Edge Case <=============================================

*/

/*
==============================> Explanation <=============================================

*/


// Method 1: O(N^2)
// For the current height find the first max height in both direction.
// other logic is same.

// Method 2: O(N) - O(N)
// left, right array for storing the max height. other logic is same.

// Method 3: O(N) - O(1) [OPTIMIZE]
// [Here]

// Method 4: O(N) - O(1) [OPTIMIZE]
// Implemeneted into other file.

int max_water(vi arr) {

	int n = arr.size();
	int maxWater = 0;
	stack<int> st;
	int i = 0;
	while(i < n) {
		while(!st.empty() && arr[st.top()] < arr[i]) {
			int top = st.top();
			int height = arr[top];
			st.pop();
			if(!st.empty()) {
				int len = i - top;
				maxWater += len * (min(arr[st.top()], arr[i]) - height);
			}
		}
		st.push(i);
		i++;
	}

	return maxWater;
}

int main() {

	vi arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << max_water(arr) << endl;
	return 0;
}

