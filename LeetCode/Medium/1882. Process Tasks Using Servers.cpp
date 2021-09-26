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

Question: 1882. Process Tasks Using Servers
Topic : minHeap, Set
Problems : https://leetcode.com/problems/process-tasks-using-servers/

==============================> Explanation <=============================================
There is problem in question...

1) If we can assign only available task at given time(index of tasks) then check solution...
- Create a two pq(used, free), or one pq(used) and one set(free)
- add all the server into the free with priority <wt, index>
- At every new task,
    - first make all the server free in which task deadline reached.
    - if have any free sever then assign the current task to that server(one of the best based on priority).
    - Otherwise assign used server which become free first.


2) If we assign multiple task at the same time with available server then Check answer 2) 
- doing above step, but here we keep track of time... And add tasks_queue in which we push all the tasks
which can be added with <= time.
- then perform all above activity.
- make server free if it is possible with current time.
- check wheather any server free with current time, if no then reset the time with used server first task deadline.
- then assign the sever of tasks from tasks_queue, until no server free or no tasks.

==============================> Apporach and Time Complexity <=============================================


N -> Tasks.
1) maxHeap:
Time:O(NlogN)
Space:O(N)

*/


class Solution {
public:

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {


        vector<int> ans(tasks.size(), -1);

        // <leave_time, server_index>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // <weight, server_idx> free server
        set<pair<int,int>> st;

        // Add all the servers into the free_server
        for(int i = 0; i < servers.size(); i++) {
            st.insert({servers[i], i});
        }

        int assignServer;

        for(int i = 0; i < tasks.size(); i++) {

            int task_arrivalTime = i;

            // make it all server_free which has deadline task_arrivalTime.
            while(!pq.empty() && pq.top()[0] <= task_arrivalTime) {
                auto completedTask = pq.top(); pq.pop();
                st.insert({servers[completedTask[1]], completedTask[1]});
            }

            // If have free server then, use it
            if(st.size() > 0) {
                auto it = *(st.begin());
                assignServer = it.second; st.erase(st.begin());

                // leavetime = i + tasks[i]
                pq.push({i+tasks[i], assignServer});
            }

            // No free server then use the sever which become free first.
            else {
                auto firstcompletedTask = pq.top(); pq.pop();
                assignServer = firstcompletedTask[1];

                // here leave_time = firstfreeServer_freeTime + tasks[i];

                pq.push({firstcompletedTask[0]+tasks[i], assignServer});
            }

            
            ans[i] = assignServer;
        }

        return ans;
    }

};





class Solution {
public:

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> free, busy; 
        
        for (int i = 0; i < servers.size(); ++i) {
            free.push(vector<long long>{servers[i], i});
        }

        vector<int> ans;
        long long time = 0;
        queue<int> task_queue;

        while (ans.size() < tasks.size()) { 


            // Bring all eligible tasks to task_queue.(How added tasks in queue in IMP).
            for (int i = ans.size() + task_queue.size(); i <= time && i < tasks.size(); ++i) {
                task_queue.push(tasks[i]);
            }

            // Bring all eligible servers to free queue.
            while (!busy.empty() && busy.top()[0] <= time) {
                auto& top = busy.top();
                free.push(vector<long long>{top[1], top[2]});
                busy.pop();
            }

            // If we have no servers, we cannot match until one of the servers becomes free.
            if (free.empty()) {
                time = busy.top()[0];
                continue;
            }

            while(!task_queue.empty() && !free.empty()) {
                // Now we just take the first task and first server as per defined priority and match the two.
                int task = task_queue.front(); 
                auto& top = free.top();
                ans.push_back(top[1]);
                busy.push(vector<long long>{time + task, top[0], top[1]});
                task_queue.pop();
                free.pop();
            }

            // Only increment time to receive new tasks once we have processed all tasks so far.
            if (task_queue.empty()) time++;
        }
        return ans;
    }
};