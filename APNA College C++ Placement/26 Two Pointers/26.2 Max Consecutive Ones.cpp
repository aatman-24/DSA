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

Question : 26.2 Max Consecutive Ones
Problems : -
*/

/*
==============================> Edge Case <=============================================
No Edge Case
*/

/*
==============================> Explanation <=============================================

*/

int maxOne(vector<int> arr, int k) {
	int zero = 0, i = 0, ans = 0;
	for(int j = 0; j < arr.size(); j++) {
		if(arr[j] == 0)
			zero++;
		while(zero > k) {
			if(arr[i] == 0) {
				zero--;
			}
			i++;
		}
		ans = max(ans, j - i + 1);
	}
	return ans;
}


int main() {

	vector<int> a = {0,1,0,1,0,1,1};
	cout << maxOne(a, 2) << endl;
}

