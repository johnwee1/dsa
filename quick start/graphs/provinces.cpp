#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz,1) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (x!=root[x]) return root[x] = find(root[x]);
        return x;
    }

    void us(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if  (root_x==root_y) return;
        if(rank[root_x]==rank[root_y]){
            //Change root y
            root[root_y] = root_x;
            rank[root_y] += 1;
        }
        else if (rank[root_x]>rank[root_y]){
            //change root y
            root[root_y] = root_x;
        }
        else root[root_x] = root_y;
        return;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int root_num(){
        vector<bool> temp(root.size(),false);
        int counter = 0;
        for(int i=0;i<root.size();i++){
            if(!temp[find(i)]){
                temp[find(i)] = true;
                ++counter;
            }
        }
        return counter;
    }
    //An even faster method is to initialize count as maxcount (n) and then minus off from count everytime union is performed
    //Also, easier to check no. of roots by running for{if (root[x] = x) ++counter}, no need for extra n space.

private:
    vector<int> root;
    vector<int> rank;
};

class Solution{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //Read the array
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (isConnected[i][j]) uf.us(i,j);
            }
        }
        return uf.root_num();
    }
};

int main(){
    Solution s;
}