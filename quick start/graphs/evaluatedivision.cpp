#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> map;
        for(int i=0;i<equations.size();++i){
            map[equations[i][0]].push_back(pair<string,double>(equations[i][1],values[i]));
            map[equations[i][1]].push_back(pair<string,double>(equations[i][0],1/values[i]));
        }
        vector<double> ans (queries.size(),0.0);
        for(int i=0;i<queries.size();++i){
            if (map.find(queries[i][0])==map.end() || map.find(queries[i][1])==map.end()){
                ans[i] = -1;
                continue;
            }
            ans[i] = dfs(queries[i][0],queries[i][1],map);
        }
        return ans;
    }
    double dfs(string a, string b, unordered_map<string,vector<pair<string,double>>>& map){
        unordered_map<string, bool> vis; 
        vis[a] = true;
        if (a==b) return 1;
        return dfs(a,b,map,vis);
    }

    double dfs(string a, string b, unordered_map<string,vector<pair<string,double>>>& map,unordered_map<string, bool>& vis){
        for(auto& [key,value]:map[a]){
            if(vis.find(key)!=vis.end()) continue; //If already visited go next
            vis[key] = true;
            if (key==b) return value;
            double x = dfs(key,b,map,vis);
            if (x!=-1) return x*value;
        }
        return -1;
        
    }
};

int main(){
    Solution s;
    vector<vector<string>> equations = {{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
    vector<double> weights = {3.0,4.0,5.0,6.0};
    vector<vector<string>> queries = {{"x2","x4"}};
    cout << s.calcEquation(equations,weights,queries)[0];
}