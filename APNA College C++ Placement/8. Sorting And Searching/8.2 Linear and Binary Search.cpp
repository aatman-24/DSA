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

Question : 8.2 Searching in Arrays | Linear and Binary Search
Topic : 
Problems :
*/

// O(N)
int linearSearch(int arr[], int key, int n) {
	for(int i = 0; i < n; i++) {
		if(arr[i] == key) return i;
	}
	return -1;
}

// O(N*logN)
int binarySearch(int arr[], int key, int n) {
	int start = 0;
	int end = n;

	while(start <= end) {
		int mid = (start+end)/2;

		if(arr[mid]==key) {
			return mid;
		}
		else if(arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int main() {

	int arr[] = {1,2,3,4,5};
	cout << linearSearch(arr, 4, 5) << endl;
	cout << binarySearch(arr, 4, 5) << endl;
	return 0;

}

