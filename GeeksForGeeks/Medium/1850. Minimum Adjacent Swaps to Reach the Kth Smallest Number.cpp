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

Question : 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number
Topic : Greedy
Problems : https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
/*
==============================> Explanation <=============================================
- Here Using the next_permuatation() of c++ we found the kth largest number.

After that How to found total swap ?

- Brute Force -> Make the og string to current number string. By swapping the numbers.

Why we don't make current string to og number ? -> Because the current string is greater number than og number
so we found the element on left of i in og number. So that is make diffcult to view on both side.

- but if we make og_string to current number then all the number we found is on right side of current index.  

If any mismatch occur, num[i] != og[j] then we find the current num[i] into the og. And make the swap all
the element left of it until you reach at i.



Time = O(N*M)
Space = O(1)
*/


/*
==============================> Edge Case <=============================================


*/


class Solution {
public:
    
    void swap(char &a, char &b) {
        char c = a;
        a = b;
        b = c;
    }
    
    
    int getMinSwaps(string num, int k) {

        string og_num = num;

        while(k--) {
            next_permutation(num.begin(), num.end());
        }

        int swapCount = 0;

        int i = 0, j = 0;
        while(i < num.size()) {

            j = i;

            // if both digit is not at same place.
            if(og_num[j] != num[i]) {

                
                // first we found the nums[i] into og. 
                while(og_num[j] != num[i]) j++;

                // after we try to make it right place at i by swapping the others 
                // number.
                while(i < j) {
                    swap(og_num[j-1], og_num[j]);
                    j--;
                    swapCount++;
                }
            }

            i++;
        }

        return swapCount;
    }

};