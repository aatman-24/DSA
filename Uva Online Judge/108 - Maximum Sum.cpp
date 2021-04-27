#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;
/*
==============================> Apporach <=============================================

Question : 108 - Maximum Sum
Topic : DP(kadane - variants), max2DRangeSum.
*/

int arr[101][101];

int max2DRangeSum(int n) {

	// REP(i,n) {
	// 	REP(j,n) cout << arr[i][j] << ' ';
	// 	cout << endl;
	// }

	int sumRect, ans = -127*100*100;
	REP(s_i,n) REP(s_j,n) {
		for(int e_i = s_i; e_i < n; e_i++) {
			for(int e_j = s_j; e_j < n; e_j++) {
				sumRect = arr[e_i][e_j];
				if(s_i > 0) sumRect -= arr[s_i-1][e_j];
				if(s_j > 0) sumRect -= arr[e_i][s_j-1];
				if(s_i > 0 && s_j > 0) sumRect += arr[s_i-1][s_j-1];
				ans = max(ans, sumRect);
			}
		}
	}
	return ans;
}



int main() {


	int n;
	 while(cin >> n){
	 		REP(i,n) REP(j,n) {
			cin >> arr[i][j];

			if(i > 0) arr[i][j] += arr[i-1][j];
			if(j > 0) arr[i][j] += arr[i][j-1];
			if(i > 0 & j > 0) arr[i][j] -= arr[i-1][j-1];
		}

		cout << max2DRangeSum(n) << endl;
		
	 }
	
}