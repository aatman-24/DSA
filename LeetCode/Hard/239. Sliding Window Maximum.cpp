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

Question : 239. Sliding Window Maximum
Topic : Monotone Queue, Deque
Problems : https://leetcode.com/problems/sliding-window-maximum/
pattern : 1 



/*
==============================> Explanation <=============================================
pattern : 1 same method

*/


/*
==============================> Edge Case <=============================================


*/


class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> q;

        for(int i = 0; i < k; i++)
        {
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for(int i = k; i < nums.size(); i++) {

            // if q.front() is out of window remove it
            while(!q.empty() && i - q.front() >= k) q.pop_front();

            // this is for incresing queue
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            // add smaller element if we have window for it.
            if(q.size() < k) q.push_back(i);

            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};