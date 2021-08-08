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

Question : 862. Shortest Subarray with Sum at Least K
Topic : Sliding Window
Problems : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
/*
==============================> Explanation <=============================================
209. Minimum Size Subarray Sum - Into this problem only positive integer is given. Normal sliding
window work. 

But in this probelm negative integer is given so that's why it does not work here.
The reason is that in normal silding window we increase the begin pointer when the sum >= k
and try to find best possible window. But it does not work here.

-34 37 51 3 -12 -50 51 100 and k = 151.
-34 + 37 + 51 + 3 - 12 - 50 + 51 + 100 = 146.. while we already see that 51 + 100 = 151 >= 151.

because some element not add the value rathar than reduce it.

2] example..

3 -2 5 and k = 5
- 3 + -2 + 5 = 6
so now we increase the begin pointer to find minimun window= 6 - 3 = 3 <= 5 (begin=1, end = 2)
and our algorithm going to stop here. But if we do this one more time we can see that
3 - (-2) = 5 which our answer. length = 1.


So what can we do?
- for finding any length subarray we have two method. 
1) sliding window simple 
2) prefix sum A[i...j] = prefix[j] - prefix[i-1].    

- So we are going to increase the end pointer(i) every time and see weather any subarray from
[0, i] can be our result. 

How ?
- so it is clear that in our calculation we find negative sum. so for keep track of it we 
use the monotonic increasing queue and put the prefix sum as index of the array.
- now any point if our queue.front() is lowest possible sum of all the subarray from [0,i]. so
if any point if we remove this sum from the current sum means remove that part from the subarray
and if this sum >= k. we can say that we found the subarray which sum >= k.
- as monotonic queue we give entry to the current sum if its value is greater than current q.back().

-34 37 51 3 -12 -50 51 100 -47 99 34 14 -13 89 31 -14 -44 23 -38 6
-34 3 54 57 45  -5  46 146 99 ...... 

queue = -34 -5 46     [we store the index rather than prefix sum in actual algorithm]

when we reach at 100 we see that our prefix sum is 146.


shrink the window until prefix_sum - q.front() >= k
146 - (-34) >= 151 [-34...100] - [-34] = [37...100] can be our subarray.
146 - (-5) >= 151 [-34...100] - [-34...-50] = [51,100] can be our result.

That's how it's working.


we store the best possible prefix_sum in deque which removal make our sum >= k.

*/

/*
==============================> Edge Case <=============================================

*/



class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

    int N = nums.size(), res = INT_MAX;
    deque<int> dq;

    for(int i = 0; i < N; i++) {
        
        // prefix sum
        if(i > 0) 
            nums[i] += nums[i-1];

        // Any point if prefix sum is greater than k means all subarray until current i is the result.
        if(nums[i] >= k)
            res = min(res, i+1);

        // what is meaning of nums[i] - nums[dq.front()] -> we consider subarray of [dq.front()....i]
        // And any point nums[dq.front()] < nums[dq.front()+1] means if our dq.front() can not satisfy this
        // condition then no index after can.

        // whenever it is true we try to minimize the window.
        while(dq.size() > 0 && nums[i] - nums[dq.front()] >= k) {
            res = min(res, i - dq.front());
            dq.pop_front();
        }

        // we store the prefix sum index in monotonic increasing queue.
        // It is not always store the index in continuous manner.
        while(dq.size() > 0 && nums[dq.back()] >= nums[i])
            dq.pop_back();

        dq.push_back(i);
    }

    return res == INT_MAX ? -1 : res;
}

};