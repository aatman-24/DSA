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

Question : KMP
Topic : 
Problems :
*/

#define MAX_N 100010
char T[MAX_N], P[MAX_N];
int b[MAX_N];
int n, m;

// O(M).
void kmpPreprocess() {
	int i = 0, j = -1;
	b[0] = -1;
	while(i < m) {
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}


// O(N).
void kmpSearch() {
	int i = 0, j = 0;
	while(i < n) {
		while(j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if(j == m) {
			printf("P is found at index %d in T\n",i - j);
			j = b[j];
		}
	}

}

int main() {
	string s = "ABABAABB";
	m = s.size();
	for(int i = 0;i < s.size(); i++) P[i] = s[i];
	kmpPreprocess();

	for(int i = 0; i < m; i++) {
		cout << s[i] << ' ';
	}
	cout << endl;

	for(int i = 0; i < m; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
}


