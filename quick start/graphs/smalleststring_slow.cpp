#include <iostream>
#include <vector>
#include <string>
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
//refer to the faster solution
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        DisjointSet set(s.size());
        for(auto& pair:pairs) set.join(pair[0],pair[1]);
        for(int i=0;i<s.size();i++){//for every "grp"... but how to dynamiucally end?
            vector<int> temp;
            for(int k=0;k<s.size();k++){ //Iter through every connected node
                if (set.find(k)==i) temp.push_back(s[k]); 
            }
            sort(temp.begin(),temp.end());
            int count = 0;
            for(int j=0;j<s.size();j++){
                if(set.find(j)==i){
                    s[j] = temp[count++];
                }
            }
        }
        return s;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> p {{0,3},{1,2}};
    string s = "dcab";
    cout << sol.smallestStringWithSwaps(s,p);
}