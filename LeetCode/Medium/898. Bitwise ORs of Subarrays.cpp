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

Question: 898. Bitwise ORs of Subarrays
Topic : Bottom-up Pattern=Cadane
Problems : https://leetcode.com/problems/bitwise-ors-of-subarrays/

==============================> Explanation <=============================================
Dp variant = BitDP, subset sum, cadane.	

Hard to come on this solution....

Ideas is that,

- we simply generate the O(N^2) all the subsets perform logical OR opreation and count how many of
them are unique.....

- But as we knew, performing the OR opretion does not unset(flip 1 -> 0) bit in the number so 
there are very large possiblity we encounter most of them duplicate. So we don't perform OR 
opreation with that and remove it by using set....


1 2 3 4

subsets: 

1
1 2 | 2
1 2 3 | 2 3 | 3
1 2 3 4 | 2 3 4 | 3 4 | 4

But here many of them are duplicates while performing OR...


suppose, when we reach at 3.... we perform OR with previous level in which performing OR result into 
the same value which is already encounter in previous level or in same level before.....


[001]
[001 011] [011]
[001 011 100] [011 100] [100]
[001 011 100 110] [011 100 110] [100 110] [110]
[001 011 100 110 101] [011 100 110 101] [100 110 101] [110 101] [101]

calculate OR opreatoin:

001
011 011
111 111 100
111 111 110 110
111 111 111 111 101


After removing duplicate:


001
011
111 100
111 110
111 101


So it is not O(N^2) but it is O(kN)... where k is largest depth of any level k is upto 32.


==============================> Apporach and Time Complexity <=============================================

1) Top-Down Pattern = Cadane
Time: O(kN)
Space: O(kN)

*/


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {

        // store all unique elements....
        unordered_set<int> res;

        // store -> have all the previous level unique elements.
        set<int> store, cur;

        for(int num: arr) {

            // cur store all the [prev_level | num].
            cur = {num};

            for(int prev: store)
                cur.insert(num | prev);

            // update the prev_level and current level.
            store = cur;

            // add all the elements into the res. which only add the unique elements.
            for(int added: store)
                res.insert(added);
        }

        return res.size();
    }
};