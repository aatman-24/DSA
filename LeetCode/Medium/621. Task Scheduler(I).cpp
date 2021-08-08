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
Topic : Greedy
Problems : https://leetcode.com/problems/task-scheduler/
/*
==============================> Explanation <=============================================
https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
*/


/*
==============================> Edge Case <=============================================


*/

class Solution {

public:
    

    int leastInterval(vector<char>& tasks, int n) {

        int arr[26] = {0};
        for(char ch : tasks) arr[ch - 'A']++;

        int max_occurance = 0, count = 0;
        for(int i = 0; i < 26; i++) max_occurance = max(max_occurance, arr[i]);

        for(int i = 0; i < 26; i++) {
            if(arr[i] == max_occurance) count++;
        }    


        // ans = (max_occurance - 1) #Leave the last one * (n + 1)(tear time + include element) + count(character which has max_occurance)
        return max((int)tasks.size(), (max_occurance-1)*(n+1) + count);


    }
};