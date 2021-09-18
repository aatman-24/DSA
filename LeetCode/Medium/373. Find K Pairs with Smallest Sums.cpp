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

Question: 373. Find K Pairs with Smallest Sums
Topic : Priority queue
Problems : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
==============================> Explanation <=============================================
N = nums1.length, M = nums2.length

1) Brute Force: Create a vector of pairs such that it contains total N*M all pairs.
Sort it based on sum. And select K pairs from the start.

2) Brute Force with PQ: Add all the Pairs into the PQ and pop the top most K pairs
from that which is our answer.

3) Priority Queue + Set(Visited)(Extra Space):

- Simple start with adding (0, 0) pair into the queue.
- And when we pop the rightmost candidate from the pq (i, j). We 
add the (i+1, j) and (i, j+1) pair into the queue.
Because it gurantee that if current pair (i, j) is the best right candidate then
next will be either (i+1, j) or (i, j+1) which ever is minimum.

Problem with this apporach is that, same pair visited two times

(0, 0) -> (0,1), (1, 0)
(1, 0) -> (1, 1), (2, 0)
(0, 1) -> (1, 1), (0, 2) (here (1, 1) is visited two times.)

So avoid it use either map, set anything to avoid duplicate entry into the pq.



4) PQ + Avoid using Visited(Set) Extra Space:

- Now how to avoid using extra space for visited(set). So for that
what we do is we first add (x, 0) where, 0 <= x < k.

Adding (nums1[x], nums2[0]) entry upto the k or n which every is minimum. 

- Now this entry give us assurance that, 

if (i, x) is take out of queue then and only (i, x+1) entry is added into the
queue. Because at every time (i, x) is best choise then (i, x+1) bcz sum is less.

- And we already added first entry of every linkedlist so we don't need to handle
(i+1, j) case it is already added.

Example..

{1 7 11 16}, {2, 9, 10, 15} is given two list,

(1,2) -> (1,9) -> (1,10) -> (1,15)
(7,2) -> (7,9) -> (7,10) -> (7,15)
(11,2) -> (11,9) -> (11,10) -> (11,15)
(16,2) -> (16,9) -> (16,10) -> (16,15)

(1, 2)
(7, 2)
(11, 2)
(16, 2)

is added into the queue and every time any entry is popped (i, j+1) needs to add
only. because (i+1, j) is already into the queue if it best choise then.

==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(N*M)(Generate pair) + O(N*M*log(N*M))(Sort the pair)
Space: O(N*M)

2) Brute Force with PQ
Time: O(N*M) + O(N*M*log(N*M))(Added all the pair into the PQ)
Space: O(N*M)

3) Priority Queue + Set(Visited)(Extra Space):
Time: O(KlogK)
Space: O(K) + O(K)(Visited)

4) PQ + Avoid using Visited(Set) Extra Space:
Time: O(KlogK)
Space: O(K)

*/


class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({nums1[0]+nums2[0], 0, 0});

        set<pair<int,int>> st;
        st.insert({0, 0});

        while(!pq.empty()) {

            auto it = pq.top(); pq.pop();
            int i = it[1], j = it[2];
            ans.push_back({nums1[i], nums2[j]});

            if(--k == 0)
                return ans;

            if(i + 1 < m && !st.count({i+1, j})) {
                pq.push({nums1[i+1]+nums2[j], i+1, j});
                st.insert({i+1, j});
            }

            if(j + 1 < n && !st.count({i, j+1})) {
                pq.push({nums1[i]+nums2[j+1], i, j+1});
                st.insert({i, j+1});

            }
        }

        return ans;
    }
};

class Solution {
public:
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        int m = nums1.size(), n = nums2.size();

        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i = 0; i < min(m, k); i++) {
            pq.push({nums1[i]+nums2[0], i, 0});
        }


        while(!pq.empty()) {

            auto it = pq.top(); pq.pop();
            int i = it[1], j = it[2];
            ans.push_back({nums1[i], nums2[j]});

            if(--k == 0)
                break;

            if(j + 1 < n)
                pq.push({nums1[i]+nums2[j+1], i, j+1});

        }

        return ans;
    }
};