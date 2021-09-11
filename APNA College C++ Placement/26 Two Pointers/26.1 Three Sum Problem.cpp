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

Question : 26.1 Three Sum Problem
Problems : -
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/

// O(N^2) - O(1)
bool threesum(vector<int> arr, int target) {

	int n = arr.size();
	int low, high, current;

	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {

		low = i + 1;
		high = n - 1;

		while(low < high) {
			current = arr[i] + arr[low] + arr[high];

			if(current == target) {
				return true;
			}

			if(current < target) {
				low++;
			}
			else {
				high--;
			}
		}
	}
	return false;
}

int main() {

	vector<int> a = {2,3,1,5,8,3,9};
	cout << threesum(a, 5) << endl;
}

