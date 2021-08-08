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
d
/*
==============================> Description <=============================================

Question : 4. Median of Two Sorted Arrays
Topic : Binary Search
Problems : https://leetcode.com/problems/median-of-two-sorted-arrays/

==============================> Explanation <=============================================

- Very nice Problem on BS. 

Striver:
https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0qYbL4TBaEWgb-ljVdhkM7R&index=6

Apporach 1) O(N) + O(N) (Merge Two Sorted Array using Extra array) [merge sort + merge method]

Apporach 2) O(N) + O(1) (Same but without Extra array use the Counter to count element is
            already  merged.)
 
Appoorach 3) O(min(logN,logM)) (binary Search)

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Try to make first as minimum array.
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);


        int n1 = nums1.size(), n2 = nums2.size(), low = 0, high = n1;

        // Binary Search on first array.
        while(low <= high) {

            // cut = 1 means only 1 element. 2 menas two element.
            int cut1 = (low + high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // find out left side and right side of split.
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            // valid condition
            if(left1 <= right2 && left2 <= right1) {
                if((n1 + n2) % 2 == 0) {
                    return ((max(left1, left2) + min(right1, right2)) / 2.0);
                }
                else {
                    return max(left1, left2);
                }

            }
            // left needs to shrink. Because left contain larger element.
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            // right contains larger element so right needs to be shrink. Left increase.
            else {
                low = cut1 + 1;
            }

        }

        return 0.0;
    }
};