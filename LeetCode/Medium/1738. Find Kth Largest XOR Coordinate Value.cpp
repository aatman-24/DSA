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

Question : 1738. Find Kth Largest XOR Coordinate Value
Topic : 2D-Array, XOR, PREFIX SUM
Problems : https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
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

class Solution {
public:
    // O(N*M*LOGK) - O(k)
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) matrix[i][j] = matrix[i][j] ^ matrix[i-1][j];
                if(j > 0) matrix[i][j] = matrix[i][j] ^ matrix[i][j-1];
                if(i > 0 && j > 0) matrix[i][j] = matrix[i-1][j-1] ^ matrix[i][j];
            }
        }

        priority_queue< int, vector<int>, greater<int> >pq;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pq.size() < k) {
                    pq.push(matrix[i][j]);
                }
                else {
                    if(matrix[i][j] > pq.top()) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top(); 
    }


    // O(N*M*K*LOGK) - O(N)
    int kthLargestValue(vector<vector<int>>& matrix, int k) {

        int n = matrix.size(); int m = matrix[0].size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0) matrix[i][j] ^= matrix[i-1][j];
                if(j > 0) matrix[i][j] ^= matrix[i][j-1];
                if(i > 0 && j > 0) matrix[i][j] ^= matrix[i-1][j-1];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res.push_back(matrix[i][j]);
            }
        }

        sort(res.begin(), res.end());

        return res[res.size() - k];        
    }
};