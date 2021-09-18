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

Question: 347. Top K Frequent Elements
Topic : Heap, bucket sort
Problems : https://leetcode.com/problems/top-k-frequent-elements/

==============================> Explanation <=============================================
1) count the frequency using map then put into the heap but we keep heap size upto the k.
So it will take O(N*logK).

2) Bucket sort. Count the frequency first then create the [n+1] bucket and add all the
element into that bucket. bucket[i] -> j means j element has i frequency.
- After that, we start visiting the bucket in decreasing order that is the main reason
we use bucket sort.

==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time: O(NlogK)
Space: O(N)

2) Heap:
Time: O(N)
Space: O(N)


*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // num -> Freq
        unordered_map<int,int> count;
        for(auto n: nums)
            count[n]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: count) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // num -> Freq
        unordered_map<int,int> count;
        for(auto n: nums)
            count[n]++;

        vector<int> bucket[nums.size() + 1];

        for(auto [num, freq]: count) {
            bucket[freq].push_back(num);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--) {
            if(bucket[i].size() > 0) {
                for(auto num: bucket[i]) {
                    ans.push_back(num);
                    k--;
                    if(k == 0)
                        return ans;
                }
            }
        }

        return ans;
    }
};