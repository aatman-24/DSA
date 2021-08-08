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

Question : 1696. Jump Game VI
Topic : DP + Monoqueue O(n)
Problems : https://leetcode.com/problems/jump-game-vi/
/*
==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================

*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        deque<int> dq;
        int curr = 0, n = nums.size();

        for(int i = n - 1; i >= 0; i--) {

            curr = nums[i] + (dq.empty() ? 0 : nums[dq.front()]);

            while(!dq.empty() && curr > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(dq.front() >= i+k) {
                dq.pop_front();
            }

            nums[i] = curr;
        }

        return curr;
    }

    // Both are same.
    int maxResult(vector<int>& nums, int k) {

        deque<int> dq;
        int curr = 0;

        for(int i = 0; i < nums.size() ; i++) {

            int max_from_window = (dq.empty() ? 0 : nums[dq.front()]);

            nums[i] = nums[i] + max_from_window;

            // outdated current sum which is less than currnet currSum going to pop here.
            while(!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // outdated index going to remove.
            if(i - dq.front() >= k) {
                dq.pop_front();
            }
        }

        return nums[nums.size() - 1];
    }
};