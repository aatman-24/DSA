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

Question : 31. Next Permutation
Topic : Array, Two Pointer
Problems : https://leetcode.com/problems/next-permutation/
/*
==============================> Explanation <=============================================
suppose number is : 2,3,6,5,4,1

- Actually this is very stright that finding next permutation is 
find the next smallest greater number than current number. For that
we need to find two number from right side such that at 
and nums[i] < nums[i+1] so if we swap both number we find greater
number than current number.

- we find first occurace from the right because we need smallest 
greater number as answer.

- 2 3 6 5 4 1 -> here (3) is number which is smaller than (6).
if we replace 6 with 3 then -> 2 6 3 5 4 1 is answer. but
actual answer can be -> 2 4 1 3 5 6 (smallest then above).

- so its clear that once we find nums[i] we find second number from
the [n-1, i] which is smallest number which is greater than nums[i].

here (4) is smallest greater number than (3).

so we swap (3, 4) -> 2 4 6 5 3 1. 
- After that we already find greater number in prefix side(number-suffixside)
- so we reverse the suffix to make it more minimize.
- 2 4 1 3 5 6 (Answer).


Other terms:
suffix -> is range which is decresing from the left -> right(increasing
right -> left). Here (6 5 4 1).In suffix range we can not swap any number
to find greater number than current because it is already greatest number.

- so we find number from the prefix(num - suffixrange) and swap it with suffix range number
which is just greater than prefixrange nums[i]. and reverse the suffix to make it
more minimize.

==============================> Edge Case <=============================================


when number is like -> 033 
and need to swap (3) with other number suppose(2) then alwasy choose
right most numuber.

032 -> reverse of it -> 230
023 -> reverse of it -> 320 (greater than above)


==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N!) * O(N)(To compare)(Generate all permutation keep track of current, next one is answer).
Space: O(N)

2) 
Time: O(N)(Overall)
Space: O(1)

*/

class Solution {
public:

    void swap(int &i, int &j) {
        int tmp = i;
        i = j;
        j = tmp;
    }

    void reverseSuffix(vector<int> &nums, int start, int end) {
        while(start < end) {
            swap(nums[start++], nums[end--]);
        }
    }

    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        if(n <= 1) return;
        
        int i, j;

        // find the index such that arr[i] < arr[i+1]. 
        for(i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1])
                break;
        }

        // if i == -1 means number are in decresing order.
        // reverse whole number to get smallest number.
        if(i == -1) {
            reverseSuffix(nums, i+1, n-1);
        }
        else {

            // otherwise find the index at which number is smallest 
            // greater than the nums[i]. swap(nums[i], nums[j])
            // and reverse the suffix (i+1, n-1).
            for(j = n - 1; j >= 0; j--) {
                if(nums[i] < nums[j]) break;
            }
            swap(nums[i], nums[j]);
            reverseSuffix(nums, i+1, n-1);
        }
    }
};