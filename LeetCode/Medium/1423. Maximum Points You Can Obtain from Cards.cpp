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

Question : 1423. Maximum Points You Can Obtain from Cards
Topic : prefix sum, sliding window
Problems : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
/*
==============================> Explanation <=============================================

- subarray maxsum of k window.
- but here right + left element can be our window. Means find the max subarray in cirucular array with
k size window.

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization

*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    int maxScore(vector<int>& arr, int k) {

        int n = arr.size(), ans = 0;

        for(int i = 1; i < n; i++)
            arr[i] += arr[i-1];

        int left = 0, mid = k-1, right = n - 1;

        while(k) {

            // lftsum = [left, mid]
            int lftsum = left >= 1 ? arr[mid] - arr[left-1] : arr[mid];

            // righsum = [right-k, right]
            int rightsum  = right-k >= 0 ? arr[right] - arr[right-k] : arr[right];

            // get element from the prefix sum
            int lftele = (left > 1) ? arr[left] - arr[left-1] : arr[left];
            int rightele = (right > 1) ? arr[right] - arr[right-1] : arr[right];

            // take whichever side sum is greater.And we jump to next element of that side.
            if(lftsum > rightsum || (lftsum == rightsum && lftele > rightele)) {
                ans += lftele;
                left++;
            }
            else {
                ans += rightele;
                right--; mid--; // mid-- also because now we can not go upto mid. so [left, mid-1]
            }            
            k--;

        }

        return ans;
    }


    // subarray k size maxsum problems. but probelms is that we have to deal with 
    // last elements + first sum elements this type of window also our solution.

    int maxScore(vector<int>& arr, int k) {

        int n = arr.size() - 1, ans = 0, lftsum, rhtsum;

        for(int i = 1; i <= n; i++)
            arr[i] += arr[i-1];

        for(int i = 0; i <= k; i++) {

            // if i == 0 means arr[n-k, k] element only. from the left side no element.
            lftsum = (i >= 1) ? arr[i-1] : 0;

            // if k - i <= 0 means all the element from the left side. 
            // else some element leftside and some from the right side.
            if(k - i > 0) {
                rhtsum = (n - k + i >= 0) ? arr[n] - arr[n-k+i] : 0;
            }
            else {
                rhtsum = 0;
            } 
            ans = max(ans, lftsum + rhtsum);
        }

        return ans;
    }   

};