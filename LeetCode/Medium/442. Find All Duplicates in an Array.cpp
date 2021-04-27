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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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

Question : 442. Find All Duplicates in an Array
Topic : Array
Problems : https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/



// O(N^2).

class Solution {
public:

    // Brute Force O(N^2) - O(1).
    // Sort Array (N*logN) - O(1).

    // O(N*logN)-O(N). Map.
    vector<int> findDuplicates(vector<int>& nums) {
        mii mp;
        int n = nums.size();
        vector<int> ans;
        REP(i,n) {
            if(mp.find(nums[i]) != mp.end()) ans.push_back(nums[i]);
            else mp[nums[i]] = 1;
        }
        return ans;
    }

    // O(N)-O(N). HashMap.
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vi arr(n,0);
        vector<int> ans;
        REP(i,n) {
            if(arr[nums[i]] == 1) ans.push_back(nums[i]);
            else arr[nums[i]] = 1;
        }
        return ans;
    }

    // O(N)-O(1). ARRAY CHANGED.
    vector<int> findDuplicates(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        int n = nums.size();
        REP(i,n) {
            nums[nums[i] % n] = nums[nums[i] % n]  + n;
        }
        vi ans;
        REP(i,n) {
            if(nums[i] > 2 * n) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    // O(N)-O(1). ARRAY CHANGED.
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vi ans;
        REP(i,n) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) {
                ans.push_back(index+1);
            }
            nums[index] = -nums[index];
        }
        return ans;
    }


};