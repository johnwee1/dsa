#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool dfs(vector<vector<int>>& adj, int node, vector<int>& status, vector<int>& ans){
        int lstatus = status[node];
        if (lstatus == 0) status[node] = 1;
        else if (lstatus == 1) return false;
        else return true;
        for(auto& sibling:adj[node]){
            if(!dfs(adj, sibling, status,ans)) return false;
        }
        status[node] = 2;
        ans.push_back(node);
        return true;
    }


    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (n);
        for (auto pair:prerequisites) adj[pair[0]].push_back(pair[1]);
        vector<int> status (n,0);
        vector<int> ans;
        for (int i=0;i<n;i++){
            if(!dfs(adj, i, status, ans)) return {};
        }
        return ans;
    }
};