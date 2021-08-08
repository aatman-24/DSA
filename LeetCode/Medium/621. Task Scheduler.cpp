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

Question : 621. Task Scheduler
Topic : Greedy, pq, heap
Problems : https://leetcode.com/problems/task-scheduler/


/*
==============================> Edge Case <=============================================


*/


/*
==============================> Explanation <=============================================
1] https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation

2]
-First count the number of occurrences of each element.
-Let the max frequency seen be M for element E
-We can schedule the first M-1 occurrences of E, each E will be followed by at least N CPU cycles in between successive schedules of E
-Total CPU cycles after scheduling M-1 occurrences of E = (M-1) * (N + 1) // 1 comes for the CPU cycle for E itself
-Now schedule the final round of tasks. We will need at least 1 CPU cycle of the last occurrence of E. If there are multiple tasks with frequency M, they will all need 1 more cycle.
-Run through the frequency dictionary and for every element which has frequency == M, add 1 cycle to result.
-If we have more number of tasks than the max slots we need as computed above we will return the length of the tasks array as we need at least those many CPU cycles
*/



class Solution {
public:

     int leastInterval(vector<char>& tasks, int n) {
        
        int counter[26];
        memset(counter, 0, sizeof(counter));
        
        int maxFreq = 0;
        int maxCount = 0; // number of task which have hightest freq.


        for(char task : tasks) {
            counter[task - 'A']++;
            if(maxFreq == counter[task - 'A'])
                maxCount++;
            else if(maxFreq < counter[task - 'A']) {
                maxFreq = counter[task - 'A'];
                maxCount = 1;
            }
        }


        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int empSlots = partCount * partLength;
        int availableSlots = tasks.size() - maxFreq*maxCount;
        int idles = max(0, empSlots - availableSlots);

        return tasks.size() + idles;

    }



    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);

        for(auto e : mp) if(e.second == count) ans++;

        return max((int)tasks.size(), ans);
    }
};