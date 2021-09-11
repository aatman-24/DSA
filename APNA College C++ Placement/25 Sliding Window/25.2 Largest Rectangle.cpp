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

Question : 25.2 Largest Rectangle
Problems : -
*/

/*
==============================> Edge Case <=============================================
IN 2nd method at last if element in the stack then we need to pop all
element and count max height for that one also.


To avoid this we add extra -1 at the end of height array so at last 
every time we encounter -1 into stack.

*/

/*
==============================> Explanation <=============================================
In second Apporach:

we add element into stack if it is in increasing order. but if we 
found new height is less than top of index height then we start to pop
it. And top of stack is consecutive max height when we reach at ith index. 

*/

// Method 1 : Brute Force
// O(N^2)
int get_max_area(vector<int> arr) {
	int maxArea = 0;
	for(int i = 0; i < arr.size(); i++) {
		int height = arr[i];
		for(int j = i; j < arr.size(); j++) {
			int len = j - i + 1;
			height = min(height, arr[j]);
			maxArea = max(maxArea, len * height);
		}

	}
	return maxArea;
}



// Method 2 : Using Stack + Sliding window
// O(N)
int get_max_area(vector<int>& arr) {
	stack<int> st;
	int i = 0, maxArea = 0;

	// Added -1 to the end so we don't need to handle extra case.
	arr.push_back(-1);
	int n = arr.size();

	while(i < n) {
		while(!st.empty() && arr[st.top()] > arr[i]) {
			int top = st.top();
			st.pop();
			int height = arr[top];
			int len = i - top;
			maxArea = max(maxArea, len * height);
		}
		st.push(i);
		i++;
	}
	return maxArea;
}



int main() {

	vi arr = {1,2,3,1,1,5,10,15};
	cout << get_max_area(arr) << endl;
	return 0;
}

