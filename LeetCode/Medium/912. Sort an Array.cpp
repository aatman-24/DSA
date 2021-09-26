#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007
#define eps 1e-6

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

Question: 912. Sort an Array
Topic : Merge Sort
Problems : https://leetcode.com/problems/sort-an-array/

==============================> Explanation <=============================================

- All Sorting Algorithm.

==============================> Apporach and Time Complexity <=============================================


1) Merge Sort:
Time: O(NlogN)
Space: O(N)

*/


class Solution {
public:
    
    void merge(vector<int>&arr, int low, int mid, int high) {

        int n1 = mid - low + 1;
        int n2 = high - mid;

        int left[n1], right[n2];
        for(int i = 0; i < n1; i++) left[i] = arr[low+i];
        for(int i = 0; i < n2; i++) right[i] = arr[mid+1+i];
        
        int i = 0, j = 0, k = low;

        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
    
        while(i < n1) {
            arr[k++] = left[i++];
        }

        while(j < n2) {
            arr[k++] = right[j++];
        }
    }


    void mergetSort(vector<int>&arr, int low, int high) {

        if(low < high) {
            int mid = (low + high) >> 1;
            mergetSort(arr, low, mid);
            mergetSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergetSort(nums, 0, nums.size()-1);
        return nums;
    }
};