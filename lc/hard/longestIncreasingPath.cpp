#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/
//This code bad because of extra adj matrix because I mapped 2d array to 1d. refer to FAST version for a more efficient soln
class Solution {
public:
    int dfs(vector<vector<int>>& adj, int node, vector<int> status, vector<vector<int>>& matrix){
        if (status[node]!=-1) return status[node];
        int max_child = 0;
        for (auto& sibling:adj[node]){
            if (compare(matrix, adj, node, sibling)){
                max_child = max(dfs(adj, sibling, status, matrix),max_child);
            }
        }
        status[node] = 1+max_child;
        return status[node];
    }
    
    bool compare(vector<vector<int>>& matrix, vector<vector<int>>& adj, int node, int sibling)
    {
        //returns true if sibling value is greater than node
        int x = int(matrix[0].size());
        int is = sibling/x;
        int js = sibling%x;
        int in = node/x;
        int jn = node%x;
        return matrix[is][js]>matrix[in][jn];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> adj (m*n);
        vector<int> status (m*n, -1);
        for (int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if (i != 0) adj[j+i*n].push_back(j+(i-1)*(n));
                if (i != m-1) adj[j+i*n].push_back(j+(i+1)*n);
                if (j != 0) adj[j+i*n].push_back(j-1+i*n);
                if (j != n-1) adj[j+i*n].push_back(j+1+i*n);
            }
        }
        //dfs time
        int ans = 1;
        for(int i=0;i<m*n;i++){
            ans = max(ans, dfs(adj, i, status, matrix));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,4},{2,3}};
    cout << s.longestIncreasingPath(matrix);
}