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
d
/*
==============================> Description <=============================================

Question : 659. Split Array into Consecutive Subsequences
Topic : Greedy
Problems : https://leetcode.com/problems/split-array-into-consecutive-subsequences/
==============================> Explanation <=============================================
- Split the Array Into the three or more length subsequence such that every element
in subsequence consecutive.
Can you derive all subsequence which can be formed by above statement?


- Idea is that, we keep track of previous element, 
number of subsequence which end at previous element,
with length 1 p1
with length 2 p2 
with length 3 p3

- Now If current element we visit right now is curr and occuracnce of curr is cnt.

- We greedliy add the curr to the end of previous subsequence first we add to the length 1, then 
length 2 and length 3.

But problem is that,
    if (curr != pre + 1)
        that time we have to make new sequence which start point is curr. Right.

        Before that all subsequence must have length more than 3.

        so we check if p1 == 0 && p2 == 0  or not. But any of them is not zero means we can not
        form the subsequence of length 3. Because already element is sorted so whatever length p1
        or p2 is not zero its remain same. So we return False.

        - If both zero. Then We make the 1 length subsequence of count times. We have no option.
        We have to create separte sequence of curr element.


    - But if curr is pre + 1. Then we can append the curr to the any subsequence which end at the pre.

    1) Let extend the length 1 subsequence.

    -here we also check if (cnt > p1 + p2) means total number of curr must fill up the all the 
    subsequence which end at pre and length is 1 or 2. If not return False.
    
    - Else



    c2(end at curr with length 2) = p1 (Bcz adding curr to the p1 make size 2.)

    c3 = p2 + min(p3, cnt-(p1+p2))
    // So c3 is atleast p2. But after that we can also add curr to the p3. But if p3 is more than
    cnt-(p1+p2) so we only extend the minimum of(p3, cnt-(p1+p2)). p1 and p2 already extended so 
    remaining curr is used.

    c1 = max(cnt -(p1+p2+p3), 0)
    // Add after filling the c3 if still curr is remaining make it length 1. This is possible when
    p3 is minimum the cnt-(p1+p2).




    And last if (p1 == 0 && p2 == 0) then and only return true.
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:
 bool isPossible(vector<int>& nums) {

    int pre = INT_MIN, p1 = 0, p2 = 0, p3 = 0;
    int cur = 0, cnt = 0, c1 = 0, c2 = 0, c3 = 0;

    for(int i = 0; i < nums.size(); pre = cur, p1 = c1, p2 = c2, p3 = c3) {

        // count occurance of curr.
        for(cur = nums[i], cnt = 0; i < nums.size() && cur == nums[i]; i++)
            cnt++;

        // if pre + 1 is not current. 
        if(cur != pre + 1) {


            if(p1 != 0 || p2 != 0)
                return false;

            // New starting with cnt sequence of length 1.
            c1 = cnt;
            c2 = 0;
            c3 = 0;

        }
        else {

            if(cnt < p1 + p2)
                return false;

            c2 = p1;
            c3 = p2 + min(p3, cnt - (p1+p2));
            c1 = max(0, cnt - (p1 + p2 + p3));

        }

    }

    return (p1 == 0 && p2 == 0);
 }
};