#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    //Whoever thought of this ^ is a genius
    
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        if (dp[i][j]!=-1) return dp[i][j];
        int ii;
        int jj;
        int local_max = 0;
        for(int k=0;k<4;k++){
            ii = i + dx[k];
            jj = j + dy[k];
            if (ii>=0 && ii<matrix.size() && jj>=0 && jj<matrix[0].size()){
                if(matrix[ii][jj]>matrix[i][j])  local_max = max(dfs(matrix, ii, jj, dp),local_max);
            }
        }
        return dp[i][j] = local_max+1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int dist = 0;
        vector<vector<int>> dp (200, vector<int> (200, -1));
        for(int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                dist = max(dist, dfs(matrix, i, j, dp));
            }
        }
        return dist;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}};
    cout << s.longestIncreasingPath(matrix);
}

