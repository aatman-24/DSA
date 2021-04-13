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

Question : Strong Language
Topic : String
Problems : https://www.codechef.com/APRIL21C/problems/SSCRIPT
Round : CodeChef April Long Challange Div-3
*/

int main() {
	int t; cin >> t;
	int ansArr[] = {1, 6, 12};
	int N;
	while(t--) {
		cin >> N;
		if(N < 4) {
			cout << (N*21) - ansArr[N-1] << endl;
		}
		else {
			int k = 0;
			if(N % 4  == 1) k = 5;
			else if(N % 4 == 2) k = 14;
			else if(N % 4 == 3) k = 24;
			int ans = N * 21 - (N/4)*(8) + 16  - k;
			cout << ans << endl;
		} 
	}
}

