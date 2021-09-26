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

Question: 1054. Distant Barcodes
Topic : maxHeap, counting
Problems : https://leetcode.com/problems/distant-barcodes/

==============================> Explanation <=============================================

- Ideas is clear that, Here already given that arranging element that way is possible
then we directly think about greedy approach.

1) We arrange most frequent element first by placing +2 index. So for that we count
frequency and put into maxHeap.
- Next step pop out the element which have  max frequency in pq and arrange that element
from the last (i). If we hint the i at the boundary (i >= n) then we start from 
the i = 1 index. 
- This can be done in two pass. Because 0 -> 2(index) already filled, 1 -> 3(index)
already filled so we just need to start from the index = 0, index = 1.
- but using pq can make O(NlogN).

2) Second approach is not using pq.
- We used map to count frequency. But here our ideas is to place the most frequent
element into the even index(0, 2, 4....n) first and after no matter which element is next,
we start filling the index where most frequent stop... so doing that it will guarantee us
(0, 2, 4.... n) is already filled so no same element can be placed in besides of each othere.
- so other element can be placed at any blank index.

==============================> Apporach and Time Complexity <=============================================

1) MaxHeap:
Time: O(NLogN)
Space: O(N)

2) MinHeap:
Time: O(N)
Space: O(N)

*/

class Solution {
public:

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        int n = barcodes.size();

        unordered_map<int,int> count;
        for(auto it: barcodes) {
            count[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        for(auto it: count) {
            pq.push({it.second, it.first});
        }

        vector<int> arr(n, 0);
        int i = 0;
        while(!pq.empty()) {

            auto it = pq.top(); pq.pop();
            int num = it.second, freq = it.first;
            
            while(freq > 0) {
                arr[i] = num;
                freq--;
                i = i + 2 < n ? i + 2: 1;
            }
        }

        return arr;
    }
};



class Solution {
public:

vector<int> rearrangeBarcodes(vector<int>& barcodes) {

    int n = barcodes.size(), max_num, max_freq=0;

    unordered_map<int,int> count;
    for(auto it: barcodes) {
        count[it]++;
        if(count[it] > max_freq) {
            max_freq = count[it];
            max_num = it;
        }
    }
    
    vector<int> arr(n, 0);

    int i = 0;
    while(max_freq) {
        // start from where we last stop.
        arr[i] = max_num;
        max_freq--;
        i = i + 2 < n ? i + 2: 1;
    }


    for(auto it: count) {
        int num = it.first, freq = it.second;
            
        // not placed max_num. already placed one time.
        if(num == max_num)
            continue;
        
        while(freq) {

            // start from where we last stop.
            arr[i] = num;
            freq--;
            i = i + 2 < n ? i + 2: 1;
        }
        
    }

    return arr;
}


};