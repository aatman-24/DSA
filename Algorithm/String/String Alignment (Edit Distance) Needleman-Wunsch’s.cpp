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


/*
Here I constrcut the opreation path from the starting of the string that's why i need one more 2D array.

you can also constrcut from the bottom.


This soultion is not accepted into UVA online judge but it is accepted into UDebug.

bcz there are many solution possible but min cost is same for all.

*/

#define MAX_SIZE 1001

string INSERT = "Insert";
string DELETE = "Delete";
string REPLACE = "Replace";

int INSERTCOST = 1; 
int MATCHCOST = 0;
int MISMATCHCOST = 1;
int DELETECOST = 1;

int dp[MAX_SIZE][MAX_SIZE];
int mark[MAX_SIZE][MAX_SIZE];

int cost(string x, string y, int i, int j) {
	if(x[i] == y[j]) return MATCHCOST;
	return MISMATCHCOST;
}

void find_soultion(string x, string y, int i, int j) {

	if(i == 0 && j == 0) return;

	int insertCost = dp[i][j-1] + INSERTCOST;
	int alignCost = dp[i-1][j-1] + cost(x, y, i-1, j-1);
	int deleteCost = dp[i-1][j] + DELETECOST;

	int best = min({insertCost, alignCost, deleteCost});

	if(j >= 1 && best == insertCost) {
		mark[i][j-1] = 1;
		find_soultion(x, y, i, j-1);
	}
	else if(i >= 1 && j >= 1 && best == alignCost) {
		mark[i-1][j-1] = 1;
		find_soultion(x, y, i-1, j-1);
	}
	else {
		mark[i-1][j] = 1;
		find_soultion(x, y, i-1, j);
	}
}

vector<string> make_soultion(string x, string y) {

	vector<string> sol;
	

	int n = x.size(), m = y.size();

	memset(mark, 0, sizeof(mark));
	mark[0][0] = mark[n][m] = 1;

	find_soultion(x,y,n,m);


	int i = 0, j = 0;
	int pos = 1;

	while(i != n || j != m) {

		if(i+1 <= n && mark[i+1][j] == 1) {
			sol.push_back(DELETE + ' ' + to_string(pos));
			i++;
		}
		else if (j+1 <= m && mark[i][j+1] == 1) {
			sol.push_back(INSERT + ' ' + to_string(pos) + ',' + y[j]); 
			pos++;
			j++;
		}
		else if (i <= n && j <= m && mark[i+1][j+1] == 1) {
			if(x[i] != y[j]) sol.push_back(REPLACE + ' ' + to_string(pos) + ',' + y[j]); 
			i++; j++;
			pos++;
		}
	}
	return sol;
}



vector<string> alignment(string x, string y) {

	int n = x.size();
	int m = y.size();

	memset(dp,0,sizeof(dp));

	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int j = 0; j <= m; j++) dp[0][j] = j;


	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = min({dp[i-1][j-1] + cost(x,y,i-1,j-1), dp[i-1][j] + DELETECOST, dp[i][j-1] + INSERTCOST});
		}
	}
	return make_soultion(x,y);
}


int main() {



	string x,y;
	x = "ACAATCC";
	y = "AGCATGC";

	vector<string> res = alignment(x, y);

	cout << "min opration " <<  res.size() << endl;
		

	return 0;
}
