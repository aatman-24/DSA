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

Question : Naive-Matching.
Topic : 
Problems :
*/

// O(NM).
void naiveMatching(string T, string P) {
	int n = T.size();
	int m = P.size();

	for(int i = 0; i < n; i++) {
		bool found = true;

		for(int j = 0; j < m && found; j++) {
			if(i + j >= n || T[i+j] != P[j]){
				found = false;
			}
		}

		if(found) {
			printf("P is found at index %d in T\n",i);
		}
	}
}



int main() {
	naiveMatching(s, "Worl");
}


