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

Question : World Record
Topic : Math
Problems : https://www.codechef.com/APRIL21C/problems/BOLT
Round : CC April LC Div-3
*/

int main() {

	double k1, k2, k3, v;
	int t; cin >> t;
	while(t--) {
		cin >> k1 >> k2 >> k3 >> v;
		double res = k1 * k2 * k3 * v;
		res = 100 / res;
		res = round(res * 100.0) / 100.0;
		if(float(res) < float(9.58)) cout<<"YES\n";
		else cout <<"NO\n";  
	}	

}

