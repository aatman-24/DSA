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

Question : 8.4 Merge Sort
Topic : 
Problems :
*/

// merge two array inplace
void merge(int arr[], int l, int mid, int r) {

	int n1 = mid - l + 1;	// +1 bcz we consider mid element.
	int n2 = r - mid;		

	int a[n1], b[n2]; // make two tmp array
	for(int i = 0; i < n1; i++) a[i] = arr[l+i];  
	for(int i = 0; i < n2; i++) b[i] = arr[mid+1+i];

	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {

		if(a[i] <= b[j]) {
			arr[k] = a[i];
			i++; k++;
		}
		else {
			arr[k] = b[j];
			j++; k++;
		}
	}

	// remaining element
	while(i < n1) {
		arr[k] = a[i];
		i++; k++;
	}

	while(j < n2) {
		arr[k] = b[j];
		j++; k++;
	}
}

void mergeSort(int arr[], int l, int r) {

	if(l < r) {
		int mid = (l+r)/2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);	
	}

}


int main() {

	int arr[] = {3,2,4,5,1};
	mergeSort(arr,0,4);
	for(int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;

}

