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

Question : 8.5 Quick Sort
Topic : 
Problems :
*/



void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int arr[], int l, int r) {

	int pivot = arr[r];
	int i = l-1;
	for(int j = l; j < r; j++) {
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}


void quickSort(int arr[], int l, int r) {

	if(l < r) {
		int pi = partition(arr, l, r);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi+1, r);
	}

}


int main() {

	int arr[] = {3,2,4,5,1};
	quickSort(arr, 0, 4);
	for(int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;

}

