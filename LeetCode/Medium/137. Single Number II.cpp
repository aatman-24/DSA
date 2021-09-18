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

Question: 137. Single Number II
Topic : XOR, Bit Manipulation
Problems : https://leetcode.com/problems/single-number-ii/
==============================> Explanation <=============================================

1) Count Frequency using MAP.
- Add N number into map which take logN time. So overall O(NlogN).
- Then find the number whose frequency is 1.

2) Sorting + Linear:
- Discuss below.

3) Counting Each bit is multiple of 3 or not.
- Discuss below.

4) Circuit Desing
- Discuss below.

5) Ones and twos set tracking.
- Discuss below.

==============================> Apporach and Time Complexity <=============================================

1) Count Frequency using MAP.
Time: O(NlogN)(Adding N number into the map) + O(N)(Visting map)
Space: O(N)

2) Sorting + Linear
Time: O(NlogN)(Sorting) + O(N)(Finding the number)
Space: O(1)

3) Counting Each bit is multiple of 3 or not.
Time: O(N*32)
Space: O(1)

4) Circuit Desing
Time: O(N)
Space: O(1)

5) Ones and twos set tracking.
Time:O(N)
Space:O(1)

*/



/*
5) Ones and twos set tracking.

Remember this algorithm...

Working of Algorithm.

First time number encounter:
- Added into the ones. By checking that twos not contain that number.
- Not Added into the twos because ones contain that number.

Second time number encoutner:
- Removed from the ones.
- Added into the twos by checking ones does not contain number.

Third time number encoutner:
- Not added into the ones because twos contain that number.
- Removed from the twos. 
- At the end remove from both ones and twos.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones = 0, twos = 0;


        // ~twos and ~ones checking that given number is not
        // present into that set.

        for(int num: nums) {

            // added into ones if twos not contain that number.
            ones = (ones ^ num) & (~twos);

            // added into twos if ones not contain the number.
            twos = (twos ^ num) & (~ones);
        }

        // return ones which have result which is encounted only once.
        return ones;
    }
};


/*
3) Counting Each bit is multiple of 3 or not.
given number is 4 4 4 3.

4 -> 1 0 0
4 -> 1 0 0
4 -> 1 0 0
3 -> 0 1 1
     
     3 1 1 (count)

So If the count of bit is multiple of 3 then we don't add this weight
into the result because Single number is not added into that bit.
Otherwise it count % 3 != 0 then we add that bit weight into the
result.

We need to check each bit count using each number every times.

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for(int i = 0; i < 32; i++) {

            int mask = 1 << i;

            int count = 0;
            for(int num: nums) {
                if(num & mask) 
                    count++;
            }

            if(count % 3) {
                ans += mask;
            }
        }

        return ans;
    }
};


/*
2) Sorting + Linear
Sort each number first,

Base Case:

1 2 2 2 (ans is at first index.) 
1 1 1 3 (ans is at last index.)
1 1 1 2 3 3 3 (ans is at first index of the group).

For the third case,

0 1 2 3 4 5 6 
1 1 1 2 3 3 3

We check that, if nums[i-1] != nums[i] or nums[i] != nums[i+1]
then nums[i-1](first element of group) is occuring once. So we
return it. We take jump of index with 3. 1 -> 4 -> 7.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int N = nums.size();

        if(N == 1)
            return nums[0];

        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1]) 
            return nums[0];

        if(nums[N-2] != nums[N-1])
            return nums[N-1];

        for(int i = 1; i < N; ) {
            if(nums[i-1] != nums[i] || nums[i] != nums[i+1])
                return nums[i-1];
            i += 3;
        }

       return -1;    
    }
};

// 4) Circuit Desing:
// Current Number can be repeated three times,
// Initial State(0) -> One time Present(1) -> Two time Present(2) -> Three/Zero Time Present(0)

// Only Three State can be represented by using 2 bit (A B),

// 00 -> 01 -> 10 -> 00    Ignore(11)

// Design Table...(C is incoming Bit)

// current  next
// A B C -> A B

// 0 0 0    0 0(0)
// 0 1 0    0 1(1)
// 1 0 0    1 0(2)
 
// 0 0 1    0 1(1)
// 0 1 1    1 0(2)
// 1 0 1    0 0(0)

// 1 is encounterd = A B C
//                   0 1 0
//                   0 0 1

// 2 is encounterd = A B C 
//                   1 0 0
//                   0 1 1

// using this either you got one time occuring or two time occuring
// not both the same time.

class Solution {
public:
int singleNumber(vector<int>& nums) {

        // a -> Two times Occuring
        // b -> One times Occuring
        int a = 0, b = 0;

        for(int c: nums) {
            // need old value while calculating b.
            int ta = (a&~b&~c)|(~a&b&c);
            b = (~a&~b&c)|(~a&b&~c);
            a = ta;
        }

        // return one time occuring b. two times is actually zero into this.
        return b;
    }
};