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

Question: 1985. Find the Kth Largest Integer in the Array
Topic : Sorting, PQ
Problems : https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

==============================> Explanation <=============================================
1) Add Element into the pq using comparator. Top most element is our answer.

2) Inplace sorting.

==============================> Apporach and Time Complexity <=============================================
N = length of array.
M = maximum string length. M = 100.

1) Inplace Sorting:
Time: O(N*logN*M)    -> Sort with respect to all the elements.
Space: O(1)


2) Heap:
Time: O(N*logK*M)   -> Sort on only on K most promising elements.
Space: O(K)
 


*/

class NumStrMinComparator {
public:
    bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrMinComparator> minHeap;
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};



class Solution {
public:
    
    static bool sort_func(string &n1, string &n2) {
        if(n1.size() > n2.size())
            return true;

        if(n1.size() < n2.size())
            return false;
    
        return n1 > n2;
    }

    string kthLargestNumber(vector<string>& nums, int k) {

        sort(nums.begin(), nums.end(), sort_func);

        return nums[k-1];
    }
};
