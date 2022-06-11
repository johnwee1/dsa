#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet{
    public:
    DisjointSet(int sz) : root(sz,0), rank(sz,1){
        for(int i=0;i<sz;i++){
            root[i]=i;
        }
    }

    int find(int x){
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    void join(int a,int b){
        a = find(a);
        b = find(b);
        if (a==b) return;
        if (rank[a]==rank[b]){
            root[b] = a;
            rank[a]+=1;
        }else if (rank[a]>rank[b]){
            root[b] = a;
        } else root[a] = b;
    }
    vector<int> root;
    vector<int> rank;
};


//A very convoluted solution that has very slow code, likely due to the disgusting amount of nesting I am doing
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet set(s.size());
        for(auto& pair:pairs) set.join(pair[0],pair[1]);
        unordered_map<int, vector<int>> grps;
        for(int i=0;i<s.size();i++){
            grps[set.find(i)].push_back(i); //Pushes the root indices. dont push the chars themselves yet
        }
        
        string ans (s.size(), ' ');
        for(auto& g:grps){
            vector<int> indices = g.second; //copies over the indices that belong to a particular group!! genius
            vector<char> chars;
            for(auto index:indices){
                chars.push_back(s[index]);
            }
            sort(chars.begin(),chars.end());
            int count = 0;
            for(auto index:indices){
                ans[index] = chars[count++];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> p {{0,3},{1,2}};
    string s = "dcab";
    cout << sol.smallestStringWithSwaps(s,p);
}