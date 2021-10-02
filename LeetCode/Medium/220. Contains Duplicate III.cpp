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

Question: 220. Contains Duplicate III
Topic : Bucket, Two Poninter
Problems : https://leetcode.com/problems/contains-duplicate-iii/

==============================> Explanation <=============================================

- Bucket Sort + Two Pointer.

- We create bucket which can hold (0...k) elements which has differnce at most k.
- Using Two pointer we remove the element from the bucket which is outdated.

https://leetcode.com/problems/contains-duplicate-iii/discuss/824578/C%2B%2B-O(N)-time-complexity-or-Explained-or-Buckets-or-O(K)-space-complexity

==============================> Apporach and Time Complexity <=============================================
2) Bucket Sort + Two Pointer:
Time: O(N)
Space: O(K)

*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();

        if(n == 0 || k < 0 || t < 0) return false;

        unordered_map<int,int> buckets;

        for(int i = 0; i < n; i++) {


            // (t+1) buckets reason is that, differnce can be 0,1,..t ->(t+1).
            int bucket = nums[i] / ((long)t+1);

            if(nums[i] < 0)
                bucket--;

            // same bucket has any elements.
            if(buckets.count(bucket)) {
                return true;
            }
            else {

                // put the current one into the bucket.
                buckets[bucket] = nums[i];

                // check neighbor bucket have the element for which abs(nums[i]-nums[j]) <= t.
                if(buckets.count(bucket-1) && (long)nums[i] - buckets[bucket-1] <= t) return true;
                if(buckets.count(bucket+1) && buckets[bucket+1] - (long)nums[i]  <= t) return true;

                // If bucket contain more than k elements. Then we remove the bucket
                // which has key nums[i-k]/(t+1). Because this bucket violate the abs(i-j) <= k from
                // now on.
                if(buckets.size() > k) {
                    int key_to_remove = nums[i-k] / ((long)t + 1);
                    if(nums[i-k] < 0)
                        key_to_remove--;
                    buckets.erase(key_to_remove);
                }
            }
        }
        
         return false;
    }

};