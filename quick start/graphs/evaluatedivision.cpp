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
        vector<double> ans (0.0,queries.size());
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
        return dfs(a,b,map,vis);
    }

    double dfs(string a, string b, unordered_map<string,vector<pair<string,double>>>& map,unordered_map<string, bool>& vis){
        //this function won't even be called if the node is already visited
        if (a==b) return 1;
        for(auto& [key,value]:map[a]){
           if(vis.find(key)!=vis.end()) continue;
           vis[key] = true;
           if(key==b) return value;
           dfs(key,b,map,vis);
        }
        //Once the list is empty... PROBLEMATIC IN SOME WAY
        //return dfs() * value ???? how to get the value to change as it propagates back up?
        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<string>> equations = {{"A","B"},{"B","C"}};
    vector<double> weights = {2.0,3.0};
    vector<vector<string>> queries = {{"A","C"}};
    cout << s.calcEquation(equations,weights,queries)[0];
}