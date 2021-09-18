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

Question: 260. Single Number III
Topic : XOR, Bit Manipulation
Problems : https://leetcode.com/problems/single-number-iii/
==============================> Explanation <=============================================
- So Ideas is that, If we xor all the number then result is xor of answer(num1, num2).

Now How to Get those two number separately rathar than it's XOR ?
- Whatever result we got as XOR of that numbers, We analyse the each bit,

Bit -> 0 (Either both have bit 0 or 1)
Bit -> 1 (Either one of them have 0 and second one have 1)

Use this Concept to separet out because all others number is must be in same
group either 0 or 1 for that set bit.

- First we find any set bit into the result. Here we preferred the last set bit.

- Now In second pass,
We create two number num1 and num2, num1 is group in which lastSetBit is on 
and num2 is bit in which it is off.

- We perfrom the XOR again with all the numbers but with that condition to separet
out groups. Intution is that now if other element goes to the same group so again
it affect nothing and at last the num1 and num2 we got.

==============================> Apporach and Time Complexity <=============================================


*/

class Solution
{
public:
       vector<int> singleNumber(vector<int>& nums) {

        unsigned ans = 0;
        for(int num: nums) {
            ans = ans ^ num;
        }
         
        // For finding the lastSetBit perfer this method which looks 
        // promising rathar than below fancy.
        int lastSetBit;
        for(int i = 0; i < 32; i++) {
            if(ans & (1 << i)) {
                lastSetBit = 1 << i;
                break;
            }
        }
        
        // For this type of ans is int then does not work because when 
        // it is -2^32-1 then subtracting 1 from it is invalid so used
        // unsigned type instead of int.

        // lastSetBit = (ans & (ans - 1)) ^ ans;
        // lastSetBit = (ans & ~(ans - 1));
        
        vector<int> res = {0, 0};

        for(int num: nums) {
            if(num & lastSetBit) {
                res[0] ^= num;
            }
            else {
                res[1] ^= num;
            }
        }

        return res;
    }
};
