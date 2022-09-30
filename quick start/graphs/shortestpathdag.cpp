#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/network-delay-time/
/*
    Pretty interesting question that I totally misinterpreted.
    I was looking at a question that I could apply what I newly learnt: shortest path alg in non-cyclic DAG
    (this solution does pass the non-cyclic testcases but complexity was not evaluated)
    Question did not explicitly rule out cycles --> need to use dijkstra's instead :) will come back later

    it might be a good idea to just reverse the topsorted array for readability instead of dealing with negative loops(?)

    note to self: although use BFS to detect clusters, theres no need to do that in this question.
*/
class Solution{
    typedef vector<vector<pair<int,int>>> matrix;
    public:
    //THIS IS 1-INDEXED
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        matrix adj (n+1);
        for (auto& vect:times){
            adj[vect[0]].push_back(make_pair(vect[1],vect[2]));
        }
        vector<int> vis (n+1,0);
        vector<int> top; //empty array
        for (int i=1;i<n+1;i++){
            if (!dfs(adj, i, vis, top)) return -1;
        }
        if (top.size() != n) return -1;
        //if the graph doesnt start from the origin node return false
        if(top[n-1]!=k) return -1;
        //relaxation
        vector<int> dist (n+1,INT_MIN);
        dist[k]=0;
        int maxdist = INT_MIN;
        for(int i=n-1;i>0;i--){ //reverse top array
            for(auto& node:adj[top[i]]){
                dist[node.first] = dist[top[i]] + node.second;
                maxdist = max(maxdist, dist[node.first]);
            } //is there a better way to do this? how to generate a bottom up array instead of max() comparisons?
        }
        return maxdist;
    }

    bool dfs(matrix& adj, int node, vector<int>& vis, vector<int>& top){
        if(vis[node]==2) return true; //0 not 1 current 2 visited
        if(vis[node]==1) return false;
        vis[node] = 1;
        for(auto& v:adj[node]){
            if(!dfs(adj, v.first, vis, top)) return false;
        }
        top.push_back(node);
        vis[node]=2;
        return true;
    }
    
};

int main(){
    Solution sol;
    vector<vector<int>> time = {{1,2,1},{2,1,3}};
    int n = 2;
    int k = 2;
    cout << sol.networkDelayTime(time,n,k);
}
