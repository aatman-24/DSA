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

Question : 8.6 Count Sort
Topic : 
Problems :
*/

// Max number from the array you want to sort
int MAX_SIZE = 100;

// O(max(N,maxEle)) - O(maxEle)
void countSort(int arr[], int n) {

	// Find Max element from the array.
	int maxEle = arr[0];
	for(int i = 0; i < n; i++) 
		maxEle = max(maxEle, arr[i]);

	// Create new count array of max element size.
	// but in c++ array dynamic memory of array size is not allowed. 
	int count[MAX_SIZE] = {0};
	for(int i = 0; i < n; i++)
		count[arr[i]]++;

	// sum up the count array for first position of element.
	for(int i = 1; i <= maxEle ; i++)
		count[i] += count[i-1];

	// store the result into new array.
	int output[n];
	for(int i = n-1; i >= 0; i--) 
		output[--count[arr[i]]] = arr[i];

	// copy the output into given array.
	for(int i = 0; i < n; i++)
		arr[i] = output[i];
}


int main() {	

	int arr[] =  {3,2,4,1,5,8,3};
	int n = sizeof(arr)/sizeof(int);
	countSort(arr, n);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

