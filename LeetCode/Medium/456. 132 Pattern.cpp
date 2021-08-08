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

Question : 456. 132 Pattern
Topic : Monotone Stack
Problems : https://leetcode.com/problems/132-pattern/
pattern : 1 
/*
==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================

*/


class Solution {
public:
    
    // In this solution we try to maintain the [min, max] range. and our top of
    // stack represent the global (min, max).
    bool find132pattern(vector<int>& nums) {

        if(nums.size() <= 2) return false;

        stack<ii> st;

        for(int n : nums) {

            // If we find new minimum push new pair (n,n) into stack. 
            if(st.empty() || n < st.top().first) st.push({n,n});

            // top[min, max] mean current n(2) > top.min(1)
            else if(n > st.top().first) {

                ii last = st.top(); st.pop();

                // n(2) < top.max(3) we found 132.
                if(n < last.second) return true;

                else {

                    // if (n > last.second) we update the last.max with n. new pair = [min, n].
                    last.second = n;

                    // Here we remove all the pair for, pair.max < n (It can not be our soultion)
                    while(!st.empty() && st.top().second < n) st.pop();

                    // if stack is not empty. Means st.top().max > n. 3 > 2
                    // so we check st.top().min < n 1 < 2 we found our soultion.
                    if(!st.empty() && st.top().first < n) return true;


                    // and if not then we push pair [global_min, n].
                    st.push(last);

                }
            }
        }
        return false;
    }




    bool find132pattern(vector<int>& nums) {

        if(nums.size() <= 2) return false;

        int min_val = INT_MAX;

        for(int n : nums) {

            if(n <= min_val) {
                min_val = n;
            }
            else {

                while(!st.empty()) {

                    // st.top() represent the min value till the current n
                    // if st.top() > n -> arr = [-1 4 5(C)] st = [4 -1] 5(C) at time we don't processed further.
                    if(st.top() >= n) break; 

                    // if st.top() < n (mean n > min) (2 > 0)

                    st.pop(); // pop min elements

                    if(!st.empty()) {

                        // st.top() > n (mean  max > n) (3 > 2)
                        if(st.top() > n) return true;
                        st.pop();
                    }
                }
                // we first push min_val and then n so we can make interval [min_val, n] in stack.
                // push 3 first then push 0
                st.push(n); 
                st.push(min_val);
            }
        }
        return flase;
    }


    // keep the value of s3 as big as possible
    // use a "sorted" stack to maintain the candidates of s2 and s3.
    // The numbers inside the stack are s2 and the number that popped out is the maximum s3. So the last thing to do is to maintain the order of the stack.
    // https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
    bool find132pattern(vector<int>& nums) {

        int s3 = INT_MIN;
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] < s3) return true;
            else {
                while(!st.empty() && nums[i] > st.top()) {
                    s3 = st.top(); st.pop();
                }
            }
            st.push(nums[i]);
        }

        return false;
    }
};