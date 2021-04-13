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

Question : 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
Topic : Greedy
Problems : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

class Solution {
    
int INT_BASE = 48;

public:
    int minPartitions(string s) {

        int ans = -1;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            ans = max(s[i]-INT_BASE, ans);
        }
        return ans;
    }
};	


int main() {

	Solution ob;
	string N;
	while(cin >> N) {
		cout << ob.solve(N) << endl;
	}

}