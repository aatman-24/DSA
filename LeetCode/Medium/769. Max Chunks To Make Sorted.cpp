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

Question : 769. Max Chunks To Make Sorted
Topic : Array
Problems : https://leetcode.com/problems/max-chunks-to-make-sorted/
*/


// https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/138844/Python-O(n)-Very-Detailed-Explanation

class Solution {
public:

// O(N) - O(1).
int maxChunksToSorted(vector<int>& arr) {
    int trackIndexNum = 0, cnt = 0;;
    for(int index = 0; index < arr.size(); index++) {
        trackIndexNum = max(trackIndexNum, arr[index]);
        if(trackIndexNum == index) cnt++;
    }
    return cnt;
}



};