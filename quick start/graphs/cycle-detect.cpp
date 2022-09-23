#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<int>> V;
    vector<int> rstack;
    
    void dfsjoin(unordered_map<int, vector<int>>& V, vector<vector<int>>& p, int i){
        V[p[i][0]].push_back(p[i][1]);
    }
    
    bool dfsvisit(unordered_map<int, vector<int>>& V, int s, unordered_map<int,int>& parent){
        for (int& v: V[s]){
            if(find(rstack.begin(),rstack.end(), v)==rstack.end()){
                rstack.push_back(v);
                parent[v] = s;
                bool cycle = dfsvisit(V, v, parent);
                if (!cycle) return false;
                rstack.pop_back();
            }
            else return false;
        }
        return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        for (int i=0;i<numCourses;i++){
            dfsjoin(V, p, i);
        }
        unordered_map<int, int> parent;
        for (auto& s:V){
            if (parent.find(s.first)==parent.end()){
                parent[s.first] = -1;
                rstack.push_back(s.first);
                bool cycle = dfsvisit(V, s.first, parent);
                if (!cycle) return false;
                rstack.pop_back();
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> a = {{1,0}};
    cout << sol.canFinish(2,a);
}