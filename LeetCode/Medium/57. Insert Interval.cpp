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

Question : 57. Insert Interval
Topic : Greedy, Pattern = Interval
Problems : https://leetcode.com/problems/insert-interval/

==============================> Explanation <=============================================
Brute Force:

- Add all intervals into new array.
- Sort the new array
- Overlap the intervals.


1st Apporach:

Consider all the case.

{begin, end} -> {ibegin, iend}(need to insert interval)

Case:

    ibegin < begin

        - iend < begin
            {ibegin, iend}

        - begin <= end
            start = ibegin
            fetch all interval 
                upto = max(iend, end)
            {start, upto}

    begin <= ibegin

        - end < ibegin
            {begin, end}

        - end >= ibegin
            start = begin
            fetch all interval 
                upto = max(iend, end)
            {start, upto}

- And once the interval is inserted we just add all remaining intervals.


2nd Approach(Easy):


- Same as first apporach but some condition is mixed.

- Add pre-intervals. (end < ibegin)
    
- Add Overlap intervals. (begin < iend) (update iend(upto))

- Add post-intervals. (iend < begin)


==============================> Apporach and Time Complexity <=============================================

1) Brute Force
Time: O(NlogN)
Space: O(1)

2) Linear
Time: O(N)
Space: O(1)

*/



class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
    
        // base case.
        if(n == 0) {
            return {newInterval};
        }

        int i = 0, start, end;

        // inserted new interval or not.
        bool inserted = false;

        vector<vector<int>> ans;


        while(i < n && !inserted) {

            // {ibegin, begin}
            if(newInterval[0] < intervals[i][0]) {

                // {ibegin, iend, begin, end} -> {ibegin, iend}
                if(newInterval[1] < intervals[i][0]) {
                    ans.push_back({newInterval[0], newInterval[1]});
                    inserted = true;
                }

                // {ibegin, begin, (iend, end)} -> {ibegin, upto}
                else {
                    
                    start = newInterval[0];

                    end = max(newInterval[1], intervals[i][1]);
                    
                    while(i < n && intervals[i][0] <= end) {
                        end = max(end , intervals[i][1]);
                        i++;
                    }

                    inserted = true;
                    ans.push_back({start, end});
                }
            }
            // {begin, ibegin}
            else {

                // {begin, end, ibegin, iend}   ->  {begin, end}
                if(intervals[i][1] < newInterval[0]) {
                    ans.push_back({intervals[i][0], intervals[i][1]});
                    i++;
                }
                else {

                    // {begin, ibegin, (iend,end)}  -> {begin, upto}
                    start = intervals[i][0];

                    end = max(newInterval[1], intervals[i][1]);
                    
                    while(i < n && intervals[i][0] <= end) {
                        end = max(end , intervals[i][1]);
                        i++;
                    }

                    inserted = true;
                    ans.push_back({start, end});  
                }
            }
        }

        // add remaining intervals.
        while(i < n) {
            ans.push_back(intervals[i++]); 
        }
        
        // newInterval is not inserted then add it.
        if(!inserted) {
            ans.push_back(newInterval);
        }
        
        return ans;
    }
};





class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size(), i = 0;
        
        vector<vector<int>> ans;
    
        // add all interval which is finished before newInterval start. {begin, end, ibegin, iend}
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Handle all overlap intervals. Covers -> {begin, ibegin, iend, end}, {begin, ibegin, end, iend}, {ibegin, begin, iend, end}, {ibegin, begin, end, iend}
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        // Add all remaining intervals. {ibegin, iend, begin, end}
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};