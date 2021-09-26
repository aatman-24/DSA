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

Question: 973. K Closest Points to Origin
Topic : Heap, QuickSelect
Problems : https://leetcode.com/problems/k-closest-points-to-origin/

==============================> Explanation <=============================================

Parent Question: 347. Top K Frequent Elements

1) Offline Apporach. Sort the points based on distance and select top K from its.

2) Min Heap: Add all the elements into the heap. Which take O(NLogN) time. AFter
pop the K element from it O(logK).

3) Max Heap: Use Max Heap and maintain the size if pq.size() > k then pop the element.
O(NlogK). .

4) Quick Select. Ideas from the 215. Kth Largest Element in an Array. Used Quicksort
parition method to make decision.


==============================> Apporach and Time Complexity <=============================================
M = Longest string length.

1) Brute Force:
Time: O(NLogN)
Space: O(N)

2) MinHeap:
Time: O(NlogN) + O(logK)
Space: O(N)


3) MaxHeap:
Time: O(NlogK)
Space: O(N)

4) Quick Select:
Time: Ave -> O(N), Worst -> O(N^2) 
Space: O(1)


*/


class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // maxHeap.
        priority_queue<vector<int>, vector<vector<int>>> pq;
        
        for(auto point: points) {
            pq.push({point[0]*point[0] + point[1]*point[1], point[0], point[1]});
            if(pq.size() > k) 
                pq.pop();
        }

        vector<vector<int>> answer;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            answer.push_back({it[1], it[2]});
        }

        return answer;

    }
};


class Solution {
public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int low = 0, high = points.size() - 1;
        while(low <= high) {
            
            int pivot = partition(points, low, high);
            
            // (0, pivot(k-1)) found that [0, k-1] are smallest compare to [k, n-1] elements.
            if(pivot == k - 1)
                break;

            // pivot < k - 1 means on left side smallest number is not k still we need some
            // other smallest number to make it k.
            else if(pivot < k - 1) {
                low = pivot + 1;
            } 

            // number on left side which is smallest are more than k need to shrink its.
            else {
                high = pivot - 1;
            }
        }

        vector<vector<int>> answer;
        for(int i = 0; i < k; i++) {
            answer.push_back(points[i]);
        }

        return answer;

    }

    int compare(vector<int> &p1, vector<int> &p2) {
        return p1[0]*p1[0]+p1[1]*p1[1] - p2[0]*p2[0]-p2[1]*p2[1];
    }

    int partition(vector<vector<int>> &points, int low, int high) {
        int pivot = low;
        while(low <= high) {
            while(low <= high && compare(points[pivot], points[low]) >= 0) low++;
            while(low <= high && compare(points[pivot], points[high]) < 0) high--;
            if(low > high)
                break;
            swap(points[low], points[high]);
        }

        // high index hold the last smallest or equal number then points[pivot]. 
        // And also indicate (0, high) numbers are less or equal then points[pivot]. 
        swap(points[pivot], points[high]);
        return high;
    }
};