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

Question: 1104. Path In Zigzag Labelled Binary Tree
Topic : Binary Search
Problems : https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
==============================> Explanation <=============================================

Concept is to track the parent from the child,

- We know tha in BT, parentIdx = leftchildIdx / 2 or int(rightChildIdx/2).
- But Problem is that, due to change in order of row direct this is not possible.

So for that we must go from the right child to parent. So we need to restore
the child first,

How ?

So If there is level, 

4 5 6 7 -> right Order

7 6 5 4 -> Reverse Order

Then element is same in the level but order is differnt which we can achieve
using max + min - curr (which return the reverse or mirror of that element)

suppose going from 6 -> 5. (7 + 4 - 6) = 5.
That's why mirroring is used. And each level need to perform this to got the lable(parent).

https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/324011/Python-O(logn)-time-and-space-with-readable-code-and-step-by-step-explanation
==============================> Apporach and Time Complexity <=============================================

1) Binary Serach:
Time: O((logN)^2) (power * Binary Search)
Space: O(logN)


*/

class Solution {
public:

vector<int> pathInZigZagTree(int label) {

        vector<int> res;

        int level = 1;

        // first count the level.
        int node = 1;
        while(label >= node * 2) {
            node = node << 1; // node *= 2;
            level++;
        }


        while(level) {

            res.push_back(label);

            // switch to the right lable and go to the parent.
            int level_max = pow(2, level) - 1;
            int level_min = pow(2, level-1);
            label = (level_max + level_min - label) / 2;

            level--;
        }

        reverse(res.begin(), res.end());


        return res;
    }
};