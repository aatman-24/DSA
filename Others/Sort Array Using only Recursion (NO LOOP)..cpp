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

Question : Sort Array Using only Recursion (NO LOOP).
Topic : Array
Problems :
*/


void insert(vi &arr, int tmp) {
	if(arr.size() == 0 || arr[arr.size() - 1] <= tmp) {
		arr.push_back(tmp);
		return ;
	}
	int lastEle =  arr[arr.size() - 1];
	arr.pop_back();
	insert(arr, tmp);
	arr.push_back(lastEle);
}

void sort_arr(vi &arr) {
	if(arr.size() == 1) return ;
	int tmp = arr[arr.size() - 1];
	arr.pop_back();
	sort_arr(arr);
	insert(arr, tmp);
}

int main() {
	
	vi arr = {3,1,2,4};
	sort_arr(arr);
	REP(i, 4) {
		cout << arr[i] << ' ';
	}

}