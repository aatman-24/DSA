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

Question : 1314. Matrix Block Sum
Topic : DP, Kadane
Problems : https://leetcode.com/problems/matrix-block-sum/
*/

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

Question : 1222. Queens That Can Attack the King
Topic : 2D-Array, 
Problems : https://leetcode.com/problems/queens-that-can-attack-the-king/
*/




class Solution {
public:

    // O(N^2) - O(1). 
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        int n = queens.size();
        int xIndex, yIndex, kxIndex, kyIndex;
        kxIndex =  king[0]; kyIndex = king[1];
        vvi ans;

        for(int i = 0; i < n; i++) {
            xIndex = queens[i][0]; yIndex = queens[i][1];
            if(xIndex == kxIndex) {
                int flag = 0;
                for(int j = 0; j < n; j++) {
                    if(i != j && queens[j][0] == kxIndex && kyIndex < queens[j][1] && queens[j][1] < yIndex) {flag = 1; break;}
                    if(i != j && queens[j][0] == kxIndex && kyIndex > queens[j][1] && queens[j][1] > yIndex) {flag = 1; break;}
                }
                if(!flag) ans.push_back({xIndex, yIndex});
            }
            else if(yIndex == kyIndex) {
                int flag = 0;
                for(int j = 0; j < n; j++) {
                    if(i != j && queens[j][1] == kyIndex && kxIndex < queens[j][0] && queens[j][0] < xIndex) {flag = 1; break;}
                    if(i != j && queens[j][1] == kyIndex && kxIndex > queens[j][0] && queens[j][0] > xIndex) {flag = 1; break;}
                }
                if(!flag) ans.push_back({xIndex, yIndex});
            }
            else if(abs(kxIndex - xIndex) == abs(yIndex - kyIndex)) {
                int flag = 0;
                for(int j = 0; j < n; j++) {
                    if(abs(queens[j][0] - kxIndex) == abs(queens[j][1]- kyIndex)){
                        if(i != j && kxIndex < queens[j][0] && queens[j][0] < xIndex) {
                            if(kyIndex < queens[j][1] && queens[j][1] < yIndex) {flag=1; break;}
                            else if(kyIndex > queens[j][1] && queens[j][1] > yIndex) {flag=1; break;}
                        }
                        else if(i != j && kxIndex > queens[j][0]&& queens[j][0] > xIndex) {
                            if(kyIndex < queens[j][1] && queens[j][1] < yIndex) {flag=1; break;}
                            else if(kyIndex > queens[j][1] && queens[j][1] > yIndex) {flag=1; break;}
                        }
                    }
                }
                if(!flag) ans.push_back({xIndex, yIndex});  
            }
        }
        return ans;
    }

    // O(N*logN) - O(N).
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int X = king[0], Y = king[1];
        int x_dir[] = {-1, 0, 1};
        int y_dir[] = {-1, 0, 1};

        map<ii, int> mp;
        for(int i = 0; i < queens.size(); i++) {
            mp[{queens[i][0],queens[i][1]}] = 1;
        }

        vvi res;
        for(int i = 0;i < 3;i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 8; k++) {
                    int new_x = X + x_dir[i] * k;
                    int new_y = Y + y_dir[j] * k;

                    if(mp.find({new_x,new_y}) != mp.end()) {
                        res.push_back({new_x,new_y});
                        break;
                    }
                }
            }
        }
        return res;
    }


    // O(N) - O(64).
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {


        int X = king[0], Y = king[1];
        int x_dir[] = {-1, 0, 1};
        int y_dir[] = {-1, 0, 1};


        int b[8][8];
        memset(b, 0, sizeof(b));

        for(int i = 0; i < queens.size(); i++) {
            b[queens[i][0]][queens[i][1]] = 1;
        }

        vvi res;

        for(int i = 0;i < 3;i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 8; k++) {
                    int new_x = X + x_dir[i] * k;
                    int new_y = Y + y_dir[j] * k;

                    if(new_x > -1 && new_x < 8 && new_y > -1 && new_y < 8) {
                        if(b[new_x][new_y] == 1) {
                            res.push_back({new_x,new_y});
                            break;
                        }
                    }
                    else break;

                }
            }
        }

        return res;

    }



};