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

Question : 8.8 Wave Sort 
Topic : 
Problems :
*/

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// O(N) - O(1)
void waveSort(int arr[], int n) {

	for(int i = 1; i < n; i+=2) {

		if(arr[i] > arr[i-1])
			swap(arr[i], arr[i-1]);

		if(i <= n - 2 && arr[i] > arr[i+1])
			swap(arr[i], arr[i+1]);
	}

}

int main() {	

	int arr[] =  {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(int);
	waveSort(arr, n);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

