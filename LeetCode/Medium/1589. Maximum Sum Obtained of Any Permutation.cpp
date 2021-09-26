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

Question: 1589. Maximum Sum Obtained of Any Permutation
Topic : prefixSum, Sweep Line
Problems :  https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

==============================> Explanation <=============================================
- Ideas is clear that,

We have power to take any permutation of array. So Simple Which index is overlapped more time, we assign
that index highest number from the array...  and so on Greedy Manner.Because permutation means that we 
can put any element of the index at any order but all elements must have one index.

1) Brute Force: (TLE)
- Simple, make freq[n] = {0},
-for every request increse the count of the index from request[0] -> request[1].
-sort both freq and nums array.
-(freq[i] * nums[i]) (Hightest number with highest freq) until freq[i] > 0.

2) Prefix Array(Sweep Line):

How ???

1) Imagine that you had intervals [1:3], [3:5].

2) For each mark boundaries only to avoid complexity raise (TLE) on a wide interval as you 
do nothing with values inside the interval and ignore it quantity.

t[start] +=1 means every index after this one will be counted 1 more time,
t[end+1] -= 1, means every index this one will be counted 1 less time

after [1:3] : [0, 1(+1), 0, 0, -1(-1), 0, 0]

after [3:5] : [0, 1, 0, 1(+1), -1, 0, -1(-1)]

3)Then after all intervals start|end+1 marking we can set the final frequency in one pass.
So the prefix sum of t will correspond to the number of requests for each index.

for i in range(1, n):
    count[i] += count[i - 1]

It will become
[0, 1, 0, 1, -1, 0, -1] -> [0, 1, 1, 2, 1, 1, 0]



4)As you can see 3rd element occurred 2 times 1,2,4,5 1 time and others 0 time

In short, 

[start: end] -> freq[start]++, freq[end+1]--;

                After performing prefix sum give,,,   freq[start] -> freq[end] is added by one. And after freq[end] again will
                be the same due to freq[end+1]--. (1 - 1) = 0.



This trick is called Sweep Line.



Other Greedy Approach is Same..



==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2) -> TLE here, N = 10^5.
Space: O(N) 

2) Prefix Sum Construction(Sweep Line):
Time:O(N)
Space:O(N)

*/


#define mod 1000000007


class Solution {
public:
    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n = nums.size();

        vector<int> freq(n, 0);

        for(auto it: requests) {                // O(N^2) -> TLE, N = 10^5.
            for(int i = it[0]; i <= it[1]; i++) {
                freq[i]++;
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(freq[i] > 0) {
                 ans += (long)freq[i] * (long)nums[i]; 
                 ans = ans % mod;
            }
            else {
                break;
            }
        }


        return ans;
    }
};



#define mod 1000000007

class Solution {
public:
    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n = nums.size();
        vector<int> freq(n, 0);

        for(auto it: requests) {
            int left = it[0], right = it[1];

            // add +1 for freq[left, n]
            freq[left]++;

            // subtract -1 from freq[right+1, n]
            if(right + 1 < n) freq[right+1]--;

            // overall in freq[left, right] will be added 1.
        }

        // Perform prefix-sum
        for(int i = 1; i < n; i++) {
            freq[i] += freq[i-1];
        }
        

        // Greedy Apporach, Highest Freq of number will be assigning the greater number from nums[i]...
        sort(nums.begin(), nums.end(), greater<int>());
        sort(freq.begin(), freq.end(), greater<int>());

        int i = 0;
        long ans = 0;
        while(i < n && freq[i] > 0) {
            ans += (long)freq[i] * (long)nums[i]; 
            ans = ans % mod;
            i++;
        }

        return ans;
    }
};