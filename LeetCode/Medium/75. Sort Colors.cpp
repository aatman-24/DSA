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

Question : 75. Sort Colors
Topic : Two pointer
Problems : https://leetcode.com/problems/sort-colors/
*/
// https://en.wikipedia.org/wiki/Dutch_national_flag_problem


class Solution {
public:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

// sort 0 at left and 2 at right. 1 is sort by his self. (TWO POINTER) O(2N).
  void sortColors(vi &arr) {
    int second = arr.size()-1; int zero = 0;
    for(int i = 0; i <= second; i++) {
        while(i < second && arr[i] == 2) swap(arr[i], arr[second--]);
        while(i > zero && arr[i] == 0) swap(arr[i], arr[zero++]);
    }
}




// two pass O(m+n) space
void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}




    // Three Pointer. O(N).
    void sortColors(vi &arr) {

        int i_start, j_start, k_start;
        int i_count, j_count, k_count;
        int i_end, j_end, k_end;

        i_count = j_count = k_count = 0;

        REP(i, arr.size()) {
            if(arr[i] == 0) i_count++;
            else if(arr[i] == 1) j_count++;
            else k_count++;
        }

        i_start = 0;
        i_end = j_start = i_start + i_count;
        j_end = k_start = j_start + j_count;
        k_end = k_start + k_count;

        while(i_start != i_end || j_start != j_end || k_start != k_end ) {

            while(i_start < i_end && arr[i_start] == 0) i_start++;

            while(j_start < j_end && arr[j_start] == 1) j_start++;
            if(j_start < j_end && arr[j_start] == 0) {
                    swap(arr[i_start], arr[j_start]);
                    i_start++;
            }

            while(k_start < k_end && arr[k_start] == 2) k_start++;

            if(k_start < k_end && arr[k_start] == 0) {
                    swap(arr[i_start], arr[k_start]);
                    i_start++;
            }
            if(k_start < k_end && arr[k_start] == 1) {
                    swap(arr[j_start], arr[k_start]);
                    j_start++;
            }
        }
    }


};


