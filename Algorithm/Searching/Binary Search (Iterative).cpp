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

Question : Binary Search (Iterative).
Topic : 
Problems :
*/


// O(logN)
int binarySearch(int arr[], int n, int key) {
	int s = 0;
	int e = n;
	while(s <= e) {
		int mid = (s + e)/2;
		if(arr[mid] == key) return mid;
		else if(key < arr[mid]) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return -1;
}
