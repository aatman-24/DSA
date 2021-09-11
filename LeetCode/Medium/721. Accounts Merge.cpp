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

Question: 721. Accounts Merge
Topic : Graph, DFS, Matrix, Path Finding
Problems : 721. Accounts Merge

==============================> Explanation <=============================================
Ideas,

Given that if any two name email list have common email then it is create a single list or merge of
them. So it is clear find union component of email.

How to create graph here ?
-> So all the emails in one name list are connected so create a graph based on that.


Two Way to find component:

- In both solution need to maintain EmailToName(email->name) map.

1) DFS:
- create a graph.
- perform dfs for every mail which is not visited and find out all email connected to it.
- And create a result.

2) Union-Find
- setup the union-find.
    a) parent. Every email is own parent. 
    b) put the entry into emailToName(email -> name).

- Now take the union of every email in the particular name list. Because as said above that all
are connected. 

- Create mergedAccount map.(parent_email->[emails]).

- And setup the result.




==============================> Apporach and Time Complexity <=============================================


1) DFS + Visited:

Time = O(N*logN) -> For every email into the list need to add/find of email take the O(logN). -> O(N*logN) = N is total unique Email 
Space = O(N+E)(adjList) + O(N)(visited) + O(N)(all map). 

2) DFS:
Time = O(N*logN) -> Adding into the set take O(logN). -> O(N*logN).
Space = O(N)(All Map)


*/

class Solution {
public:
    
    // Email -> [Emails]
    unordered_map<string, vector<string>> adjList;

    // Name -> Email.
    unordered_map<string, string> emailToName;

    unordered_set<string> visited;

    void buildGraph(vector<vector<string>>& accounts) {
        
        // Create a graph. 
        for(int i = 0; i < accounts.size(); i++) {
            
            string name = accounts[i][0];
            string first_email = accounts[i][1];
            
            for(int j = 1; j < accounts[i].size(); j++) {

                adjList[first_email].push_back(accounts[i][j]);
                adjList[accounts[i][j]].push_back(first_email);

                if(emailToName.find(accounts[i][j]) == emailToName.end()) {
                    emailToName[accounts[i][j]] = name;
                }

            }
        }
    }

    // Perform DFS and all visited email add into single component.
    void dfs(string email, set<string> &email_set) {

        visited.insert(email);
        email_set.insert(email);

        for(auto it: adjList[email]) {

            if(!visited.count(it)) {
                
                dfs(it, email_set);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        buildGraph(accounts);

        vector<vector<string>> res;

        for(auto [email, _] : adjList) {

            if(!visited.count(email)) {
        
                set<string> email_set;
                dfs(email, email_set);


                // Create a Result.
                vector<string> temp(email_set.size()+1);
                temp = {email_set.begin(), email_set.end()};

                string name = emailToName[email];
                
                temp.insert(temp.begin(), name);
                
                res.push_back(temp);
            }
        }



        return res;
    }
};


class Solution {
public:
    // Map email -> email.
    unordered_map<string, string> parent;

    // Map email -> Name.
    unordered_map<string, string> emailToName;

    // Find Parent Email For given Email.
    string findParent(string A) {
        if(parent[A] == A)
            return A;
        return parent[A] = findParent(parent[A]);
    }

    // Peform Union Of Two Email A and B. Overall It set parent[parentOfAEmail] = parent[parentOfBEmail]. 
    void union_(string A, string B) {
        A = findParent(A);
        B = findParent(B);
        if(A != B) {
            parent[A] = B;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        // Map parent itself and name to every email.
        for(int i = 0; i < accounts.size(); i++) {
            string name = accounts[i][0];
            for(int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                emailToName[accounts[i][j]] = name;
            }
        }

        // Union All the Email With The first Email.
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 2; j < accounts[i].size() ; j++) {
                union_(accounts[i][1], accounts[i][j]);
            }
        }

        // Create mergedAccount Map which make result easy to build.
        // Map Every ParentEmail -> {ChildEmails}.
        unordered_map<string,set<string>> mergedAccount;
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string currEmail = accounts[i][j];
                string rootOfEmail = findParent(currEmail);
                mergedAccount[rootOfEmail].insert(currEmail);
            }
        }

        vector<vector<string>> ans;
        unordered_map<string, set<string>> nameToEmails;

        for(auto it: mergedAccount) {
            string name = emailToName[it.first];
            set<string> emails = it.second;

            vector<string> temp;
            temp.push_back(name);

            for(auto email: emails)
                temp.push_back(email);

            ans.push_back(temp); 
        }

        return ans;

    }   
};
