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

Question : 1673. Find the Most Competitive Subsequence
Topic : Stack
Problems : https://leetcode.com/problems/design-circular-queue/
*/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
We can use sliding window using stack.
Here is one problem is that we have to decided how many element can we pop from the 
stack so that we can maintain k element into the stack.

st.size() - 1 + nums.size() - i >= k (is the main part)

here -1 is indicate that we remove the top of stack.
so remaining element is =  nums.size() - i

so, if after removing top of stack + remaining element which is still remain to visit >= k then and only
we remove element from the stack and continuously we check this condition while pop from the stack.

*/



class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k){
        vector<int> st;
        for(int i = 0; i < nums.size(); i++) {
            while(!st.empty() && nums[i] < st.back() && st.size() - 1 + nums.size() - i >= k)         {
                st.pop_back();
            }
            if(st.size() < k) {
                st.push_back(nums[i]);
            }
        }
        return st;
}
};