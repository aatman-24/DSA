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
	string S;
	int set, N, K;
	while(t--) {
		cin >> N >> K;
		cin >> S;
		set = 0;
		int cn = 0;
		for(int i = 0; i < N; i++) {
			if(S[i] == '*') {
				cn = 0;
				while(i < N && S[i] == '*') {cn++; i++;}
				if(cn >= K) {set=1; break;}
			}

		}

		if(set) cout << "YES" << endl;
		else cout << "NO" << endl;


	}
}

