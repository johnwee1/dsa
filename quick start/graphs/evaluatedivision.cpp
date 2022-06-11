#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Set{
    private:
    unordered_map<string,string> root;
    unordered_map<string, int> rank;
    
    public:
    Set(vector<vector<string>> str){
        for(auto vec:str){
            for(string s:vec){
                root[s] = s;
                rank[s] = 1;
            }
        }
    }

    string find(string s){
        if(root[s] == s) return s;
        return root[s] = find(root[s]);
    }

    void join(string a, string b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(rank[a]>rank[b]) root[b] = a;
        else if(rank[b]>rank[a]) root[a] = b;
        else{
            root[a] = b;
            rank[b]+=1;
        }
    }
    
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Set set(equations);
        
        
    }
};