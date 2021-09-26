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

Question: 930. Binary Subarrays With Sum
Topic : prefixsum
Problems : https://leetcode.com/problems/binary-subarrays-with-sum/

==============================> Explanation <=============================================
- In this type of question,

1) Brute force: make subarray using two for loop and third loop for the sum.

2) prefix sum with map: Here we perform the prefix sum first(or in running). Idea is that whatever
prefix is sum at that moment we add into the map, so next time we try to get (current - target) into the map.
map store <sum, freq>. Already covered that type of question.

3) Sliding window: Below

==============================> Apporach and Time Complexity <=============================================

1) Brute Force:
Time:O(N^3)
Space:O(1)

2) Prefix sum:
Time:O(N)
Space:O(N)

3) Sliding window:
Time:O(N)
Space:O(1)

*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> mp;
        for(int i = 1; i < nums.size() ; i++)
            nums[i] += nums[i-1];

        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Because it indicate that from (0, i) subarray which is not added into the map.
            // Either perform separately or add the <0:1> entry into the map.
            if(nums[i] == goal) ans++;

            if(mp.count(nums[i] - goal))
                ans += mp[nums[i]-goal];

            mp[nums[i]]++;
        }

        return ans;
    }
};

/*
Sliding window: Direct Sliding window work if there is not any element <= 0. But here 0 can be element so
we need variant of it(some modificiation to standard algorithm).


p p P' 0 0 0 L' l h1 0 0 0 h2 h h

low -> point to the first l
p -> point to the last visited one(1).
h -> point to the next one(1).

So we have problem in which 0 is encounter,

Like here, if there is window (L', h1) then our answer can be,

[0 0 0 L' l h1], [0 0 L' l h1], [0 L' l h1], [L' l h1] -> 4 subarray. So encounter previous zero we keep 
track of P(prev pointer) also.

total subarray is = 1(OG, Last One above) + (low - prev + 1)(Except last one).
And we always make sure that,
low -> point to the first one.
prev -> last low pointer. (initial prev = -1)
high -> next pointer.


Need to handle case when target = 0,
because -> [0 0 0 0] -> 1 + 2 + 3 + 4 -> 10. All the subarrays.
[0 0 1 0 0] -> 1  + 2 + 0 + 1 + 2 -> Reset seq when 1 is encounter.

*/

class Solution {
public:
    int helper(vector<int> &nums) {

        int cnt = 0;
        int res = 0;

        for(int i = 0;  i < nums.size(); i++) {
            if(nums[i] == 0) {
                cnt++;
                res += cnt;             // Seq sum: 1 2 3 4 5 -> [0, 0, 0, 0, 0]
            }
            else {
                cnt = 0;                // Reset the Seq.
            }
        }

        return res;
    }



    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Edge Case
        if(goal == 0)
            return helper(nums);

        int low = 0, high = 0, prev = -1, ans = 0, cur = 0;

        while(low < nums.size() && nums[low] == 0){
            low++; high++;
        }

        while(high < nums.size()) {

            if(cur + nums[high] == goal) {
                cur += nums[high];
                
                // from (low, high)
                ans++;

                // from (prev, high)
                ans += (low - prev - 1);

                high++;
            }
            else if(cur + nums[high] < goal) {
                cur += nums[high];
                high++;
            }
            else {

                // shrink the window
                cur -= nums[low];

                // currnet low become prev.
                prev = low;
                low++;

                // low point to the first one.
                while(nums[low] == 0)
                    low++;
            }
        }

        return ans;
    }
};



/*
Intuition Behind this algorithm is, we first count the subarray which sum is at most K and after that we 
count subarray which sum is at most (K - 1) and subtract it from the previous which result into the subarray
which sum is K.

subarray sum with K = subarray with sum at Most K - subarray with sum at Most K-1.
subarray with sum 2 = subarray with sum at most 2(2, 1, 0) - subarray with sum at most 1(1, 0)
                    = subarray with sum 2


Index: 0 1 2 3 4 5 6 
Array: 0 0 0 1 1 0 0 

K=2  : 1 2 3 4 5(') 6 7 

5 -> [0, 0, 0, 1, 1], [0, 0, 1, 1], [0, 1, 1], [1, 1], [1] (sum at most 2 -> (0, 1, 2))

K=1  : 1 2 3 4 1(') 2 3 

1 -> [1] (last one in above). (sum at most 1 -> (1, 0))

res  : 0 0 0 0 4(') 4 4

4 -> [0, 0, 0, 1, 1], [0, 0, 1, 1], [0, 1, 1], [1, 1] (sum exactly -> 2)
*/



class Solution {
public:

    int sumAtMostK(vector<int>&nums, int K) {

        // If K is negative return 0;
        if(K < 0) return 0;
        
        int l = 0, h = 0, cur = 0, ans = 0;
        
        while(h < nums.size()) {

            cur += nums[h];

            // shrink the window until fit.
            while(cur > K) {
                cur -= nums[l];
                l++;
            }

            // add all the (h - l + 1) subarray which can be made from [l, h] pointer.
            ans += (h - l + 1);

            h++;
        }

        return ans;
    }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sumAtMostK(nums, goal) - sumAtMostK(nums, goal - 1);
    }
};