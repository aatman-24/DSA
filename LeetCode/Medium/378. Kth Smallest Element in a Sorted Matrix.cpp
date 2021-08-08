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
d
/*
==============================> Description <=============================================

Question : 378. Kth Smallest Element in a Sorted Matrix
Topic : Binary Search
Problems : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

==============================> Explanation <=============================================
- From Median of Sorted Matrix but there is no rule that median comes from the 
matrix.


But here kth element need to be from the matrix. So how can you converge it?

- So when the count >= k. (that time we update high = mid). Because at mid 
we found the k or greater than k element so our answer still be in [low, mid].

- If count < k. That time we update the, low = mid + (low == mid). To avoid the
TLE because if low == mid. Then it trapped into the INFINITE loop. So when the low == mid
increment the low = mid + 1. Otherwise low = mid. 

- So doing this when the mid is greater than answer it goes to second else clause 
which gurantee us it only converge to the element which is from the matrix.


At last low is our answer because where the algorithm stop is low < high. 

Time = O(N*M) + O(N*log(MAX-MIN))


2) Second Solution:
- Use PQ. And add first element from all the Row. and Then keep track of num which
we pop. And add the next element from the same row which is pop. Doing the same
thing until you found the kth element.




*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


      struct numCompare {
        bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
          return x.first > y.first;
        }
      };


      // 1) Priority Queue = Space O(N) + Time same.

      static int findKthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;

        // put the 1st element of each row in the min heap
        // we don't need to push more than 'k' elements in the heap
        for (int i = 0; i < n && i < k; i++) {
          minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }

        // take the smallest element form the min heap, if the running count is equal to k return the number
        // if the row of the top element has more elements, add the next element to the heap
        int numberCount = 0, result = 0;
        while (!minHeap.empty()) {
          auto heapTop = minHeap.top();
          minHeap.pop();
          result = heapTop.first;
          if (++numberCount == k) {
            break;
          }

          heapTop.second.second++;
          if (n > heapTop.second.second) {
            heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
            minHeap.push(heapTop);
          }
        }
        return result;
      }




    int lessThanOrEqualToK(vector<vector<int>>& matrix, int k) {

        int lessThanOrEqualToKEle = 0;
        for(vector<int> A: matrix) {
            int ele = upper_bound(A.begin(), A.end(), k) - A.begin();
            lessThanOrEqualToKEle += ele;
        }

        return lessThanOrEqualToKEle;
    }


    // Optimal Solution
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int min = INT_MAX, max = INT_MIN;
        for(vector<int> A: matrix) {
            for(int ele: A) {
                if(ele > max) {
                    max = ele;   
                }
                if(ele < min) {
                    min = ele;
                }
            }
        }


        int l = min, h = max;

        while(l < h) {

            int mid = (l + h) >> 1;

            if(lessThanOrEqualToK(matrix,mid) >= k) {  
            // converge the mid into the matrix. Found Equal to K that means our
            // element either in matrix or not into matrix but greater than answer.
            // 12 13 15 (but mid = 14) which is kth element also but not into matrix.
                h = mid;
            }


            else {
                // So when the mid is greater than answer. That time we change the 
                // h = mid. So again it goes to the left side. Now Using this 
                // clause it goes to right side slowly. When there is two element
                // 12 13 (l = 12, h = 13, mid = 12) that time don't again and again
                // mid become 12 for that add 1. So it either goes above clause
                // or our answer.
                l = mid + (l == mid);
            }

        }

        return l;

    }

};