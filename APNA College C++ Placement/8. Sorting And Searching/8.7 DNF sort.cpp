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

Question : 8.7 DNF sort
Topic : 
Problems :
*/


void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// O(N) - O(1)
void dnfSort(int arr[], int n) {

	int low = 0, mid = 0, end = n - 1;
	while(mid <= end) {

		if(arr[mid] == 0) {
			swap(arr[mid], arr[low]);
			mid++; low++;
		}
		else if(arr[mid] == 1) {
			mid++;
		}
		else {
			swap(arr[mid], arr[end]);
			end--;
		}
	}
}




int main() {	

	int arr[] =  {0,1,1,0,0,2,1,0,1,2,0,2};
	int n = sizeof(arr)/sizeof(int);
	dnfSort(arr, n);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

