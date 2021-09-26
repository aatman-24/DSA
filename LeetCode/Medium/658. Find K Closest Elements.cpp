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

Question: 658. Find K Closest Elements
Topic : maxHeap, Two Pointer, binary Search
Problems : https://leetcode.com/problems/find-k-closest-elements/

==============================> Explanation <=============================================
1) Brute-Force: Using Two For loops, (i - j) == k and check that arr[i]-arr[j] is best
window or not.

2) Using Priority Queue: Focus on how to get best promising value from the PQ.
Make a fucntion or comparator, 

MinHeap, Reverse Compartor,
if(x - a) == (x - b) then, a > b,
return (x - a) > (x - b).

Maintain only most promising K element into the queue.

3) Two Pointer:
- maintain the window of k size atleast.
- check, between arr[low], arr[high] whose is farest, whoever is farest we make it close
either by low++, high--.


4) Binary Search:

-Here array is sorted, so think about binary search apporach,

Idea, Which single element is close to the X. This type of question we used BS. So
Why not here ?

Assume we are taking A[i] ~ A[i + k -1].
We can binary research i
We compare the distance between x - A[mid] and A[mid + k] - x

Assume A[mid] ~ A[mid + k] is sliding window,


- A[mid+k] is out of window next element not the last element of window.

case 1: x - A[mid] < A[mid + k] - x, need to move window go left
-------x----A[mid]-----------------A[mid + k]----------

case 2: x - A[mid] < A[mid + k] - x, need to move window go left again
-------A[mid]----x-----------------A[mid + k]----------

case 3: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]------------------x---A[mid + k]----------

case 4: x - A[mid] > A[mid + k] - x, need to move window go right
-------A[mid]---------------------A[mid + k]----x------

If x - A[mid] > A[mid + k] - x,
it means A[mid + 1] ~ A[mid + k] is better than A[mid] ~ A[mid + k - 1],
and we have mid smaller than the right i.
So assign left = mid + 1.

==============================> Apporach and Time Complexity <=============================================




1) Brute-Force:
Time: O(N^2)
Space: O(1)

2) MaxHeap:
Time: O(NlogK)
Space: O(K)

3) Two Pointer:
Time: O(N)
Space: O(1)

4) Binary Search:
Time: O(log(N-K) + K)
Space: O(1)

*/


class compare {
public:

    // maxHeap, condition for minHeap.
    bool operator() (pair<int,int> &a, pair<int,int> &b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

class Solution {
public:
       vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // maxHeap
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(auto it: arr) {
            pq.push({abs(it-x), it});
            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans(k, 0);
        while(!pq.empty()) {
            ans[--k] = pq.top().second; pq.pop();
        }

        // sort the answer.
        sort(ans.begin(), ans.end());

        return ans;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int low = 0, high = arr.size() - 1;

        while(high-low+1 > k) {
        
            if(abs(arr[low]-x) <= abs(arr[high]-x)) {
                high--;
            }
            else {
                low++;
            }
        }

        vector<int> answer;
        for(int i = low; i <= high; i++) {
            answer.push_back(arr[i]);
        }

        return answer;
    }
};


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int low = 0, high = arr.size() - k;
        
        while(low < high) {
            
            int mid = (low+high) >> 1;

            if(x-arr[mid] >  arr[mid+k]-x) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        vector<int> answer;
        for(int i = low; i < low+k; i++) {
            answer.push_back(arr[i]);
        }

        return answer;
    }
};

