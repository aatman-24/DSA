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

Question : 167. Two Sum II - Input array is sorted
Topic : Two pointer
Problems : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/


class Solution {
public:

    //O(N^2) - O(1) check for all pairs.


    //O(N) - O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {

        int lft, rht;
        lft = 0;
        rht = numbers.size() - 1;

        while(numbers[lft] + numbers[rht] != target) {

            if(numbers[lft] + numbers[rht] < target) {
                lft++;
            }
            else {
                rht--;
            }
        }
        return vector<int>({lft+1,rht+1});
    }
};