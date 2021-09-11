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

Question : 25.1 Sliding Window Maximum using Deque 
Problems : -
*/

/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================


*/

// O(N*K)
// METHOD 1: Two For loop
	
// O(N*logN)
// METHOD 2: map + silding window
vector<int> maxSubarray(vector<int> nums, int k) {
	multiset<int, greater<int>> s;
	vector<int> ans;

	for(int i = 0; i < k; i++)
		s.insert(nums[i]);

	ans.push_back(*s.begin());
	for(int i = k; i < nums.size(); i++) {
		s.erase(s.lower_bound(nums[i-k]));
		s.insert(nums[i]);
		ans.push_back(*s.begin());
	}

	return ans;
}


// O(N)
// METHOD 3 - Sliding window proper.
vector<int> maxSubarray(vector<int> nums, int k) {

	deque<int> q;
	vector<int> ans;

	for(int i = 0; i < k; i++) {
		while(!q.empty() && a[q.back()] < a[i]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	ans.push_back(nums[q.front()]);

	for(int i = k; i < nums.size(); i++) {
		
		// drop first element from the window.
		if(q.front() == i - k) {
			q.pop_front();
		}

		// allow element if is bigger than current window lowest element.
		// inserted in decreasing order only.
		while(!q.empty() && a[q.back()] < a[i]) {
			q.pop_back();
		}
		q.push_back(i);
		ans.push_back(nums[q.front()])
	}
	
	return ans;
}


int main() {




	return 0;
}

