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

Question: 229. Majority Element II
Topic : Hashing,  Boyer-moore Voting
Problems : https://leetcode.com/problems/majority-element-ii/

==============================> Explanation <=============================================
Parent Problem: 169. Majority Element

This problem can be solved by using Boyer-moore Voting.

Here we need to return all the elements which occurs is more than N/3.

Intuition behind algorithm is that,

In answer can have 2 elements maximum reason is that,

N = N/3 + N/3+ N/3

Given that, elements which occurs more than N/3 times.

N = (N/3+1) + (N/3+1) + (N/3-2) -> So there are 2 elements possibles.

So We Update/Modify the Standard Algorithm, We keep count of 2 candidates which can be our solution(later
we confirm it) same as we do in standard algorithm(keep track of 1 candidates).
- And using Other Two for loops we check candidates is actually our solution or not.

STEP-1: Choose the two candidate which occurs more time than any other elements.
STEP-2: Validate candidate.

First step -> Given the two candidates is candidate who occurs more time than any other elements not
gurantee that it occurs more than N/3 times.
So we need to check that it is occur more than N/3 times or not.


==============================> Apporach and Time Complexity <=============================================
1) Brute Force:
Time: O(N^2)
Space: O(1)

2) Hashing:
Time: O(N)
Space: O(N)

3) Sorting:
Time: O(NlogN)
Space: O(1)

4) Boyer-moore Voting:
Time: O(N)
Space: O(1)

*/


class Solution {
public:
    
bool isConfirmCandidate(vector<int> &nums, int candidate) {
    int count = 0;
    for(int num : nums) {
        if(candidate == num) {
            count++;
        }
    }
    return count > nums.size()/3;
}

vector<int> majorityElement(vector<int>& nums)  {
    
    int candidate1 = 0, count1 = 0;
    int candidate2 = 1, count2 = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == candidate1) {
            count1++;
        }
        else if(nums[i] == candidate2) {
            count2++;
        }
        else if(count1 == 0) {
            candidate1 = nums[i];
            count1++;
        }
        else if(count2 == 0) {
            candidate2 = nums[i];
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }

    vector<int> candidates = {candidate1, candidate2};
    vector<int> answer;

    // validate candidate.
    for(int candidate: candidates) { 
        if(isConfirmCandidate(nums, candidate)) {
            answer.push_back(candidate);
        }
    }

    return answer;

}
};