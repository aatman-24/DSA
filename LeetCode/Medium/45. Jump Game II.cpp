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

Question : 45. Jump Game II
Topic : DP, BFS, Greedy, Array
Problems : https://leetcode.com/problems/jump-game-ii/
/*
==============================> Explanation <=============================================
This problem in which we should think greddily but do the program as dp. You can also think
as BFS. Because at current level we try to visit all the nodes one by one and select which ever is
best do the same.


One more approach is 
- find the left most index for given position. Once we found we update pos = i and again start from the 
index = 0 to find left most index to get pos. until pos is 0.


Example...


2 3 1 3 4 2 1(P)
i = 0, pos = 6(last element)


i = 3 -> i + nums[i] >= pos -> 3 + 3 > 6 so we update pos = 3.


2 3 1 3(P) 4 2 1

i = 1 -> i + nums[i] >= pos -> 1 + 3 > 4 so we update pos = 1.


2 3(P) 1 3 4 2 1
i = 0 -> i + nums[i] >= pos -> 2 + 0 > 1 so we update pos = 0.


jump = 3.

1 1 1 1 1 1


*/


/*
==============================> Edge Case <=============================================


*/

class Solution {
public:


    int jump(vector<int>& nums) {
                
        int i = 0, cnt = 0, j, jumpCredit, mostPromisingIndex;

        while(i < nums.size() - 1) {

            // jumpCredit = Farthest unit we can go from nums[i];
            jumpCredit = nums[i];

            // j = Farthest points we can reach from nums[i];
            j = i + jumpCredit; cnt++;

            // If j reach to the last element we found our solution.
            if(j >= nums.size() - 1) break;

            // Otherwise We need to found the mostPromisingIndex between current [i, j] which can push
            // maximum to the rights. So we start from the farthest points and comes to the current i
            // and keep track of mostPromisingIndex.

            // mostPromisingIndex = j  if j index provide maximum of nums[j] + j. In range of [i,j]. 
            jumpCredit = 0;
            while(j > i) {

                if(nums[j] + j > jumpCredit) {
                    mostPromisingIndex = j;
                    jumpCredit = nums[j] + j;
                }
                j--;
            }

            // we jump to that index. 
            i = mostPromisingIndex;
        }
        return cnt;
    }


    // same soultion.
    // O(N) - O(1)
    int jump(vector<int>& nums) {
        
        // curEnd = curEnd is index which last point for current level.
        // curFarthest = curFarthest is index which keep track of farthest index before reach to the curEnd. 
        int jumps = 0, curEnd = 0, curFarthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            // keep track of curFarthest. 
            curFarthest = max(curFarthest, i + nums[i]);

            // curEnd reached then update it with curFarthest.
            if(i == curEnd) {
                jumps++;
                curEnd = curFarthest;
            }
        }

        return jumps;

    }


    // We find the leftmost index which satisfy the nums[i] + i >= position. Here position is the right most index.
    // again when this true, we update the pos = i and again start from the index = 0.
    // O(N^2)
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int jump = 0;
        while(pos != 0) {
            for(int i = 0; i < pos; i++) {

                // found the ith index. update pos = i and again start from the 0 .
                if(nums[i] + i >= pos) {
                    pos = i;
                    jump++;
                    break;
                }
            }
        }
        return jump;
    }
};


