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

Question : 1524. Number of Sub-arrays With Odd Sum
Topic : prefixSum, DP
Problems : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/



class Solution {

public:
        // O(N^3) - TLE [using three loop all subarray is calculated and then check sum is odd or not]
        int numOfSubarrays(vector<int>& arr) {

            int sum, cnt=0;
            for(int from = 0; from < arr.size(); from++) {
                for(int to = from; to < arr.size(); to++) {
                    sum = 0;
                    for(int i = from; i <= to; i++) {
                        sum += arr[i];
                    }
                    if(sum % 2) cnt = (cnt + 1) % mod;
                }
            }

            return cnt;
        }

        // O(N^2) - TLE [here we use prefix sum so we can omit one for loop]
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            int pre[n];
            pre[0] = arr[0];
            int sum, cnt=0;
            for(int i = 1; i < n; i++) pre[i] = pre[i-1] + arr[i];

            for(int from = 0; from < arr.size(); from++) {
                for(int to = from; to < arr.size(); to++) {
                    sum = pre[to] - pre[from] + arr[from];
                    if(sum % 2) cnt = (cnt + 1) % mod;
                }
            }
            return cnt;

        }

        // O(N) - O(1)
        /*
            odd - even == even - odd = odd;
            used this concept.

            we use prefix sum. if we encounter any ith index Cursum == odd.
            It means that from [1...i] our sum is odd. cnt++;
            then from [1..i-1] how many even sum is encounterd is add into cnt.
            reason is odd + even = odd.

            1 2 3 4  5 
            1 3 6 10 15
                      |

            for (15 here)
            we encounter two times even number (6, 10).

            6 = 1 + 2 + 3
            10 = 1 + 2 + 3 + 4

            so if we subtract 15 - 6 = (1+2+3+4+5) - (1+2+3) = (4+5) = 9 (odd)
            same for 15 - 10 = 5. (odd).

            cnt = cnt + even;

    
            If any ith index cursum == even.
            same as odd.
            but we add odd into cnt;

            1 2 3 4  5 
            1 3 6 10 15
                  |
    
            previous_odd = 1,3
            1 = 1
            3 = 1 + 2

            so 10 - 3 =  (1+2+3+4) - (1+2) = 7 (odd).
            same for 1 -> 10 - 1 = 9 (odd).
        */

        int numOfSubarrays(vector<int>& arr) {

            int curSum, evenNum, oddNum, cntOdd;
            curSum = evenNum = oddNum = cntOdd = 0;

            for(int i = 0; i < arr.size(); i++) arr[i] = (arr[i] % 2) ? 1 : 0;
            
            for(int i = 0; i < arr.size(); i++) {
                curSum += arr[i];
                if(curSum % 2) {
                    cntOdd++;   // this is for [1..i]th sum is odd for that.
                    cntOdd += evenNum;
                    oddNum++;
                }
                else {
                    cntOdd += oddNum;
                    evenNum++;
                }
                cntOdd = cntOdd % mod;
            }
            return cntOdd;
        }

    };