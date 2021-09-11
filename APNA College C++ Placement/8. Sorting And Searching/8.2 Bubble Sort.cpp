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

Question : 8.2 Bubble Sort 
Topic : 
Problems :
*/

// Find the first kth large/small Number in array = O(N*K)


// O(N^2)
void bubbleSort(int arr[], int n) {
	int cnt = 0;
	while(cnt < n) {
		for(int i = 0; i < n - cnt; i++) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		cnt++;
	}
}


int main() {

	int arr[] = {3,2,4,5,1};
	bubbleSort(arr, 5);
	for(int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;

}

