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

Question : 307. Range Sum Query - Mutable
Topic : Binary Indexed Tree, Segement Tree
Problems : https://leetcode.com/problems/range-sum-query-mutable/e

==============================> Explanation <=============================================

Prefix sum: TLE-> N = 10^8.

Standard problem of segement tree.


==============================> Apporach and Time Complexity <=============================================

1) Segement Tree
Time: update: O(logN), query: O(logN)
Space: O(4*n)

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// prefix sum - TLE
class NumArray {

public:

    vector<int> prefix;

    NumArray(vector<int>& nums) {
        prefix.assign(nums.size(), 0);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }
    }
    
    void update(int index, int val) {
        int prev = index == 0 ? prefix[index] : prefix[index] - prefix[index-1];
        for(int i = index; i < prefix.size(); i++) {
            prefix[i] += (val-prev);
        }
    }
    
    int sumRange(int left, int right) {
       return prefix[right] - (left == 0 ? 0 : prefix[left-1]); 
    }
};





// segment tree with range update query.
class NumArray {

public:

    int arr[100005], seg[4*100005], lazy[4*100005];
    int N;

    
    void build(int index, int low, int high) {
    
        if(low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*index+1, low, mid);
        build(2*index+2, mid+1, high);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }


    NumArray(vector<int>& nums) {
        N = nums.size();
        for(int i = 0; i < N; i++)
            arr[i] = nums[i];

        // fill the lazy tree with 0.
        memset(lazy, 0, sizeof(lazy));

        build(0, 0, N-1);
    }
    

    void rangeUpdate(int index, int low, int high, int l, int r, int val) {

        // cout << index << ' ' << low << ' ' << high << ' ' << l << ' ' << r << endl;
        
        if(lazy[index] != 0) {

            seg[index] += (high - low + 1) * lazy[index];

            if(low != high) {

                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index];
            }

            lazy[index] = 0;
        }

        // (outcast)
        if(high < l || low > r || low > high)
            return;

        // (inside)
        if(low >= l && high <= r) {

            seg[index] += (high - low + 1) * (val - arr[l]);

            if(low != high) {

                lazy[2*index+1] += (val - arr[l]);
                lazy[2*index+2] += (val - arr[l]);
            }
            else {

                arr[low] += (val - arr[l]); 
            }

            lazy[index] = 0;
            
            return;
        }

        // overlap
        int mid = (low + high) >> 1;
        rangeUpdate(2*index+1, low, mid, l, r, val);
        rangeUpdate(2*index+2, mid+1, high, l, r, val);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }

    void update(int index, int val) {
        // cout << "HEL" << endl;
        rangeUpdate(0, 0, N-1, index, index, val);
        // cout << "ED" << endl;
    }

    int query(int index, int low, int high, int l, int r) {

        if(lazy[index] != 0) {

            seg[index] += (high - low + 1) * lazy[index];

            if(low != high) {

                lazy[2*index+1] += lazy[index];
                lazy[2*index+2] += lazy[index];
            }

            lazy[index] = 0;
        }

        // (outcast)
        if(high < l || low > r || low > high)
            return 0;

        // (inside)
        if(low >= l && high <= r) {
            return seg[index];
        }

        // overlap
        int mid = (low + high) >> 1;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);

        return left + right;
    }


    int sumRange(int left, int right) {
        // cout << "HEL" << endl;
       int x = query(0, 0, N-1, left, right);
        // cout << "HEL" << endl;
        return x;
    }
};



// segment tree with point update query.
class NumArray {

public:

    int arr[100005], seg[4*100005];
    int N;

    
    void build(int index, int low, int high) {
    
        if(low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;
        build(2*index+1, low, mid);
        build(2*index+2, mid+1, high);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }


    NumArray(vector<int>& nums) {
        N = nums.size();
        for(int i = 0; i < N; i++)
            arr[i] = nums[i];

        build(0, 0, N-1);
    }
    

    void pointUpdate(int index, int low, int high, int l, int r, int val) {

        // (outcast)
        if(high < l || low > r || low > high)
            return;

        // point update.
        if(low == high) {
            arr[low] = val;
            seg[index] = val;
            return;
        }

        // overlap
        int mid = (low + high) >> 1;
        pointUpdate(2*index+1, low, mid, l, r, val);
        pointUpdate(2*index+2, mid+1, high, l, r, val);

        seg[index] = seg[2*index+1] + seg[2*index+2];
    }


    void update(int index, int val) {
        pointUpdate(0, 0, N-1, index, index, val);
    }


    int query(int index, int low, int high, int l, int r) {

        // (outcast)
        if(high < l || low > r || low > high)
            return 0;

        // (inside)
        if(low >= l && high <= r) {
            return seg[index];
        }

        // overlap
        int mid = (low + high) >> 1;
        int left = query(2*index+1, low, mid, l, r);
        int right = query(2*index+2, mid+1, high, l, r);

        return left + right;
    }


    int sumRange(int left, int right) {
       return query(0, 0, N-1, left, right);
    }
};
