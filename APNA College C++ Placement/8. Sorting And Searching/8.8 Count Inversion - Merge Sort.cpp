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

Question : 8.8 Count Inversion - Merge Sort
Topic : 
Problems :
*/


// What is inversion ? -> if i < j and arr[i] > arr[j] then this is one inversion.

// Method - 1: Brute force O(N^2)
// Using Two loop count all inversion.
ll countInversion(int arr[], int n) {
	ll inv = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
				inv++;
			}
		}
	}
	return inv;
}

ll merge(int arr[], int l, int m, int r) {

	ll inv = 0;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int a[n1], b[n2];
	for(int i = 0; i < n1; i++) a[i] = arr[i+l];
	for(int i = 0; i < n2; i++) b[i] = arr[i+m+1];

	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2) {
		if(a[i] <= b[j]) {
			arr[k] = a[i];
			i++; k++;
		}
		else {
			inv += (n1 - i);		// Here we count inversion.
			arr[k] = b[j];
			j++; k++;
		}
	}

	while(i < n1) {
		arr[k] = a[i];
		k++; i++;
	}

	while(j < n2) {
		arr[k] = b[j];
		j++; k++;
	}

	return inv;
}


// Method-2: O(NlogN) 
ll mergeSortInversion(int arr[], int l, int r) {

	ll inv = 0;

	if(l < r) {

		int m = (l+r)/2;
		inv += mergeSortInversion(arr, l, m);
		inv += mergeSortInversion(arr, m+1, r);
		inv += merge(arr, l, m, r);
	}
	return inv;
}


int main() {	

	int arr[] =  {3,5,6,9,1,2,7,8};
	int n = sizeof(arr)/sizeof(int);
	cout <<  mergeSortInversion(arr, 0, n-1) << endl;

}

