#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool dfs(vector<vector<int>>& adj, int node, vector<int>& status){
            int local_stat = status[node]; //retrieve status of current node
            if (local_stat==0) status[node] = 1;
            else if (local_stat==1) return false; //return if cycle (back edge)
            else return true; //NODES COMPLETELY VISITED NEED TO BE IMMEDIATELY RETURNED BECAUSE IT IMPLIES EVERYTHING AFTER THAT NODE IS ALREADY EXPLORED AND VERIFIED
            for (auto& child : adj[node]){
                if (!dfs(adj, child, status)) return false;
            }
            status[node] = 2;
            return true;
        }


        bool canFinish(int n, vector<vector<int>>& prereqs){
            vector<vector<int>> adj (n);
            vector<int> status (n, 0);
            //0 - unpro, 1 - midprocessing, 2 - finished
            for (auto x:prereqs) adj[x[0]].push_back(x[1]);
            for (int i=0;i<n;i++){
                //Iterating through n counts as iterating thru ALL nodes
                if (!dfs(adj, i, status)) return false;
            }
            return true; //only return true after everything has run

        }
};