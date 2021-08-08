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

Question : 1861. Rotating the Box
Topic : Two Pointer
Problems : https://leetcode.com/problems/rotating-the-box/
/*
==============================> Explanation <=============================================


*/


/*
==============================> Edge Case <=============================================

*/

class Solution {
public:

    void swap(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

        int n = box.size(), m = box[0].size();
        vector<vector<char>> vertical_box(m, vector<char>(n, '.'));

        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                vertical_box[j][i] = box[n-i-1][j];
            }
        }

        for(int col = 0; col < n; col++) {
            
            // first pointer which is place where # this can be put if it is empty.
            int i = m - 1;

            // starting from the end and traverse all continous * or # sequence.
            while(i >= 0 && (vertical_box[i] == '#' || vertical_box[i] == '*')) i--;
            
            // J  move i -> 0 and find # which can be put at the ith place.
            int j = i - 1;

            while(j >= 0 && i >= 0) {

                // if ith pointer is ahead from jth pointer set jth ahead to ith. 
                if(j >= i) {
                    j--;
                    continue;
                }

                // found # then put it into valid position.
                if(vertical_box[j][col] == '#') {
                    if(i >= 0) {
                        swap(vertical_box[i][col], vertical_box[j][col]);
                        i--;

                        // relax i pointer until we find empty place.
                        while(i >= 0 && (vertical_box[i] == '#' || vertical_box[i] == '*')) i--;
                    }
                }

                if(vertical_box[j][col] == '*') {
                    // move ith pointer to obstacle relax it.
                    i = j;

                    // relax i pointer until we find empty place.
                    while(i >= 0 && (vertical_box[i] == '#' || vertical_box[i] == '*')) i--;
                }

                j--;
            }

        }

        return vertical_box;
    }

};

