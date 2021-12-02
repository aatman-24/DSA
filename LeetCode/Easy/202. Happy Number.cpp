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

Question: 202. Happy Number
Topic : ycle Detection
Problems : https://leetcode.com/problems/happy-number/

==============================> Explanation <=============================================

- Cycle Detection in series. CP - 3 Book.
- Using slow and fast pointer.
- Here, we stop if slow == fast, and even slow == 1, fast is also 1 so we can check it out
of loop.

==============================> Apporach and Time Complexity <=============================================

1) Cycle Detection
Time: O(N)
Space: O(1)

*/




class Solution {

public:

    int getNextNumber(int n) {
        int num = 0;
        while(n > 0) {
            int digit = n % 10;
            num += digit * digit;
            n /= 10;
        }
        return num;
    }



    bool isHappy(int n) {
        
        int slow, fast;
        slow = fast = n;
        do {
            slow = getNextNumber(slow);
            fast = getNextNumber(getNextNumber(fast));
        } while(slow != fast);


        return slow == 1;
    }
};