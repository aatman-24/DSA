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

Question : 54. Spiral Matrix
Topic : 2DArray
Problems : https://leetcode.com/problems/spiral-matrix/
/*
==============================> Explanation <=============================================
solution 1:
use four pointer minI(up), maxI(down), minJ(left), maxJ(right).
going to print until both (minI < maxI || minJ < maxJ) one of them true.
- when we hit at any corner correspoding pointer needs to update.

In this soultion we chain up both (increment i and increment j). and same
decrement j and decrement i.

- both opreation going to be in chain. if first not then second not.
if first then second can be or can not be as per condition.


solution 2:
- In this (left -> right) || (right <- left) are fully.
and (up -> down) and (down -> up) is (up + 1 -> down - 1) || (down - 1 -> up + 1)
so all squrae become at the end.


1 2 3
4 5 6
7 8 9

-> (1 2 3) (6) (9 8 7) (4) (5) (that's how sprial print).


and we also check every time if all element printed or not.


*/



/*
==============================> Edge Case <=============================================


*/



class Solution {
public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int minI = 1, maxI = matrix.size()-1, minJ = 0, maxJ = matrix[0].size()-1;
        int inc = 1, i = 0, j = 0;
        vector<int> ans;

        while(minI <= maxI || minJ <= maxJ) {

            if(inc == 1) {

                if(minJ > maxJ) break;
                while(j <= maxJ) {
                    ans.push_back(matrix[i][j++]);
                }
                j = maxJ--; i++;

                if(minI > maxI) break;
                while(i <= maxI) {
                    ans.push_back(matrix[i++][j]);
                }
                i = maxI--; j--;

            }
            else {

                if(minJ > maxJ) break;
                while(j >= minJ) {
                    ans.push_back(matrix[i][j--]);
                }
                j = minJ++; i--;

                if(minI > maxI) break;
                while(i >= minI) {
                    ans.push_back(matrix[i--][j]);
                }
                i = minI++; j++;
            }

            inc = -inc;
        }
        return ans;
    }




    // Interview Persepective
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int left = 0, right = matrix[0].size()-1, up = 0, down = matrix.size()-1;
        int n = (right+1) * (down+1);
        vector<int> ans;

        while(ans.size() < n) {

            for(int i = left; i <= right && ans.size() < n; i++)
                ans.push_back(matrix[up][i]);

            for(int j = up + 1; j <= down - 1 && ans.size() < n; j++)
                ans.push_back(matrix[j][right]);

            for(int i = right; i >= left && ans.size() < n; i--) 
                ans.push_back(matrix[down][i]);

            for(int j = down-1; j >= up + 1 && ans.size() < n; j--) 
                ans.push_back(matrix[j][left]);

            left++; right--; up++; down--;
        }
        return ans;
    }

};

