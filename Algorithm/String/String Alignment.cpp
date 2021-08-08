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

Question : String Alignment (Edit Distance) Needleman-Wunsch’s
Topic : 
Problems :
*/


#define MAX_SIZE 1001

string INSERT = "INSERT_ ";
string ALIGN = "ALIGN_ ";
string DELETE = "DELETE_ ";

int dp[MAX_SIZE][MAX_SIZE];


int cost(string x, string y, int i, int j) {
	if(x[i] == y[j]) return 0;
	return 1;
}


void find_soultion(string x, string y, int i, int j, vector<string> &soultion) {

	if(i == 0 || j == 0) return ;

	int insert = dp[i][j-1] + 1;
	int align = dp[i-1][j-1] + cost(x, y, i-1, j-1);
	int delete_ele = dp[i-1][j];

	string INSERT = "INSERT_ ";


	int best = min({insert, align, delete_ele});

	string tmp_ans;

	if(best == insert) {
		soultion.push_back(INSERT + y[j-1]);
		find_soultion(x, y, i, j-1, soultion);
	}
	else if(best == align) {
		soultion.push_back(ALIGN + y[j-1]);
		find_soultion(x, y, i-1, j-1, soultion);
	}
	else {
		soultion.push_back(DELETE + x[i-1]);
		find_soultion(x, y, i-1, j, soultion);
	}
}

int alignment(string x, string y) {

	int n = x.size();
	int m = y.size();

	memset(dp,0,sizeof(dp));


	// Adding space into X -> means delete substring[1,i] into X.
	for(int i = 0; i <= n; i++) dp[i][0] = i;

	// Inserting space into Y
	for(int j = 0; j <= m; j++) dp[0][j] = j;

	// (Matching | Delete | Insert )

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {


			dp[i][j] = min({dp[i-1][j-1] + cost(x,y,i-1,j-1), dp[i-1][j] + 1, dp[i][j-1] + 1});
		}
	}

	vector<string> sol;
	find_soultion(x,y,n,m,sol);

	REP(i,sol.size()) {
		cout << sol[i] << endl;
	}

	return dp[n][m];
}


int main() {

	string x = "ACAATCC";
	string y =  "AGCATGC";
	cout << alignment(x, y) << endl;

	return 0;
}
