#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	
	ll N,M,tmp;
	set<ll> st;
	while(cin >> N >> M)
	{
		if(N == 0 && M == 0) break;
		st.clear();
		for(ll i = 0 ; i < N; i++) {cin >> tmp; st.insert(tmp);}
		for(ll i = 0 ; i < M; i++) {cin >> tmp; st.insert(tmp);}
		ll covered  = N + M - st.size();
		cout << covered << endl;

	}


	return 0;
}
