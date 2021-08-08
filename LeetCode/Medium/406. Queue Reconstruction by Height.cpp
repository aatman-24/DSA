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
d
/*
==============================> Description <=============================================

Question : 406. Queue Reconstruction by Height
Topic : Greedy
Problems : https://leetcode.com/problems/queue-reconstruction-by-height/
/*
==============================> Explanation <=============================================
Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
E.g.
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Sort an Input based on height. If height is same then second one which is small.

[[7,0], [7,1],  [6,1], [5,0],[5,2], [4,4]]

subarray after step 1: [[7,0], [7,1]]
subarray after step 2: [[7,0], [6,1], [7,1]]
subarray after step 3: [[5,0], [7,0], [6,1], [7,1]]
subarray after step 4: [[7,0], [6,1], [5,2], [4,4], [7,1]]

Why It works as greedy ?

- When we perform sort we ensure that every person height is greater it comes first. If height is same then
whose second argument is less that it comes first.

- So when we start append the person. Then persons before the current person must be second argument which indicate
the person whose height is greater or equal. Appending this Person It will not change the list after all person
after it because it height is greater than it.


[7,0] [5,1] [7,2] [6,1]

Now if we insert [5,2] at 2 index.

[7,0] [5,1] [5,2] [7,2] [6,1]

It will not affect [7,2] [6,1].

Because still [7,2] means only two elements are greater than it before it in array. We added the [5,2] which 
height is less than 7. That's why adding less height element before greater height not affect the second arguments.




*/


/*
==============================> Edge Case <=============================================


*/


class Solution {
public:

    // Brute Force = O(N*LogN) + O(N^2) = O(N^2)
    void swap(vector<int> &a, vector<int> &b) {
        vector<int> tmp = a;
        a = b;
        b = tmp;
    }


    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {
            if(p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] > p2[0];
        });


        for(int i = 0; i < people.size(); i++) {

            // Here If we try to put the people[i] at the people[i][1] place if it is less than current i.
            // By swapping with all left elements.
            if(people[i][1] < i) {
                int j = i;
                int until = people[i][1];
                while(j >= 1 && j != until) {
                    swap(people[j-1], people[j]);
                    j--;
                }
            }

        }

        return people;
    }

    // Sort + LinkedList
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(), people.end(),[](vector<int> p1, vector<int> p2) {
            if(p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] > p2[0];
        }); 


        // C++ Vector is implemented on LinkedList Base.
        vector<pair<int,int>> sol;
        
        for (auto person : people){
            sol.insert(sol.begin() + person.second, person);
        }

        return sol;
    }
};
