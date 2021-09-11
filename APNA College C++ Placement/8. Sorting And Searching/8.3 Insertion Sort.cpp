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

Question : 8.3 Insertion Sort
Topic : 
Problems :
*/


// O(N^2)
void insertionSort(int arr[], int n) {

	for(int i = 1; i < n; i++) {
		int curr = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > curr) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = curr;
	}
}


int main() {

	int arr[] = {3,2,4,5,1};
	insertionSort(arr, 5);
	for(int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;

}

