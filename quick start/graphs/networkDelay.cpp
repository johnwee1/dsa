#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    typedef vector<vector<pair<int,int>>> vec;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vec adj (n+1);
        for(vector<int>& u : times){
            adj[u[0]].push_back(make_pair(u[1],u[2]));//adj[0] should be empty
        }
        dijkstra(adj, k, times);
    }

    void dijkstra(vec adj, int k, vector<vector<int>> times){
        vector<int> d (adj.size(), INT_MAX); //n+1
        vector<int> p (adj.size()); //predecessor
        vector<bool> visited (adj.size(), false);
        d[k] = 0;
        for(int j=1;j<d.size();j++){
            //Loop through all the number of edges, account for 1 indexing
            
            //Extracting the min value of the node
            int extract_min = 0;
            for(int i=1;i<d.size();i++){
                int local_min = INT_MAX;
                if(!visited[i] && d[i]<local_min){
                    local_min = d[i];
                    extract_min = i;
                }
            }
            for(auto& edge:adj[extract_min]){
                //relax adjacent nodes
                if(d[extract_min] + edge.second < d[edge.first]){
                    d[edge.first] = d[extract_min] + d[edge.second];
                    p[edge.first] = extract_min;
                }
            }
            visited[extract_min] = true;
        }

    }
};


int main(){
    Solution sol;
}