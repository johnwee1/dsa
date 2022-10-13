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
        return dijkstra(adj, k, times);
    }

    int dijkstra(vec adj, int k, vector<vector<int>> times){
        vector<int> d (adj.size(), INT_MAX); //n+1
        vector<int> p (adj.size()); //predecessor
        vector<bool> visited (adj.size(), false);
        d[k] = 0;
        for(int j=1;j<d.size();j++){
            //Loop through all the number of edges, account for 1 indexing

            //Extracting the min prio node
            int extract_min = -1; //cp alg sets it to -1, no diff here since 1-index doesnt hit 0
            int local_min = INT_MAX;
            for(int i=1;i<d.size();i++){
                if(!visited[i] && d[i]<local_min){
                    local_min = d[i];
                    extract_min = i;
                }
            }
            if(extract_min==-1) return -1;
            //unreachable clusters stay at INTMAX. return -1
            for(auto& edge:adj[extract_min]){
                //relax adjacent nodes
                if(d[extract_min] + edge.second < d[edge.first]){
                    d[edge.first] = d[extract_min] + edge.second;
                    p[edge.first] = extract_min;
                }
            }
            visited[extract_min] = true;
        }
        int ans = 0;
        for(int i=1;i<d.size();i++){
            ans = max(ans, d[i]); //maximum shortest dist
        }
        return ans;

    }
};
//this particular leetcode question did not require the path to be reconstructed, but I included the vector p anyway for purpose of learning.



int main(){
    Solution sol;
}