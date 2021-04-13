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

Question : 402. Remove K Digits
Topic : Stack, Array
Problems : https://leetcode.com/problems/remove-k-digits/
*/

class Solution {

public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) return "0"; // num=112 and k >= 3 (remove all) ans = "0".
        stack<char> st;
        st.push(num[0]);


        // Here we check the top of stack if the st.top() > nums[i] then pop the stack top element 
        // bcz this element increase the value of number.
        // if st.top() <= nums[i] then push the nums[i] into the stack.This process run until k == 0 or i == num.length()[1,2,3,4]
        // if (k == 0) add reamining element into the stack.
        // if(k != 0) then pop the kth element from the stack.
        // ans last reverse the stack element and remove the leading zero if exist.

        int i = 1;
        while(i < num.length() && k > 0) {
                
            if(!st.empty() && st.top() > num[i]) {
                st.pop();
                k--;
            }
            else {
                st.push(num[i]);
                i++;
            }
            if(k == 0) break;
            
        }

        for(int rem = i; rem < num.length(); rem++) st.push(num[rem]);

        // k != 0 remove the element from the top of stack.
        while(k != 0) {
            st.pop(); k--;
        }

        // pop all element and store into the tmp_result.
        string resWithLeadingZero = "";
        while(!st.empty()) {
            resWithLeadingZero += st.top();
            st.pop();
        }

        // reverse the tmp-result string.
        reverse(resWithLeadingZero.begin(), resWithLeadingZero.end());

        // remove leading zero.
        string res = "";
        int start = 0;
        int n = resWithLeadingZero.length();
        while(start < n && resWithLeadingZero[start] == '0') start++;

        while(start < n) {
            res += resWithLeadingZero[start];
            start++;
        }

        // if all element is removed we return "0".
        if(res.length() == 0) res = "0";
        
        return res;
    }
};	

int main() {

	Solution ob;
    string res=  ob.removeKdigits("1432219", 3);
    cout << res << endl;
}